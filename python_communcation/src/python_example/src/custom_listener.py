#!/usr/bin/env python
import rospy
from python_example.msg import Person

def callback(data):
	rospy.loginfo('%s is age: %d' % (data.name, data.age))

def listener():
	rospy.init_node('custom_listener', anonymous=True)
	rospy.Subscriber('custom_chatter', Person, callback)
	
	rospy.spin()

if __name__ == '__main__':
	listener()