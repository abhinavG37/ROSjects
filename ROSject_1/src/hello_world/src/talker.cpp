//
// Created by abhinav137 on 15/07/21.
//
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "TALKER_NODE_1");

  ros::NodeHandle node_talker;
  ros::Publisher chatter_pub = node_talker.advertise<std_msgs::String>("Chatter", 100);
  ros::Rate loop_rate(10);
  int count = 0;

  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;

    ss << "Hello World" << count << std::endl;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
}
