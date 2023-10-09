#ifndef GAZEBO_PLUGINS__GAZEBO_ROS_12DOFTORQUE_HPP_
#define GAZEBO_PLUGINS__GAZEBO_ROS_12DOFTORQUE_HPP_

#include <gazebo/common/Plugin.hh>
#include "ifv_interfaces/msg/torque12dof.hpp"
#include <gazebo/physics/Model.hh>
#include <gazebo_ros_joint_torque_private.hpp>
#include <memory>

namespace gazebo_plugins
{
class GazeboRosJointTorque;

/// This plugin collects data from a ROS topic and applies wrench to a link accordingly.
/**
  \details The last received force will be continuously added to the link at every simulation iteration.
  Send an empty / zero message to stop applying a force.

  Example Usage:
  \code{.xml}
    <plugin name="gazebo_ros_force" filename="libgazebo_ros_force.so">

      <ros>

        <!-- Add a namespace -->
        <namespace>/test</namespace>

        <!-- Remap the default topic -->
        <remapping>gazebo_ros_force:=force_test</remapping>

      </ros>

      <!-- Name of link within model which will receive the force -->
      <link_name>link</link_name>

      <!-- Frame where the force/torque will be applied (options: world; link)-->
      <force_frame>link</force_frame>

    </plugin>
  \endcode
*/

class GazeboRosJointTorque : public gazebo::ModelPlugin
{
public:
  /// Constructor
  GazeboRosJointTorque();

  /// Destructor
  virtual ~GazeboRosJointTorque();
public: gazebo::physics::ModelPtr model;
protected:
  // Documentation inherited
  void Load(gazebo::physics::ModelPtr model, sdf::ElementPtr sdf) override;

  /// Optional callback to be called at every simulation iteration.
  virtual void OnUpdate();

private:
  /// Callback when a ROS Wrench message is received
  /// \param[in] msg The Incoming ROS message representing the new force to
  /// exert.
  void OnRosWrenchMsg(const ifv_interfaces::msg::Torque12dof &msg);

  /// Private data pointer
  std::unique_ptr<GazeboRosJointTorquePrivate> impl_;
};
}  // namespace gazebo_plugins

#endif  // GAZEBO_PLUGINS__GAZEBO_ROS_FORCE_HPP_