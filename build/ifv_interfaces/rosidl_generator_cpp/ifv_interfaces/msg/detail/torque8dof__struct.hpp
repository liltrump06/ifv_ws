// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice

#ifndef IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__STRUCT_HPP_
#define IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ifv_interfaces__msg__Torque8dof __attribute__((deprecated))
#else
# define DEPRECATED__ifv_interfaces__msg__Torque8dof __declspec(deprecated)
#endif

namespace ifv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Torque8dof_
{
  using Type = Torque8dof_<ContainerAllocator>;

  explicit Torque8dof_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lf1 = 0.0f;
      this->lf2 = 0.0f;
      this->rf1 = 0.0f;
      this->rf2 = 0.0f;
      this->lh1 = 0.0f;
      this->lh2 = 0.0f;
      this->rh1 = 0.0f;
      this->rh2 = 0.0f;
    }
  }

  explicit Torque8dof_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lf1 = 0.0f;
      this->lf2 = 0.0f;
      this->rf1 = 0.0f;
      this->rf2 = 0.0f;
      this->lh1 = 0.0f;
      this->lh2 = 0.0f;
      this->rh1 = 0.0f;
      this->rh2 = 0.0f;
    }
  }

  // field types and members
  using _lf1_type =
    float;
  _lf1_type lf1;
  using _lf2_type =
    float;
  _lf2_type lf2;
  using _rf1_type =
    float;
  _rf1_type rf1;
  using _rf2_type =
    float;
  _rf2_type rf2;
  using _lh1_type =
    float;
  _lh1_type lh1;
  using _lh2_type =
    float;
  _lh2_type lh2;
  using _rh1_type =
    float;
  _rh1_type rh1;
  using _rh2_type =
    float;
  _rh2_type rh2;

  // setters for named parameter idiom
  Type & set__lf1(
    const float & _arg)
  {
    this->lf1 = _arg;
    return *this;
  }
  Type & set__lf2(
    const float & _arg)
  {
    this->lf2 = _arg;
    return *this;
  }
  Type & set__rf1(
    const float & _arg)
  {
    this->rf1 = _arg;
    return *this;
  }
  Type & set__rf2(
    const float & _arg)
  {
    this->rf2 = _arg;
    return *this;
  }
  Type & set__lh1(
    const float & _arg)
  {
    this->lh1 = _arg;
    return *this;
  }
  Type & set__lh2(
    const float & _arg)
  {
    this->lh2 = _arg;
    return *this;
  }
  Type & set__rh1(
    const float & _arg)
  {
    this->rh1 = _arg;
    return *this;
  }
  Type & set__rh2(
    const float & _arg)
  {
    this->rh2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ifv_interfaces::msg::Torque8dof_<ContainerAllocator> *;
  using ConstRawPtr =
    const ifv_interfaces::msg::Torque8dof_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ifv_interfaces::msg::Torque8dof_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ifv_interfaces::msg::Torque8dof_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ifv_interfaces::msg::Torque8dof_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ifv_interfaces::msg::Torque8dof_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ifv_interfaces::msg::Torque8dof_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ifv_interfaces::msg::Torque8dof_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ifv_interfaces::msg::Torque8dof_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ifv_interfaces::msg::Torque8dof_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ifv_interfaces__msg__Torque8dof
    std::shared_ptr<ifv_interfaces::msg::Torque8dof_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ifv_interfaces__msg__Torque8dof
    std::shared_ptr<ifv_interfaces::msg::Torque8dof_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Torque8dof_ & other) const
  {
    if (this->lf1 != other.lf1) {
      return false;
    }
    if (this->lf2 != other.lf2) {
      return false;
    }
    if (this->rf1 != other.rf1) {
      return false;
    }
    if (this->rf2 != other.rf2) {
      return false;
    }
    if (this->lh1 != other.lh1) {
      return false;
    }
    if (this->lh2 != other.lh2) {
      return false;
    }
    if (this->rh1 != other.rh1) {
      return false;
    }
    if (this->rh2 != other.rh2) {
      return false;
    }
    return true;
  }
  bool operator!=(const Torque8dof_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Torque8dof_

// alias to use template instance with default allocator
using Torque8dof =
  ifv_interfaces::msg::Torque8dof_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ifv_interfaces

#endif  // IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__STRUCT_HPP_
