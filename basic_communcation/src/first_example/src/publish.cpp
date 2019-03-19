#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "simple_publisher");
    ros::NodeHandle n; // it's the handler of our process, it allow us to interact with environment
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("message",10);//topic name
    
    ros::Rate loop_rate(10);//10HZ
    while(ros::ok()) //could be stopped by ctrl + c
    {
        std_msgs::String msg;
        std::stringstream ss;
        
        ss << "I am the publisher node";
        msg.data = ss.str();
        chatter_pub.publish(msg);
        
        loop_rate.sleep();
    }
    return 0;
}