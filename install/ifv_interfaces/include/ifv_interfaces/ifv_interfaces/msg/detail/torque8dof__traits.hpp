// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice

#ifndef IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__TRAITS_HPP_
#define IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ifv_interfaces/msg/detail/torque8dof__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ifv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Torque8dof & msg,
  std::ostream & out)
{
  out << "{";
  // member: lf1
  {
    out << "lf1: ";
    rosidl_generator_traits::value_to_yaml(msg.lf1, out);
    out << ", ";
  }

  // member: lf2
  {
    out << "lf2: ";
    rosidl_generator_traits::value_to_yaml(msg.lf2, out);
    out << ", ";
  }

  // member: rf1
  {
    out << "rf1: ";
    rosidl_generator_traits::value_to_yaml(msg.rf1, out);
    out << ", ";
  }

  // member: rf2
  {
    out << "rf2: ";
    rosidl_generator_traits::value_to_yaml(msg.rf2, out);
    out << ", ";
  }

  // member: lh1
  {
    out << "lh1: ";
    rosidl_generator_traits::value_to_yaml(msg.lh1, out);
    out << ", ";
  }

  // member: lh2
  {
    out << "lh2: ";
    rosidl_generator_traits::value_to_yaml(msg.lh2, out);
    out << ", ";
  }

  // member: rh1
  {
    out << "rh1: ";
    rosidl_generator_traits::value_to_yaml(msg.rh1, out);
    out << ", ";
  }

  // member: rh2
  {
    out << "rh2: ";
    rosidl_generator_traits::value_to_yaml(msg.rh2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Torque8dof & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lf1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lf1: ";
    rosidl_generator_traits::value_to_yaml(msg.lf1, out);
    out << "\n";
  }

  // member: lf2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lf2: ";
    rosidl_generator_traits::value_to_yaml(msg.lf2, out);
    out << "\n";
  }

  // member: rf1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rf1: ";
    rosidl_generator_traits::value_to_yaml(msg.rf1, out);
    out << "\n";
  }

  // member: rf2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rf2: ";
    rosidl_generator_traits::value_to_yaml(msg.rf2, out);
    out << "\n";
  }

  // member: lh1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lh1: ";
    rosidl_generator_traits::value_to_yaml(msg.lh1, out);
    out << "\n";
  }

  // member: lh2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lh2: ";
    rosidl_generator_traits::value_to_yaml(msg.lh2, out);
    out << "\n";
  }

  // member: rh1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rh1: ";
    rosidl_generator_traits::value_to_yaml(msg.rh1, out);
    out << "\n";
  }

  // member: rh2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rh2: ";
    rosidl_generator_traits::value_to_yaml(msg.rh2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Torque8dof & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ifv_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ifv_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ifv_interfaces::msg::Torque8dof & msg,
  std::ostream & out, size_t indentation = 0)
{
  ifv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ifv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ifv_interfaces::msg::Torque8dof & msg)
{
  return ifv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ifv_interfaces::msg::Torque8dof>()
{
  return "ifv_interfaces::msg::Torque8dof";
}

template<>
inline const char * name<ifv_interfaces::msg::Torque8dof>()
{
  return "ifv_interfaces/msg/Torque8dof";
}

template<>
struct has_fixed_size<ifv_interfaces::msg::Torque8dof>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ifv_interfaces::msg::Torque8dof>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ifv_interfaces::msg::Torque8dof>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__TRAITS_HPP_
