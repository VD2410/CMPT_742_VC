#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
int main(int argc, char** argv) {
ros::init(argc, argv, "my_tf_broadcaster");
ros::NodeHandle node;
tf::TransformBroadcaster br;
ros::Rate rate(10.0);
while (ros::ok()) {
tf::StampedTransform tf_map_odom;
tf_map_odom.frame_id_ = "map";
tf_map_odom.child_frame_id_ = "odom";
tf_map_odom.stamp_ = ros::Time::now();
tf_map_odom.setOrigin(tf::Vector3(2, 1, 0));
tf_map_odom.setRotation(tf::createQuaternionFromYaw(0.78));
br.sendTransform(tf_map_odom);
rate.sleep();
}
return 0;
}
