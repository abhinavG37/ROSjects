//
// Created by abhinav137 on 17/07/21.
//
#include <ros/ros.h>
#include <std_msgs/String.h>

void chatterCallback(const std_msgs::String::ConstPtr & msg){
  ROS_INFO("I Heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv){
  ros::init(argc, argv, "Listener");
  ros::NodeHandle node;
  ros::Subscriber chatter_sub = node.subscribe("Chatter", 1000, chatterCallback);
  ros::spin();
  return 0;
}