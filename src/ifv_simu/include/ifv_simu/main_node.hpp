#include <functional>
#include <memory>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include "rclcpp/rclcpp.hpp" 
#include "rclcpp/node.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "ifv_interfaces/msg/torque12dof.hpp"
#include "pdcontroller.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

class MainNode : public rclcpp::Node
{
   public:
      MainNode();
      ~MainNode();
      void init();
      // void stop();
   private:
      void jointstate_callback(const sensor_msgs::msg::JointState & msg);
      void imu_callback(const sensor_msgs::msg::Imu & msg);
      void timer_callback();

   private:
      rclcpp::TimerBase::SharedPtr timer_;
      rclcpp::Publisher<ifv_interfaces::msg::Torque12dof>::SharedPtr publisher_;
      rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription1_;
      rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription2_;
      std::shared_ptr<PDController> controller_ptr;
      std::vector<double> pdgain;
      std::vector<double> joint_position;
      std::vector<double> joint_velocity;
      geometry_msgs::msg::Quaternion imu_orientation;
      geometry_msgs::msg::Vector3 imu_angular_velocity;
      geometry_msgs::msg::Vector3 imu_linear_acceleration;
      std::vector<double> applied_torque;
      int start_pub = 0;
};