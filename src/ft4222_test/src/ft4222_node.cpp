#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "libft4222.h"
#include "ftd2xx.h"
#include "ifv_interfaces/srv/spione.hpp"


using namespace std::chrono_literals;

#define BYTES_EXPECTED 10 // Length of Master's message.

FT_HANDLE global_ftHandle;
static uint8 rxBuffer[BYTES_EXPECTED+2]={0x63,0x24,0x12,0x34,0x56,0x78,0x64,0x23,0x61,0x69};
static uint8 txBuffer[BYTES_EXPECTED-1]={0x05,0xED,0xDC,0xCB,0xBA,0xA9,0x98,0x87,0x00};

FT_HANDLE out_fthandle;
/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */
static FT_HANDLE init_FT4222(DWORD locationId)
{
      // int                  success = 0;
      FT_STATUS            ftStatus;
      FT_HANDLE            ftHandle = (FT_HANDLE)NULL;
      FT4222_STATUS        ft4222Status;
      FT4222_Version       ft4222Version;


      ftStatus = FT_OpenEx((PVOID)(uintptr_t)locationId, 
                         FT_OPEN_BY_LOCATION, 
                         &ftHandle);
      if (ftStatus != FT_OK)
      {
        printf("FT_OpenEx failed (error %d)\n", 
               (int)ftStatus);
        goto exit;
      }
    
      ft4222Status = FT4222_GetVersion(ftHandle,
                                     &ft4222Version);
      if (FT4222_OK != ft4222Status)
      {
        printf("FT4222_GetVersion failed (error %d)\n",
               (int)ft4222Status);
        goto exit;
      }
    
      printf("Chip version: %08X, LibFT4222 version: %08X\n",
           (unsigned int)ft4222Version.chipVersion,
           (unsigned int)ft4222Version.dllVersion);

      // Configure the FT4222 as SPI Slave.
      ft4222Status = FT4222_SPISlave_InitEx(ftHandle,SPI_SLAVE_NO_PROTOCOL);
      if (FT4222_OK != ft4222Status)
      {
        printf("FT4222_SPISlave_Init failed (error %d)\n",
               (int)ft4222Status);
        goto exit;
      }
      ft4222Status =FT4222_SPISlave_SetMode(
          ftHandle,
          CLK_IDLE_HIGH,     // clock idles at logic 0
          CLK_LEADING);      // data captured on rising edge)
      if (FT4222_OK != ft4222Status)
      {
        printf("FT4222_SPISlave_SetMode failed (error %d)\n",
               (int)ft4222Status);
        goto exit;
      }
      ft4222Status = FT4222_SPI_SetDrivingStrength(ftHandle,
                                                 DS_8MA,
                                                 DS_8MA,
                                                 DS_8MA);
      if (FT4222_OK != ft4222Status)
      {  
        printf("FT4222_SPI_SetDrivingStrength failed (error %d)\n",
            (int)ft4222Status);
        goto exit;
      }

      //configure GPIO for suspend
      // GPIO_Dir gpioDir[4];
      // gpioDir[0] = GPIO_OUTPUT;
      // gpioDir[1] = GPIO_OUTPUT;
      // gpioDir[2] = GPIO_OUTPUT;
      // gpioDir[3] = GPIO_INPUT;
      // ft4222Status =FT4222_GPIO_Init(ftHandle,&gpioDir[4]);
      
      // if (FT4222_OK != ft4222Status)
      // {  
      //   printf("FT4222_SPI_GPIO_Init failed (error %d)\n",
      //       (int)ft4222Status);
      //   goto exit;
      // }


      goto noexit;
      noexit:
        return ftHandle;
    
      exit:
        if (ftHandle != (FT_HANDLE)NULL)
        {
          (void)FT4222_UnInitialize(ftHandle);
          (void)FT_Close(ftHandle);
        }

      return ftHandle;
};
static void prepare_ft4222()
    {
      FT_STATUS                 ftStatus;
      FT_DEVICE_LIST_INFO_NODE *devInfo = NULL;
      DWORD                     numDevs = 0;
      int                       i;
      int                       retCode = 0;
      int                       found = 0;

      ftStatus = FT_CreateDeviceInfoList(&numDevs);
      if (ftStatus != FT_OK) 
      {
        printf("FT_CreateDeviceInfoList failed (error code %d)\n", 
               (int)ftStatus);
        retCode = -10;
        goto exit;
      }
      if (numDevs == 0)
      {
        printf("No devices connected.\n");
        retCode = -20;
        goto exit;
      }
      devInfo = static_cast<FT_DEVICE_LIST_INFO_NODE*>(std::calloc((size_t)numDevs, sizeof(FT_DEVICE_LIST_INFO_NODE)));
      if (devInfo == NULL)
      {
        printf("Allocation failure.\n");
        retCode = -30;
        goto exit;
      }
      ftStatus = FT_GetDeviceInfoList(devInfo, &numDevs);
      if (ftStatus != FT_OK)
      {
        printf("FT_GetDeviceInfoList failed (error code %d)\n",
               (int)ftStatus);
        retCode = -40;
        goto exit;
      }
      for (i = 0; i < (int)numDevs; i++) 
      {
        if (devInfo[i].Type == FT_DEVICE_4222H_0)
        {
            printf("\nDevice %d is FT4222H in mode 0 (single Master or Slave):\n",i);
            printf("  0x%08x  %s  %s\n", 
                   (unsigned int)devInfo[i].ID,
                   devInfo[i].SerialNumber,
                   devInfo[i].Description);
            out_fthandle = init_FT4222(devInfo[i].LocId);
            global_ftHandle = out_fthandle;
            found = 1;
            break;
        }
        
        if (devInfo[i].Type == FT_DEVICE_4222H_3)
          {
            printf("\nDevice %d is FT4222H in mode 3\n", i);
          }

        if (devInfo[i].Type == FT_DEVICE_4222H_1_2)
          {
            printf("\nDevice %d is FT4222H in mode 1 or 2\n", i);
          }
      }
        if (!found)printf("No mode-3 FT4222H device found.\n");
    
      goto noexit;
      noexit:
      return;
      exit:
      free(devInfo);
      printf("Returning %d\n", retCode);
      return;
    };


class FT4222_node : public rclcpp::Node
{
  public:
    //static std::vector<uint8> read_data;
    //uint8 *read_ptr = &read_data[0];
    FT4222_node(): Node("FT4222_node"),count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      timer_ = this->create_wall_timer(
      1ms, std::bind(&FT4222_node::timer_callback, this));
    }
  private:
    void timer_callback()
    {
      std::vector<uint8> msg;
      // if (count_ == 0)prepare_ft4222();
      count_++;
      read_FT4222();
      auto message = std_msgs::msg::String();
      //message.data = "datapoint 1 is " + std::to_string(rxBuffer[0]) + " datapoint 2 is " + std::to_string(rxBuffer[1]);
      message.data = std::to_string(rxBuffer[0])+' '+std::to_string(rxBuffer[1])+' '+std::to_string(rxBuffer[2])+' '+std::to_string(rxBuffer[3])+' '+\
std::to_string(rxBuffer[4])+' '+std::to_string(rxBuffer[5])+' '+std::to_string(rxBuffer[6])+' '+std::to_string(rxBuffer[7])+' '+std::to_string(rxBuffer[8])+' '+std::to_string(rxBuffer[9]);
  
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
    void read_FT4222()//std::vector<uint8> read_data,uint8 *read_ptr)
    {
      FT4222_STATUS        ft4222Status;
      FT_HANDLE            ftHandle = out_fthandle;
      int                  tries;
      const int            retryLimit = 321123879;
      uint16               bytesReceived = 0;
      FT4222_SPI_ResetTransaction(ftHandle,0);
      for (tries = 0; tries < retryLimit; tries++)
      {
        uint16 bytesAvailable = 0;
        uint16 bytesRead = 0;
        uint16 bytesWritten = 0;
        
        if (tries == 0)
        {
          ft4222Status = FT4222_SPISlave_Write(ftHandle, 
                                       txBuffer, 
                                       BYTES_EXPECTED,
                                       &bytesWritten);
          if (FT4222_OK != ft4222Status)
          {
            printf("FT4222_SPISlave_Write failed (error %d)\n",
            (int)ft4222Status);
            goto exit;
          }
        }
        ft4222Status = FT4222_SPISlave_GetRxStatus(ftHandle, 
                                                   &bytesAvailable);
        if (FT4222_OK != ft4222Status)
        {
          printf("FT4222_SPISlave_GetRxStatus failed (error %d)\n",
                 (int)ft4222Status);
          goto exit;
        }
        
        if (bytesAvailable == 0)
        continue;
        

        ft4222Status = FT4222_SPISlave_Read(ftHandle, 
                                            rxBuffer, 
                                            bytesAvailable, 
                                            &bytesRead);
        if (FT4222_OK != ft4222Status)
        {
          printf("FT4222_SPISlave_Read failed (error %d)\n",
                 (int)ft4222Status);
          goto exit;
        }

          bytesReceived += bytesRead;
        
        if (bytesReceived >= BYTES_EXPECTED)
        {
          // ft4222Status = FT4222_SPISlave_Write(ftHandle, 
          //                                txBuffer, 
          //                                BYTES_EXPECTED,
          //                                &bytesWritten);
          // if (FT4222_OK != ft4222Status)
          // {
          //   printf("FT4222_SPISlave_Write failed (error %d)\n",
          //   (int)ft4222Status);
          //   goto exit;
          // }
          break;
        }
        if(tries==retryLimit-1)
        {
          goto exit;
        }
        
        
      }
      goto noexit;
      noexit:return;
      exit:
      
      if (ftHandle != (FT_HANDLE)NULL)
      {
        (void)FT4222_UnInitialize(ftHandle);
        (void)FT_Close(ftHandle);
      }
      rclcpp::shutdown();
      return;
    }
};

void pass_data(const std::shared_ptr<ifv_interfaces::srv::Spione::Request> request,
          std::shared_ptr<ifv_interfaces::srv::Spione::Response>      response)
{
  response->output = request->input;
  txBuffer[0] = response->output;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request hertz\na: %d",
                request->input);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "send the response hertz: [%d]", (uint8)response->output);
}

int main(int argc, char * argv[])
{
  prepare_ft4222();
  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> node = std::make_shared<FT4222_node>();
  rclcpp::Service<ifv_interfaces::srv::Spione>::SharedPtr service =
    node->create_service<ifv_interfaces::srv::Spione>("passing", &pass_data);

  rclcpp::spin(node);
  rclcpp::shutdown();
  (void)FT4222_UnInitialize(out_fthandle);
  (void)FT_Close(out_fthandle);
  return 0;
}
