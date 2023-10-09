#include <gazebo/physics/Link.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo_ros/conversions/geometry_msgs.hpp>
#include <gazebo_ros/node.hpp>
#include "ifv_interfaces/msg/torque12dof.hpp"

// #include <gazebo_ros_joint_torque.hpp>
#include <memory>
#include <string>
#include <vector>

namespace gazebo_plugins
{
  class GazeboRosJointTorquePrivate
  {
  public:
    /// A pointer to the Link, where force is applied
    gazebo::physics::JointPtr joint_;

    /// A pointer to the GazeboROS node.
    gazebo_ros::Node::SharedPtr ros_node_;

    /// Wrench subscriber
    rclcpp::Subscription<ifv_interfaces::msg::Torque12dof>::SharedPtr torque_sub_;

    /// Container for the wrench force that this plugin exerts on the body.
    std::vector<float> torque_vec_;

    // Pointer to the update event connection
    gazebo::event::ConnectionPtr update_connection_;

    /// Indicates that the force should be applied on the world frame instead of the link frame
    bool force_on_world_frame_;

    bool pre_torque = false;
  };
}