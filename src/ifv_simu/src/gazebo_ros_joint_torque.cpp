
// #include <gazebo/common/Events.hh>
// #include <gazebo/physics/Link.hh>
// #include <gazebo/physics/Model.hh>
#include <ifv_simu/gazebo_ros_joint_torque.hpp>
// #include <ifv_simu/gazebo_ros_joint_torque_private.hpp>
// #include <gazebo_ros/conversions/geometry_msgs.hpp>
// #include <gazebo_ros/node.hpp>
// #include "ifv_interfaces/msg/torque12dof.hpp"
#ifdef IGN_PROFILER_ENABLE
#include <ignition/common/Profiler.hh>
#endif
// #include <rclcpp/rclcpp.hpp>

// #include <memory>
// #include <string>
// #include <vector>
namespace gazebo_plugins
{

GazeboRosJointTorque::GazeboRosJointTorque()
: impl_(std::make_unique<GazeboRosJointTorquePrivate>())
{
}

GazeboRosJointTorque::~GazeboRosJointTorque()
{
}

void GazeboRosJointTorque::Load(gazebo::physics::ModelPtr model_, sdf::ElementPtr sdf_)
{
  // Subscribe to wrench messages
  impl_->ros_node_ = gazebo_ros::Node::Get(sdf_);
  // Get QoS profiles
  const gazebo_ros::QoS & qos = impl_->ros_node_->get_qos();
  impl_->torque_sub_ = impl_->ros_node_->create_subscription<ifv_interfaces::msg::Torque12dof>(
    "IFV/applied_torque", qos.get_subscription_qos("gazebo_ros_12doftorque", rclcpp::SystemDefaultsQoS()),
    std::bind(&GazeboRosJointTorque::OnRosWrenchMsg, this, std::placeholders::_1));
  // Callback on every iteration
  this->model = model_;
  impl_->update_connection_ = gazebo::event::Events::ConnectWorldUpdateBegin(
  std::bind(&GazeboRosJointTorque::OnUpdate, this));
}

void GazeboRosJointTorque::OnRosWrenchMsg(const ifv_interfaces::msg::Torque12dof &msg)
{
  std::vector<float> mid_vec(12,0);
  mid_vec[0] = msg.lf1;
  mid_vec[1] = msg.lf2;
  mid_vec[2] = msg.lf3;
  mid_vec[3] = msg.rf1;
  mid_vec[4] = msg.rf2;
  mid_vec[5] = msg.rf3;
  mid_vec[6] = msg.lh1;
  mid_vec[7] = msg.lh2;
  mid_vec[8] = msg.lh3;
  mid_vec[9] = msg.rh1;
  mid_vec[10] = msg.rh2;
  mid_vec[11] = msg.rh3;

  impl_->torque_vec_ = mid_vec;
  impl_->pre_torque = true;
  RCLCPP_INFO(impl_->ros_node_->get_logger(),"get rh2 '%f' ",impl_->torque_vec_[10]);
}

void GazeboRosJointTorque::OnUpdate()
{
  // RCLCPP_INFO(impl_->ros_node_->get_logger(),"debug0");
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
  }
}
GZ_REGISTER_MODEL_PLUGIN(GazeboRosJointTorque)
}  // namespace gazebo_plugins
