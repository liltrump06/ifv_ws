#include <vector>
#include "sensor_msgs/msg/joint_state.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "rclcpp/rclcpp.hpp"

class PDController
{
   public:
      PDController(std::vector<double> pdgain);
      ~PDController();
      void init();
      void stop();
   public:
      void get_pdgain(std::vector<double> out_pdgain);
      void get_jointstate(sensor_msgs::msg::JointState msg);
      void get_imu(sensor_msgs::msg::Imu msg);
      void compute_torque();
      void get_reference();
      std::vector<double> applied_torque;
   private:
      std::vector<double> pdgain{std::vector<double>(6,1)};
      std::vector<double> joint_position;
      std::vector<double> joint_velocity;
      std::vector<double> position_ref;
      
      rclcpp::Logger logger = rclcpp::get_logger("controller_logger");
      geometry_msgs::msg::Quaternion imu_orientation;
      geometry_msgs::msg::Vector3 imu_angular_velocity;
      geometry_msgs::msg::Vector3 imu_linear_acceleration;
};