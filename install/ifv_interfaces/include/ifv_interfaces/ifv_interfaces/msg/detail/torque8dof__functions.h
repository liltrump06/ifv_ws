// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice

#ifndef IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__FUNCTIONS_H_
#define IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ifv_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "ifv_interfaces/msg/detail/torque8dof__struct.h"

/// Initialize msg/Torque8dof message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ifv_interfaces__msg__Torque8dof
 * )) before or use
 * ifv_interfaces__msg__Torque8dof__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
bool
ifv_interfaces__msg__Torque8dof__init(ifv_interfaces__msg__Torque8dof * msg);

/// Finalize msg/Torque8dof message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
void
ifv_interfaces__msg__Torque8dof__fini(ifv_interfaces__msg__Torque8dof * msg);

/// Create msg/Torque8dof message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ifv_interfaces__msg__Torque8dof__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
ifv_interfaces__msg__Torque8dof *
ifv_interfaces__msg__Torque8dof__create();

/// Destroy msg/Torque8dof message.
/**
 * It calls
 * ifv_interfaces__msg__Torque8dof__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
void
ifv_interfaces__msg__Torque8dof__destroy(ifv_interfaces__msg__Torque8dof * msg);

/// Check for msg/Torque8dof message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
bool
ifv_interfaces__msg__Torque8dof__are_equal(const ifv_interfaces__msg__Torque8dof * lhs, const ifv_interfaces__msg__Torque8dof * rhs);

/// Copy a msg/Torque8dof message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
bool
ifv_interfaces__msg__Torque8dof__copy(
  const ifv_interfaces__msg__Torque8dof * input,
  ifv_interfaces__msg__Torque8dof * output);

/// Initialize array of msg/Torque8dof messages.
/**
 * It allocates the memory for the number of elements and calls
 * ifv_interfaces__msg__Torque8dof__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
bool
ifv_interfaces__msg__Torque8dof__Sequence__init(ifv_interfaces__msg__Torque8dof__Sequence * array, size_t size);

/// Finalize array of msg/Torque8dof messages.
/**
 * It calls
 * ifv_interfaces__msg__Torque8dof__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
void
ifv_interfaces__msg__Torque8dof__Sequence__fini(ifv_interfaces__msg__Torque8dof__Sequence * array);

/// Create array of msg/Torque8dof messages.
/**
 * It allocates the memory for the array and calls
 * ifv_interfaces__msg__Torque8dof__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
ifv_interfaces__msg__Torque8dof__Sequence *
ifv_interfaces__msg__Torque8dof__Sequence__create(size_t size);

/// Destroy array of msg/Torque8dof messages.
/**
 * It calls
 * ifv_interfaces__msg__Torque8dof__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
void
ifv_interfaces__msg__Torque8dof__Sequence__destroy(ifv_interfaces__msg__Torque8dof__Sequence * array);

/// Check for msg/Torque8dof message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
bool
ifv_interfaces__msg__Torque8dof__Sequence__are_equal(const ifv_interfaces__msg__Torque8dof__Sequence * lhs, const ifv_interfaces__msg__Torque8dof__Sequence * rhs);

/// Copy an array of msg/Torque8dof messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ifv_interfaces
bool
ifv_interfaces__msg__Torque8dof__Sequence__copy(
  const ifv_interfaces__msg__Torque8dof__Sequence * input,
  ifv_interfaces__msg__Torque8dof__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // IFV_INTERFACES__MSG__DETAIL__TORQUE8DOF__FUNCTIONS_H_
