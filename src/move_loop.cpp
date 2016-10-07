#include <iostream>
#include <stdio.h>

#include <ros/ros.h>

#include <moveit/move_group_interface/move_group.h>

#include <tf/transform_datatypes.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "MoveLoop");
  ros::AsyncSpinner spinner(1);
  spinner.start();

  geometry_msgs::Pose pose[4];

  pose[0].position.x = 0.922;
  pose[0].position.y = 0.721;
  pose[0].position.z = 1.259;
  pose[0].orientation = tf::createQuaternionMsgFromRollPitchYaw(0.0,0.0,0.0);

  pose[1].position.x = 0.922;
  pose[1].position.y = 1.021;
  pose[1].position.z = 1.259;
  pose[1].orientation = tf::createQuaternionMsgFromRollPitchYaw(0.0,0.0,0.0);

  pose[2].position.x = 0.922;
  pose[2].position.y = 1.021;
  pose[2].position.z = 1.079;
  pose[2].orientation = tf::createQuaternionMsgFromRollPitchYaw(0.0,0.0,0.0);

  pose[3].position.x = 0.922;
  pose[3].position.y = 0.721;
  pose[3].position.z = 1.079;
  pose[3].orientation = tf::createQuaternionMsgFromRollPitchYaw(0.0,0.0,0.0);

  moveit::planning_interface::MoveGroup move_group("arm");

  int i=0;
  while(true) 
  {
    move_group.setPoseTarget(pose[i],"s_model_tool0");
    bool success = move_group.move();
    if (!success)
      break;
    i++;
    if (i==3)
      i=0;
  }

  return 0;
}

