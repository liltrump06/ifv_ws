# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ifv_interfaces:msg/Torque8dof.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Torque8dof(type):
    """Metaclass of message 'Torque8dof'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ifv_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ifv_interfaces.msg.Torque8dof')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__torque8dof
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__torque8dof
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__torque8dof
            cls._TYPE_SUPPORT = module.type_support_msg__msg__torque8dof
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__torque8dof

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Torque8dof(metaclass=Metaclass_Torque8dof):
    """Message class 'Torque8dof'."""

    __slots__ = [
        '_lf1',
        '_lf2',
        '_rf1',
        '_rf2',
        '_lh1',
        '_lh2',
        '_rh1',
        '_rh2',
    ]

    _fields_and_field_types = {
        'lf1': 'float',
        'lf2': 'float',
        'rf1': 'float',
        'rf2': 'float',
        'lh1': 'float',
        'lh2': 'float',
        'rh1': 'float',
        'rh2': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.lf1 = kwargs.get('lf1', float())
        self.lf2 = kwargs.get('lf2', float())
        self.rf1 = kwargs.get('rf1', float())
        self.rf2 = kwargs.get('rf2', float())
        self.lh1 = kwargs.get('lh1', float())
        self.lh2 = kwargs.get('lh2', float())
        self.rh1 = kwargs.get('rh1', float())
        self.rh2 = kwargs.get('rh2', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.lf1 != other.lf1:
            return False
        if self.lf2 != other.lf2:
            return False
        if self.rf1 != other.rf1:
            return False
        if self.rf2 != other.rf2:
            return False
        if self.lh1 != other.lh1:
            return False
        if self.lh2 != other.lh2:
            return False
        if self.rh1 != other.rh1:
            return False
        if self.rh2 != other.rh2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def lf1(self):
        """Message field 'lf1'."""
        return self._lf1

    @lf1.setter
    def lf1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lf1' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'lf1' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._lf1 = value

    @builtins.property
    def lf2(self):
        """Message field 'lf2'."""
        return self._lf2

    @lf2.setter
    def lf2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lf2' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'lf2' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._lf2 = value

    @builtins.property
    def rf1(self):
        """Message field 'rf1'."""
        return self._rf1

    @rf1.setter
    def rf1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rf1' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'rf1' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._rf1 = value

    @builtins.property
    def rf2(self):
        """Message field 'rf2'."""
        return self._rf2

    @rf2.setter
    def rf2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rf2' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'rf2' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._rf2 = value

    @builtins.property
    def lh1(self):
        """Message field 'lh1'."""
        return self._lh1

    @lh1.setter
    def lh1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lh1' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'lh1' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._lh1 = value

    @builtins.property
    def lh2(self):
        """Message field 'lh2'."""
        return self._lh2

    @lh2.setter
    def lh2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lh2' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'lh2' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._lh2 = value

    @builtins.property
    def rh1(self):
        """Message field 'rh1'."""
        return self._rh1

    @rh1.setter
    def rh1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rh1' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'rh1' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._rh1 = value

    @builtins.property
    def rh2(self):
        """Message field 'rh2'."""
        return self._rh2

    @rh2.setter
    def rh2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rh2' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'rh2' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._rh2 = value
