#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include "jst_video/jst_image.h"
#include <iostream>
using namespace cv;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "video_publisher");
	ros::NodeHandle nh;
	image_transport::ImageTransport it(nh);
	image_transport::Publisher pub = it.advertise("/camera/image", 1);
	ros::Publisher info_pub = nh.advertise<jst_video::jst_image>("/JstClassifier", 2);

	VideoCapture cap(argv[1]);
	if(!cap.isOpened())
	{
		std::cout<<"Error opening video stream or file"<<std::endl;
		return -1;
	}
	
	ros::Rate loop_rate(15);
	while (nh.ok()) {
		Mat frame;
		cap >> frame;
		if (frame.empty())
		{
			std::cout<<"Error opening video stream or file"<<std::endl;
			break;
		}
		sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
		pub.publish(msg);
		
		jst_video::jst_image score_msg;
		score_msg.header = std_msgs::Header();
		score_msg.score = 0.1;
		
		info_pub.publish(score_msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	
	
	return 0;
}