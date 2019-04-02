# INSTALL DEPENDENCIES
`sudo apt-get install ros-kinetic-gazebo-ros-pkgs ros-kinetic-Gazebo-ros-control`  
`sudo apt-get install ros-kinetic-slam-gmapping`  
`sudo apt-get install ros-kinetic-navigation`  

# LAUNCH GAZEBO
`roslaunch jst_navigation_stack configuration_gazebo.launch model:="`rospack find jst_navigation_stack`/urdf/robot1_base_04.xacro"`  

# LAUNCH AMCL LOCALIZTION ALGORITHM
`roslaunch jst_navigation_stack move_base.launch`

# IMAGE VIEW
`rosrun image_view image_view image:=/robot/camera1/image_raw`

# LASER SCAN MESSAGE
`rostopic echo /robot/laser/scan`