#include "ros/ros.h"
#include "first_example/first_msg1.h"


void messageCallback(const first_example::first_msg1::ConstPtr &msg)
{
	ROS_INFO("I heard: [%d] [%d] [%d]", msg->A, msg->B, msg->C);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "CustomMessage_Sub");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("message", 1000, messageCallback);
	ros::spin();
	return 0;
}
