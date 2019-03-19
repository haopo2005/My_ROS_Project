#include "ros/ros.h"
#include "first_example/first_srv1.h" //the header file under devel/include

bool add(first_example::first_srv1::Request &req,
            first_example::first_srv1::Response &res)
{
    res.sum = req.A + req.B + req.C;
    ROS_INFO("request: A=%ld, B=%ld, C=%ld", (int)req.A, (int)req.B, (int)req.C);
    ROS_INFO("sending back response: [%ld]", (int)res.sum);
    
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"add_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("add_3_ints", add);
    ROS_INFO("Ready to add 3 ints.");
    
    ros::spin();
    return 0;
}