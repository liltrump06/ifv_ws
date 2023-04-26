#include <functional>
#include <memory>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include "rclcpp/rclcpp.hpp" 
#include "sensor_msgs/msg/joint_state.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "ifv_interfaces/msg/torque12dof.hpp"



using std::placeholders::_1;
using namespace std::chrono_literals;

class sub_joint : public rclcpp::Node
{
public:
  sub_joint(): Node("sub_joint")
  {
    //First subscribe all the information from joints.
    subscription1_ = this->create_subscription<sensor_msgs::msg::JointState>(
      "IFV/my_joint_states", 100, std::bind(&sub_joint::topic_callback1, this, _1));
    subscription2_ = this->create_subscription<sensor_msgs::msg::Imu>(
      "imu_topic/data", 100, std::bind(&sub_joint::topic_callback2, this, _1));
    // Then publish the control torque to the plugin contained node.
    publisher_ = this->create_publisher<ifv_interfaces::msg::Torque12dof>("gazebo_ros_12doftorque", rclcpp::SystemDefaultsQoS());
    timer_ = this->create_wall_timer(0.1ms, std::bind(&sub_joint::timer_callback, this));
    

  }
  std::vector<double> applied_torque;
  int start_pub = 0; 

public:
  void topic_callback1(const sensor_msgs::msg::JointState & msg)
  {
    this->joint_position = msg.position;
    this->joint_velocity = msg.velocity;
    /*std::stringstream ss;
    for (auto it = joint_position.begin();it != joint_position.end();it++)
    {
      if (it != joint_position.begin()) {
            ss << " ";
        }
        ss << *it;
    };
    std::string lp = ss.str();
    char *ssp = lp.data();
    RCLCPP_INFO(this->get_logger(),ssp);
   */
    set_control();
    
  }
  
  void topic_callback2(const sensor_msgs::msg::Imu & msg)
  {
    imu_orientation = msg.orientation;
    imu_angular_velocity = msg.angular_velocity;
    imu_linear_acceleration = msg.linear_acceleration;
    RCLCPP_INFO(this->get_logger(),std::to_string(imu_linear_acceleration.x).c_str());
  }

  void set_control()
  {
    float Kd = 0.001;
    float Kp = 0.1;
    double position_ref[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    std::vector<double> torque_this_time;
    for(unsigned int it = 0;it < joint_position.size();it++)
    {
      unsigned int m = joint_position.size();
      if (it == 0 || it == 3 || it == 6 || it == 9)
      {
        torque_this_time.push_back(Kp * 18 * (position_ref[m-it-1]-joint_position[m-it-1]) + Kd * (0-joint_velocity[m-it-1]));
      }
      else if (it == 1 || it == 4 || it == 7 || it == 10)
      {
        torque_this_time.push_back(Kp * 3 * (position_ref[m-it-1]-joint_position[m-it-1]) + Kd * (0-joint_velocity[m-it-1]));
      }
      else{
        torque_this_time.push_back(Kp * (position_ref[m-it-1]-joint_position[m-it-1]) + Kd * (0-joint_velocity[m-it-1]));
      }
    }
    this->applied_torque = torque_this_time;
    if(!torque_this_time.empty())
    {
      this->start_pub = 1;
    }
  }

  void timer_callback()
  {
    if (this->start_pub == 1){
      auto message = ifv_interfaces::msg::Torque12dof();
      message.lf1 = this->applied_torque[0];
      message.lf2 = this->applied_torque[1];
      message.lf3 = this->applied_torque[2];
      message.rf1 = this->applied_torque[3];
      message.rf2 = this->applied_torque[4];
      message.rf3 = this->applied_torque[5];
      message.lh1 = this->applied_torque[6];
      message.lh2 = this->applied_torque[7];
      message.lh3 = this->applied_torque[8];
      message.rh1 = this->applied_torque[9];
      message.rh2 = this->applied_torque[10];
      message.rh3 = this->applied_torque[11];
      //RCLCPP_INFO(this->get_logger(),"publishing '%f'" ,message.lf1);
      publisher_->publish(message);
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<ifv_interfaces::msg::Torque12dof>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription1_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription2_;
  std::vector<double> joint_position;
  std::vector<double> joint_velocity;
  geometry_msgs::msg::Quaternion imu_orientation;
  geometry_msgs::msg::Vector3 imu_angular_velocity;
  geometry_msgs::msg::Vector3 imu_linear_acceleration;
};
    
    /*
    std::sstream ss;
    for (auto it = instmsg.begin();it != instmsg.end();it++)
    {
      if (it != instmsg.begin()) {
            ss << " ";
        }
        ss << *it;
    };
    std::string lp = ss.str();
    char *ssp = lp.data();
    RCLCPP_INFO(this->get_logger(),ssp);
    */
  
  

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<sub_joint>());
  rclcpp::shutdown();
  return 0;
}
