cmake_minimum_required(VERSION 2.8.3)
project(fix_haschke)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  moveit_ros_planning_interface
  tf
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(move_loop src/move_loop.cpp)
target_link_libraries(move_loop ${catkin_LIBRARIES})
