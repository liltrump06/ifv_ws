// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice

#ifndef IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__STRUCT_H_
#define IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Torque8dof in the package ifv_interfaces.
typedef struct ifv_interfaces__msg__Torque8dof
{
  float lf1;
  float lf2;
  float rf1;
  float rf2;
  float lh1;
  float lh2;
  float rh1;
  float rh2;
} ifv_interfaces__msg__Torque8dof;

// Struct for a sequence of ifv_interfaces__msg__Torque8dof.
typedef struct ifv_interfaces__msg__Torque8dof__Sequence
{
  ifv_interfaces__msg__Torque8dof * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ifv_interfaces__msg__Torque8dof__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__STRUCT_H_
