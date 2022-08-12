#include <functional>
#include <memory>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include "rclcpp/rclcpp.hpp" 
#include "sensor_msgs/msg/joint_state.hpp"
#include "ifv_interfaces/msg/torque8dof.hpp"



using std::placeholders::_1;
using namespace std::chrono_literals;

class sub_joint : public rclcpp::Node
{
public:
  sub_joint(): Node("sub_joint")
  {
    //First subscribe all the information from joints.
    subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
      "IFV/my_joint_states", 20, std::bind(&sub_joint::topic_callback, this, _1));
    // Then publish the control torque to the plugin contained node.
    publisher_ = this->create_publisher<ifv_interfaces::msg::Torque8dof>("gazebo_ros_8doftorque", rclcpp::SystemDefaultsQoS());
    timer_ = this->create_wall_timer(5ms, std::bind(&sub_joint::timer_callback, this));
    

  }
  std::vector<double> applied_torque;
  int start_pub = 0; 

public:
  void topic_callback(const sensor_msgs::msg::JointState & msg)
  {
    std::vector<double> joint_position = msg.position;
    std::vector<double> joint_velocity = msg.velocity;
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
    float Kd = 0.02;
    float Kp = 1.5;
    std::vector<double> torque_this_time;
    for(unsigned int it = 0;it < joint_position.size();it++)
    {
      unsigned int m = joint_position.size();
      torque_this_time.push_back(Kp * (0-joint_position[m-it-1]) + Kd * (0-joint_velocity[m-it-1]));
    }
    this->applied_torque = torque_this_time;


    /*std::stringstream ss;
    for (auto lk = this->applied_torque.begin();lk != this->applied_torque.end();lk++)
    {
      if (lk != this->applied_torque.begin()) {
            ss << " ";
        }
        ss << *lk;
    };
    std::string lp = ss.str();
    char *ssp = lp.data();
    RCLCPP_INFO(this->get_logger(),ssp);
    */
    if(!torque_this_time.empty())
    {
      this->start_pub = 1;
    }
  }
  
  void timer_callback()
  {
    if (this->start_pub == 1){
      auto message = ifv_interfaces::msg::Torque8dof();
      message.lf1 = this->applied_torque[0];
      message.lf2 = this->applied_torque[1];
      message.rf1 = this->applied_torque[2];
      message.rf2 = this->applied_torque[3];
      message.lh1 = this->applied_torque[4];
      message.lh2 = this->applied_torque[5];
      message.rh1 = this->applied_torque[6];
      message.rh2 = this->applied_torque[7];
      //RCLCPP_INFO(this->get_logger(),"publishing '%f'" ,message.lf1);
      publisher_->publish(message);
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<ifv_interfaces::msg::Torque8dof>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
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
