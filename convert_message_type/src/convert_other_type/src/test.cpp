#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <iostream>
#include <set>
#include <boost/foreach.hpp>
#include "jst_image.h"
#include "convert_other_type/jst_image.h"

int main(int argc, char **argv)
{
	rosbag::Bag bag_read;
	rosbag::Bag bag_write;
	bag_read.open(argv[1], rosbag::bagmode::Read);
	bag_write.open(argv[2], rosbag::bagmode::Write);
	
	rosbag::View view_all(bag_read);  
	BOOST_FOREACH(rosbag::MessageInstance const m, view_all)
	{
		if (m.getTopic() == "/JstClassifier"){
            jst_video::jst_image::ConstPtr jst_img_msg = m.instantiate<jst_video::jst_image>();
			
			convert_other_type::jst_image convert_msg;
			convert_msg.header = jst_img_msg->header;
			convert_msg.score = jst_img_msg->score;
            
			if (jst_img_msg != NULL){              
                ros::Time   time= m.getTime();
                bag_write.write("/JstClassifier", time, convert_msg);
            }
     	}else
		{
			bag_write.write(m.getTopic(),m.getTime(),m);
		}
	}
	bag_read.close();
	return 0;
}