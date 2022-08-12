// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice

#ifndef IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__BUILDER_HPP_
#define IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ifv_interfaces/msg/detail/torque8dof__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ifv_interfaces
{

namespace msg
{

namespace builder
{

class Init_Torque8dof_rh2
{
public:
  explicit Init_Torque8dof_rh2(::ifv_interfaces::msg::Torque8dof & msg)
  : msg_(msg)
  {}
  ::ifv_interfaces::msg::Torque8dof rh2(::ifv_interfaces::msg::Torque8dof::_rh2_type arg)
  {
    msg_.rh2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ifv_interfaces::msg::Torque8dof msg_;
};

class Init_Torque8dof_rh1
{
public:
  explicit Init_Torque8dof_rh1(::ifv_interfaces::msg::Torque8dof & msg)
  : msg_(msg)
  {}
  Init_Torque8dof_rh2 rh1(::ifv_interfaces::msg::Torque8dof::_rh1_type arg)
  {
    msg_.rh1 = std::move(arg);
    return Init_Torque8dof_rh2(msg_);
  }

private:
  ::ifv_interfaces::msg::Torque8dof msg_;
};

class Init_Torque8dof_lh2
{
public:
  explicit Init_Torque8dof_lh2(::ifv_interfaces::msg::Torque8dof & msg)
  : msg_(msg)
  {}
  Init_Torque8dof_rh1 lh2(::ifv_interfaces::msg::Torque8dof::_lh2_type arg)
  {
    msg_.lh2 = std::move(arg);
    return Init_Torque8dof_rh1(msg_);
  }

private:
  ::ifv_interfaces::msg::Torque8dof msg_;
};

class Init_Torque8dof_lh1
{
public:
  explicit Init_Torque8dof_lh1(::ifv_interfaces::msg::Torque8dof & msg)
  : msg_(msg)
  {}
  Init_Torque8dof_lh2 lh1(::ifv_interfaces::msg::Torque8dof::_lh1_type arg)
  {
    msg_.lh1 = std::move(arg);
    return Init_Torque8dof_lh2(msg_);
  }

private:
  ::ifv_interfaces::msg::Torque8dof msg_;
};

class Init_Torque8dof_rf2
{
public:
  explicit Init_Torque8dof_rf2(::ifv_interfaces::msg::Torque8dof & msg)
  : msg_(msg)
  {}
  Init_Torque8dof_lh1 rf2(::ifv_interfaces::msg::Torque8dof::_rf2_type arg)
  {
    msg_.rf2 = std::move(arg);
    return Init_Torque8dof_lh1(msg_);
  }

private:
  ::ifv_interfaces::msg::Torque8dof msg_;
};

class Init_Torque8dof_rf1
{
public:
  explicit Init_Torque8dof_rf1(::ifv_interfaces::msg::Torque8dof & msg)
  : msg_(msg)
  {}
  Init_Torque8dof_rf2 rf1(::ifv_interfaces::msg::Torque8dof::_rf1_type arg)
  {
    msg_.rf1 = std::move(arg);
    return Init_Torque8dof_rf2(msg_);
  }

private:
  ::ifv_interfaces::msg::Torque8dof msg_;
};

class Init_Torque8dof_lf2
{
public:
  explicit Init_Torque8dof_lf2(::ifv_interfaces::msg::Torque8dof & msg)
  : msg_(msg)
  {}
  Init_Torque8dof_rf1 lf2(::ifv_interfaces::msg::Torque8dof::_lf2_type arg)
  {
    msg_.lf2 = std::move(arg);
    return Init_Torque8dof_rf1(msg_);
  }

private:
  ::ifv_interfaces::msg::Torque8dof msg_;
};

class Init_Torque8dof_lf1
{
public:
  Init_Torque8dof_lf1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Torque8dof_lf2 lf1(::ifv_interfaces::msg::Torque8dof::_lf1_type arg)
  {
    msg_.lf1 = std::move(arg);
    return Init_Torque8dof_lf2(msg_);
  }

private:
  ::ifv_interfaces::msg::Torque8dof msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ifv_interfaces::msg::Torque8dof>()
{
  return ifv_interfaces::msg::builder::Init_Torque8dof_lf1();
}

}  // namespace ifv_interfaces

#endif  // IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__BUILDER_HPP_
