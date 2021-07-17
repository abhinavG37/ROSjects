//
// Created by abhinav137 on 15/07/21.
//
#include <ros/ros.h>
#include <std_msgs/String.h>


void ChatterCallbackFunc(const std_msgs::String::ConstPtr& msg){
  //Print logging info
  ros::ROS_INFO("LOGGING INFO for [%s]", msg->data.c_str());

}

int main(int argc, char **argv){
  ros::init(arg, argv, "TALKER_NODE-1");



  //Instance of Message Definition
  std_msgs::String msg;
  //msg has attribute data (read std_msgs::String to get details)
  msg->data = "HELLO-123";

  //Topic Publishing in ROS
  //Instance of publisher node
  ros::NodeHandle node_Talker;
  ros::Publisher publisher_object = node_Talker.advertise<std_msgs::String>("Chatter", 100);

  //Subscribing to a topic
  ros::NodeHandle node_subscriber;
  ros::Subscriber subscriber_object = node_subscriber.subscribe("Chatter", 100, ChatterCallbackFunc);
  //Getting params from Node
  std::string global_name;
  if(node_Talker.getParam("/global_name", global_name)){
    std::cout<"Before Setting Param"<<node_Talker.getParam("/global_name", global_name)<<std::endl;
    node_Talker.setParam("/global_name", 5);
    std::cout<"After Setting Param"<<node_Talker.getParam("/global_name", global_name)<<std::endl;
  }


}