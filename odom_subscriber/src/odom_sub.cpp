#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

void OdomCallback(const nav_msgs::Odometry::ConstPtr& odom){
 ROS_INFO("I received odom: [%f,%f,%f]",
 odom->pose.pose.position.x,
 odom->pose.pose.position.y,
 odom->pose.pose.position.z); //store x,y,z position values
}

int main(int argc, char **argv){
  ros::init(argc, argv, "subscribe_to_pose");
  ros::NodeHandle nh;

  //--Create a subscriber object
  ros::Subscriber sub_odom = nh.subscribe("odom", 1000, &OdomCallback);

  //--Let ROS take over
  ros::spin();
}
