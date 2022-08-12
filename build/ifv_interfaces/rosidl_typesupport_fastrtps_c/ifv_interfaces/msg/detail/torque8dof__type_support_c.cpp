// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice
#include "ifv_interfaces/msg/detail/torque8dof__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ifv_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ifv_interfaces/msg/detail/torque8dof__struct.h"
#include "ifv_interfaces/msg/detail/torque8dof__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Torque8dof__ros_msg_type = ifv_interfaces__msg__Torque8dof;

static bool _Torque8dof__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Torque8dof__ros_msg_type * ros_message = static_cast<const _Torque8dof__ros_msg_type *>(untyped_ros_message);
  // Field name: lf1
  {
    cdr << ros_message->lf1;
  }

  // Field name: lf2
  {
    cdr << ros_message->lf2;
  }

  // Field name: rf1
  {
    cdr << ros_message->rf1;
  }

  // Field name: rf2
  {
    cdr << ros_message->rf2;
  }

  // Field name: lh1
  {
    cdr << ros_message->lh1;
  }

  // Field name: lh2
  {
    cdr << ros_message->lh2;
  }

  // Field name: rh1
  {
    cdr << ros_message->rh1;
  }

  // Field name: rh2
  {
    cdr << ros_message->rh2;
  }

  return true;
}

static bool _Torque8dof__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Torque8dof__ros_msg_type * ros_message = static_cast<_Torque8dof__ros_msg_type *>(untyped_ros_message);
  // Field name: lf1
  {
    cdr >> ros_message->lf1;
  }

  // Field name: lf2
  {
    cdr >> ros_message->lf2;
  }

  // Field name: rf1
  {
    cdr >> ros_message->rf1;
  }

  // Field name: rf2
  {
    cdr >> ros_message->rf2;
  }

  // Field name: lh1
  {
    cdr >> ros_message->lh1;
  }

  // Field name: lh2
  {
    cdr >> ros_message->lh2;
  }

  // Field name: rh1
  {
    cdr >> ros_message->rh1;
  }

  // Field name: rh2
  {
    cdr >> ros_message->rh2;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ifv_interfaces
size_t get_serialized_size_ifv_interfaces__msg__Torque8dof(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Torque8dof__ros_msg_type * ros_message = static_cast<const _Torque8dof__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name lf1
  {
    size_t item_size = sizeof(ros_message->lf1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lf2
  {
    size_t item_size = sizeof(ros_message->lf2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rf1
  {
    size_t item_size = sizeof(ros_message->rf1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rf2
  {
    size_t item_size = sizeof(ros_message->rf2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lh1
  {
    size_t item_size = sizeof(ros_message->lh1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lh2
  {
    size_t item_size = sizeof(ros_message->lh2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rh1
  {
    size_t item_size = sizeof(ros_message->rh1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rh2
  {
    size_t item_size = sizeof(ros_message->rh2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Torque8dof__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ifv_interfaces__msg__Torque8dof(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ifv_interfaces
size_t max_serialized_size_ifv_interfaces__msg__Torque8dof(
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

  // member: lf1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: lf2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rf1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rf2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: lh1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: lh2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rh1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rh2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Torque8dof__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ifv_interfaces__msg__Torque8dof(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Torque8dof = {
  "ifv_interfaces::msg",
  "Torque8dof",
  _Torque8dof__cdr_serialize,
  _Torque8dof__cdr_deserialize,
  _Torque8dof__get_serialized_size,
  _Torque8dof__max_serialized_size
};

static rosidl_message_type_support_t _Torque8dof__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Torque8dof,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ifv_interfaces, msg, Torque8dof)() {
  return &_Torque8dof__type_support;
}

#if defined(__cplusplus)
}
#endif
