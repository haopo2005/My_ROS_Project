#include "ros/ros.h"
#include "first_example/first_msg1.h"
#include <sstream>

//transfer data via custom message
int main(int argc, char **argv)
{
	ros::init(argc, argv, "CustomMessage_Pub");
	ros::NodeHandle n;
	
	ros::Publisher pub = n.advertise<first_example::first_msg1>("message", 1000);
	ros::Rate loop_rate(10);
	
	while(ros::ok())
	{
		first_example::first_msg1 msg;
		msg.A = 1;
		msg.B = 2;
		msg.C = 3;
		pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}