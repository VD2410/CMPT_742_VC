#include <ros/ros.h>
#include <tf/transform_listener.h>
int main(int argc, char** argv) {
	ros::init(argc, argv, "my_tf_listener");
	ros::NodeHandle node;
	tf::TransformListener listener;
	ros::Rate rate(10.0);
	while (ros::ok()) {
		tf::StampedTransform tf_odom_robot;
		try {
		listener.lookupTransform("odom", "base_link",
		ros::Time(0), tf_odom_robot);
		} catch (tf::TransformException &ex) {
		ROS_ERROR("%s", ex.what());
		ros::Duration(1.0).sleep();
		continue;
		}
		ROS_INFO("robot pose: (%f, %f), %f",
		tf_odom_robot.getOrigin().getX(),
		tf_odom_robot.getOrigin().getY(),
		tf::getYaw(tf_odom_robot.getRotation()) * 180 / M_PI);
		rate.sleep();
		}
	return 0;
}
