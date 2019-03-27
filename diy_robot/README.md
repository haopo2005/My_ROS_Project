# install dependencies
`sudo apt-get install ros-kinetic-gazebo-ros-pkgs`
`sudo apt-get install ros-kinetic-gazebo-ros-control`

`wget https://bitbucket.org/osrf/gazebo_models/get/e6d645674e8a.zip`
`unzip e6d645674e8a.zip`
`mv xxx models`
`mv models ~/.gazebo`


# pull up gazebo
`roslaunch jst_laser gazebo_xacro.launch model:="`rospack find jst_laser`/urdf/robot1_base_04.xacro"`

# bring up rviz
`rviz`

# create laser
`rosrun jst_laser my_Laser`

# create odom
`rosrun jst_laser odom`

# add rviz plugin
 RobotModel, LaserScan and Odometry


![laser](laser_scan.png)
![odometry](odometry.png)