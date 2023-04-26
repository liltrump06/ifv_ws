
#include <gazebo/common/Events.hh>
#include <gazebo/physics/Link.hh>
#include <gazebo/physics/Model.hh>
#include <ifv_pkg/gazebo_ros_12doftorque.hpp>
#include <gazebo_ros/conversions/geometry_msgs.hpp>
#include <gazebo_ros/node.hpp>
#include "ifv_interfaces/msg/torque12dof.hpp"
#ifdef IGN_PROFILER_ENABLE
#include <ignition/common/Profiler.hh>
#endif
#include <rclcpp/rclcpp.hpp>

#include <memory>
#include <string>
#include <vector>
namespace gazebo_plugins
{
class GazeboRos12DofTorquePrivate
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

GazeboRos12DofTorque::GazeboRos12DofTorque()
: impl_(std::make_unique<GazeboRos12DofTorquePrivate>())
{
}

GazeboRos12DofTorque::~GazeboRos12DofTorque()
{
}

void GazeboRos12DofTorque::Load(gazebo::physics::ModelPtr model_, sdf::ElementPtr sdf_)
{
  // Subscribe to wrench messages
  impl_->ros_node_ = gazebo_ros::Node::Get(sdf_);
  // Get QoS profiles
  const gazebo_ros::QoS & qos = impl_->ros_node_->get_qos();
  impl_->torque_sub_ = impl_->ros_node_->create_subscription<ifv_interfaces::msg::Torque12dof>(
    "gazebo_ros_12doftorque", qos.get_subscription_qos("gazebo_ros_12doftorque", rclcpp::SystemDefaultsQoS()),
    std::bind(&GazeboRos12DofTorque::OnRosWrenchMsg, this, std::placeholders::_1));
  // Callback on every iteration
  this->model= model_;
  impl_->update_connection_ = gazebo::event::Events::ConnectWorldUpdateBegin(
    std::bind(&GazeboRos12DofTorque::OnUpdate, this));
}

void GazeboRos12DofTorque::OnRosWrenchMsg(const ifv_interfaces::msg::Torque12dof &msg)
{
  std::vector<float> mid_vec;
  mid_vec.push_back(msg.rh3);
  mid_vec.push_back(msg.rh2);
  mid_vec.push_back(msg.rh1);
  mid_vec.push_back(msg.lh3);
  mid_vec.push_back(msg.lh2);
  mid_vec.push_back(msg.lh1);
  mid_vec.push_back(msg.rf3);
  mid_vec.push_back(msg.rf2);
  mid_vec.push_back(msg.rf1);
  mid_vec.push_back(msg.lf3);
  mid_vec.push_back(msg.lf2);
  mid_vec.push_back(msg.lf1);
  impl_->torque_vec_ = mid_vec;
  impl_->pre_torque = true;
  //RCLCPP_INFO(impl_->ros_node_->get_logger(),"get rh2 '%f' ",msg.rh2);
}

void GazeboRos12DofTorque::OnUpdate()
{
  if(!(impl_->torque_vec_.empty())&&(impl_->pre_torque)){
    this->model->GetJoint("LF_body2hip")->SetForce(0,impl_->torque_vec_[0]);
    this->model->GetJoint("LF_hip2thigh")->SetForce(0,impl_->torque_vec_[1]);
    this->model->GetJoint("LF_thigh2calf")->SetForce(0,impl_->torque_vec_[2]);
    this->model->GetJoint("RF_body2hip")->SetForce(0,impl_->torque_vec_[3]);
    this->model->GetJoint("RF_hip2thigh")->SetForce(0,impl_->torque_vec_[4]);
    this->model->GetJoint("RF_thigh2calf")->SetForce(0,impl_->torque_vec_[5]);
    this->model->GetJoint("LH_body2hip")->SetForce(0,impl_->torque_vec_[6]);
    this->model->GetJoint("LH_hip2thigh")->SetForce(0,impl_->torque_vec_[7]);
    this->model->GetJoint("LH_thigh2calf")->SetForce(0,impl_->torque_vec_[8]);
    this->model->GetJoint("RH_body2hip")->SetForce(0,impl_->torque_vec_[9]);
    this->model->GetJoint("RH_hip2thigh")->SetForce(0,impl_->torque_vec_[10]);
    this->model->GetJoint("RH_thigh2calf")->SetForce(0,impl_->torque_vec_[11]);
    impl_->pre_torque = false;
    // std::stringstream ss;
    // for (auto it = impl_->torque_vec_.begin();it != impl_->torque_vec_.end();it++)
    // {
    //   if (it != impl_->torque_vec_.begin()) {
    //         ss << " ";
    //     }
    //     ss << *it;
    // };
    // std::string lp = ss.str();
    // char *ssp = lp.data();
    // RCLCPP_INFO(impl_->ros_node_->get_logger(),ssp);
    
    // RCLCPP_INFO(impl_->ros_node_->get_logger(),"get rh2 '%f' ",impl_->torque_vec_[0]);
  }
}
GZ_REGISTER_MODEL_PLUGIN(GazeboRos12DofTorque)
}  // namespace gazebo_plugins
