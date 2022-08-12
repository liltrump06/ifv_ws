// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice
#include "ifv_interfaces/msg/detail/torque8dof__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ifv_interfaces/msg/detail/torque8dof__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ifv_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ifv_interfaces
cdr_serialize(
  const ifv_interfaces::msg::Torque8dof & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: lf1
  cdr << ros_message.lf1;
  // Member: lf2
  cdr << ros_message.lf2;
  // Member: rf1
  cdr << ros_message.rf1;
  // Member: rf2
  cdr << ros_message.rf2;
  // Member: lh1
  cdr << ros_message.lh1;
  // Member: lh2
  cdr << ros_message.lh2;
  // Member: rh1
  cdr << ros_message.rh1;
  // Member: rh2
  cdr << ros_message.rh2;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ifv_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ifv_interfaces::msg::Torque8dof & ros_message)
{
  // Member: lf1
  cdr >> ros_message.lf1;

  // Member: lf2
  cdr >> ros_message.lf2;

  // Member: rf1
  cdr >> ros_message.rf1;

  // Member: rf2
  cdr >> ros_message.rf2;

  // Member: lh1
  cdr >> ros_message.lh1;

  // Member: lh2
  cdr >> ros_message.lh2;

  // Member: rh1
  cdr >> ros_message.rh1;

  // Member: rh2
  cdr >> ros_message.rh2;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ifv_interfaces
get_serialized_size(
  const ifv_interfaces::msg::Torque8dof & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: lf1
  {
    size_t item_size = sizeof(ros_message.lf1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lf2
  {
    size_t item_size = sizeof(ros_message.lf2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rf1
  {
    size_t item_size = sizeof(ros_message.rf1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rf2
  {
    size_t item_size = sizeof(ros_message.rf2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lh1
  {
    size_t item_size = sizeof(ros_message.lh1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lh2
  {
    size_t item_size = sizeof(ros_message.lh2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rh1
  {
    size_t item_size = sizeof(ros_message.rh1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rh2
  {
    size_t item_size = sizeof(ros_message.rh2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ifv_interfaces
max_serialized_size_Torque8dof(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: lf1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: lf2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rf1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rf2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: lh1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: lh2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rh1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rh2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Torque8dof__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ifv_interfaces::msg::Torque8dof *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Torque8dof__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ifv_interfaces::msg::Torque8dof *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Torque8dof__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ifv_interfaces::msg::Torque8dof *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Torque8dof__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Torque8dof(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Torque8dof__callbacks = {
  "ifv_interfaces::msg",
  "Torque8dof",
  _Torque8dof__cdr_serialize,
  _Torque8dof__cdr_deserialize,
  _Torque8dof__get_serialized_size,
  _Torque8dof__max_serialized_size
};

static rosidl_message_type_support_t _Torque8dof__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Torque8dof__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ifv_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ifv_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ifv_interfaces::msg::Torque8dof>()
{
  return &ifv_interfaces::msg::typesupport_fastrtps_cpp::_Torque8dof__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ifv_interfaces, msg, Torque8dof)() {
  return &ifv_interfaces::msg::typesupport_fastrtps_cpp::_Torque8dof__handle;
}

#ifdef __cplusplus
}
#endif
