The ros_pub_video will publish two kinds of topics.
One is sensor_msgs/Image
The other is self-defined messages contains only one value, "score"

The rviz_plugin will receive the above topics and render the image.
If the score is smaller than 0.5, then it will print "IDIOT" over the image layer.
If the score is greater than 0.5, then it will print "GENIUS" over the image layer.

Don't want to offend anyone. Just demo video.


#How to build
catkin_make

#How to Run
Terminal One
roscore

Terminal Two
source devel/setup.bash
rosrun jst_video pub_video your_video_path

Terminal Three
source devel/setup.bash
rviz

Add new plugins --> draw_image/JSTImageDisplay

Choose the correct topics
![negative](https://github.com/haopo2005/My_ROS_Project/blob/master/custom_rviz_plugins/result/negative.png)
![positive](https://github.com/haopo2005/My_ROS_Project/blob/master/custom_rviz_plugins/result/positive.png)
