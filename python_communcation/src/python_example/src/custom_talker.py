#!/usr/bin/env python
import rospy
from python_example.msg import Person

def talker():
	pub = rospy.Publisher('custom_chatter', Person)
	rospy.init_node('custom_talker', anonymous=True)
	r = rospy.Rate(10) #10hz
	msg = Person()
	msg.name = 'jst'
	msg.age = 5
	
	while not rospy.is_shutdown():
		rospy.loginfo(msg)
		pub.publish(msg)
		r.sleep()

if __name__ == '__main__':
	try:
		talker()
	except rospy.ROSInterruptException:
		pass
		