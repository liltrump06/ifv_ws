// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "ifv_interfaces/msg/detail/torque8dof__struct.h"
#include "ifv_interfaces/msg/detail/torque8dof__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace ifv_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _Torque8dof_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Torque8dof_type_support_ids_t;

static const _Torque8dof_type_support_ids_t _Torque8dof_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Torque8dof_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Torque8dof_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Torque8dof_type_support_symbol_names_t _Torque8dof_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ifv_interfaces, msg, Torque8dof)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ifv_interfaces, msg, Torque8dof)),
  }
};

typedef struct _Torque8dof_type_support_data_t
{
  void * data[2];
} _Torque8dof_type_support_data_t;

static _Torque8dof_type_support_data_t _Torque8dof_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Torque8dof_message_typesupport_map = {
  2,
  "ifv_interfaces",
  &_Torque8dof_message_typesupport_ids.typesupport_identifier[0],
  &_Torque8dof_message_typesupport_symbol_names.symbol_name[0],
  &_Torque8dof_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Torque8dof_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Torque8dof_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace ifv_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ifv_interfaces, msg, Torque8dof)() {
  return &::ifv_interfaces::msg::rosidl_typesupport_c::Torque8dof_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
