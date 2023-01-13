cmake_minimum_required(VERSION 3.8)
project(ft4222_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ifv_interfaces REQUIRED)
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
include_directories("/home/longarmape06/ifv_ws/install/ifv_interfaces/include/ifv_interfaces/")
add_library(lft4222 SHARED IMPORTED)
set_target_properties(lft4222 PROPERTIES IMPORTED_LOCATION
/usr/local/lib/libft4222.so)

# find_library(libft4222 NAMES lft4222 FT4222 libft4222 ft4222 REQUIRED)
# find_library(libftd2xx NAMES lftd2xx FTd2xx libftd2xx ftd2xx REQUIRED)
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


add_executable(ft4222_cent_test src/ft4222_node.cpp)
add_executable(ft4222_client src/ft4222_client.cpp)
ament_target_dependencies(ft4222_cent_test rclcpp std_msgs ifv_interfaces)
ament_target_dependencies(ft4222_client rclcpp std_msgs ifv_interfaces)
target_link_libraries(ft4222_cent_test ft4222)
install(TARGETS
  ft4222_cent_test
  ft4222_client
  DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME})
endif()
ament_package()
