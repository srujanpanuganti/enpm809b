//--this program publishes randomly-generated velocity
//--messages for turtlebot3.
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>  //--for geometry_msgs::Twist
#include <stdlib.h> //--for rand() and RAND_MAX

int main(int argc, char **argv) {
  //--initialize the ROS system and become a node.
  ros::init(argc, argv, "publish_velocity");
  ros::NodeHandle nh;

  //--create a publisher object.
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>(
    "cmd_vel", 1000);

  //--seed the random number generator.
  srand(time(0));

  //--loop at 2Hz until the node is shut down.
  ros::Rate rate(2);
  while(ros::ok()) {
    //--create and fill in the message.  The other four
    //--fields, which are ignored by turtlebot, default to 0.
    geometry_msgs::Twist msg;
    msg.linear.x = double(rand())/double(RAND_MAX);
    msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

    //--publish the message.
    pub.publish(msg);

    //--send a message to rosout with the details.
    ROS_INFO_STREAM("Sending random velocity command:"
      << " linear=" << msg.linear.x
      << " angular=" << msg.angular.z);

    //--wait until it's time for another iteration.
    rate.sleep();
  }
}
