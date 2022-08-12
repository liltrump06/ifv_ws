// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ifv_interfaces:msg/Torque8dof.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ifv_interfaces/msg/detail/torque8dof__struct.h"
#include "ifv_interfaces/msg/detail/torque8dof__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ifv_interfaces__msg__torque8dof__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ifv_interfaces.msg._torque8dof.Torque8dof", full_classname_dest, 41) == 0);
  }
  ifv_interfaces__msg__Torque8dof * ros_message = _ros_message;
  {  // lf1
    PyObject * field = PyObject_GetAttrString(_pymsg, "lf1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lf1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lf2
    PyObject * field = PyObject_GetAttrString(_pymsg, "lf2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lf2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rf1
    PyObject * field = PyObject_GetAttrString(_pymsg, "rf1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rf1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rf2
    PyObject * field = PyObject_GetAttrString(_pymsg, "rf2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rf2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lh1
    PyObject * field = PyObject_GetAttrString(_pymsg, "lh1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lh1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lh2
    PyObject * field = PyObject_GetAttrString(_pymsg, "lh2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lh2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rh1
    PyObject * field = PyObject_GetAttrString(_pymsg, "rh1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rh1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rh2
    PyObject * field = PyObject_GetAttrString(_pymsg, "rh2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rh2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ifv_interfaces__msg__torque8dof__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Torque8dof */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ifv_interfaces.msg._torque8dof");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Torque8dof");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ifv_interfaces__msg__Torque8dof * ros_message = (ifv_interfaces__msg__Torque8dof *)raw_ros_message;
  {  // lf1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lf1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lf1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lf2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lf2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lf2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rf1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rf1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rf1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rf2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rf2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rf2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lh1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lh1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lh1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lh2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lh2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lh2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rh1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rh1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rh1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rh2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rh2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rh2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
