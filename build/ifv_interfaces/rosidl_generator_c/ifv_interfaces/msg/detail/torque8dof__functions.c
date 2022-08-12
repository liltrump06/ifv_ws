// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice
#include "ifv_interfaces/msg/detail/torque8dof__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ifv_interfaces__msg__Torque8dof__init(ifv_interfaces__msg__Torque8dof * msg)
{
  if (!msg) {
    return false;
  }
  // lf1
  // lf2
  // rf1
  // rf2
  // lh1
  // lh2
  // rh1
  // rh2
  return true;
}

void
ifv_interfaces__msg__Torque8dof__fini(ifv_interfaces__msg__Torque8dof * msg)
{
  if (!msg) {
    return;
  }
  // lf1
  // lf2
  // rf1
  // rf2
  // lh1
  // lh2
  // rh1
  // rh2
}

bool
ifv_interfaces__msg__Torque8dof__are_equal(const ifv_interfaces__msg__Torque8dof * lhs, const ifv_interfaces__msg__Torque8dof * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lf1
  if (lhs->lf1 != rhs->lf1) {
    return false;
  }
  // lf2
  if (lhs->lf2 != rhs->lf2) {
    return false;
  }
  // rf1
  if (lhs->rf1 != rhs->rf1) {
    return false;
  }
  // rf2
  if (lhs->rf2 != rhs->rf2) {
    return false;
  }
  // lh1
  if (lhs->lh1 != rhs->lh1) {
    return false;
  }
  // lh2
  if (lhs->lh2 != rhs->lh2) {
    return false;
  }
  // rh1
  if (lhs->rh1 != rhs->rh1) {
    return false;
  }
  // rh2
  if (lhs->rh2 != rhs->rh2) {
    return false;
  }
  return true;
}

bool
ifv_interfaces__msg__Torque8dof__copy(
  const ifv_interfaces__msg__Torque8dof * input,
  ifv_interfaces__msg__Torque8dof * output)
{
  if (!input || !output) {
    return false;
  }
  // lf1
  output->lf1 = input->lf1;
  // lf2
  output->lf2 = input->lf2;
  // rf1
  output->rf1 = input->rf1;
  // rf2
  output->rf2 = input->rf2;
  // lh1
  output->lh1 = input->lh1;
  // lh2
  output->lh2 = input->lh2;
  // rh1
  output->rh1 = input->rh1;
  // rh2
  output->rh2 = input->rh2;
  return true;
}

ifv_interfaces__msg__Torque8dof *
ifv_interfaces__msg__Torque8dof__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ifv_interfaces__msg__Torque8dof * msg = (ifv_interfaces__msg__Torque8dof *)allocator.allocate(sizeof(ifv_interfaces__msg__Torque8dof), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ifv_interfaces__msg__Torque8dof));
  bool success = ifv_interfaces__msg__Torque8dof__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ifv_interfaces__msg__Torque8dof__destroy(ifv_interfaces__msg__Torque8dof * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ifv_interfaces__msg__Torque8dof__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ifv_interfaces__msg__Torque8dof__Sequence__init(ifv_interfaces__msg__Torque8dof__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ifv_interfaces__msg__Torque8dof * data = NULL;

  if (size) {
    data = (ifv_interfaces__msg__Torque8dof *)allocator.zero_allocate(size, sizeof(ifv_interfaces__msg__Torque8dof), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ifv_interfaces__msg__Torque8dof__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ifv_interfaces__msg__Torque8dof__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ifv_interfaces__msg__Torque8dof__Sequence__fini(ifv_interfaces__msg__Torque8dof__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ifv_interfaces__msg__Torque8dof__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ifv_interfaces__msg__Torque8dof__Sequence *
ifv_interfaces__msg__Torque8dof__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ifv_interfaces__msg__Torque8dof__Sequence * array = (ifv_interfaces__msg__Torque8dof__Sequence *)allocator.allocate(sizeof(ifv_interfaces__msg__Torque8dof__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ifv_interfaces__msg__Torque8dof__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ifv_interfaces__msg__Torque8dof__Sequence__destroy(ifv_interfaces__msg__Torque8dof__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ifv_interfaces__msg__Torque8dof__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ifv_interfaces__msg__Torque8dof__Sequence__are_equal(const ifv_interfaces__msg__Torque8dof__Sequence * lhs, const ifv_interfaces__msg__Torque8dof__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ifv_interfaces__msg__Torque8dof__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ifv_interfaces__msg__Torque8dof__Sequence__copy(
  const ifv_interfaces__msg__Torque8dof__Sequence * input,
  ifv_interfaces__msg__Torque8dof__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ifv_interfaces__msg__Torque8dof);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ifv_interfaces__msg__Torque8dof * data =
      (ifv_interfaces__msg__Torque8dof *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ifv_interfaces__msg__Torque8dof__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ifv_interfaces__msg__Torque8dof__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ifv_interfaces__msg__Torque8dof__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
