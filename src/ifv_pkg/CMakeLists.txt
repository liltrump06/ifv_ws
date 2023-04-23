cmake_minimum_required(VERSION 3.8)
project(ifv_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(gazebo_dev REQUIRED)
find_package(ifv_interfaces REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(gazebo_ros REQUIRED)

include_directories(${GAZEBO_INCLUDE_DIRS})
include_directories(${gazebo_ros_INCLUDE_DIRS})
include_directories("/opt/ros/humble/include/gazebo_ros")
link_directories(${GAZEBO_LIBRARY_DIRS})
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(ifv_listener src/sub_joint.cpp)
ament_target_dependencies(ifv_listener rclcpp sensor_msgs ifv_interfaces)


add_library(applytorque SHARED src/gazebo_ros_12doftorque.cpp)
add_library(system_gui SHARED src/plugins/systemgui.cpp)
target_include_directories(applytorque PUBLIC include)
ament_target_dependencies(applytorque 
"gazebo_ros"
"gazebo_dev"
"rclcpp" 
"sensor_msgs" 
"ifv_interfaces"
)

ament_target_dependencies(system_gui 
"gazebo_dev"
)

target_link_libraries(applytorque ${GAZEBO_LIBRARIES} )
target_link_libraries(system_gui ${GAZEBO_LIBRARIES} )

install(TARGETS
  ifv_listener
  DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME})
install(DIRECTORY
  world
  DESTINATION share/${PROJECT_NAME})

ament_package()

