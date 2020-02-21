

#include <ros/ros.h>
#include <sensor_msgs/JointState.h> //--to get joint states information
#include <trajectory_msgs/JointTrajectory.h>//--to send joint commands

int main(int argc, char **argv)
{
  ros::init(argc, argv, "arm1");
  ros::NodeHandle n;
  ros::Publisher arm1_cmd_pub = n.advertise<trajectory_msgs::JointTrajectory>("/ariac/arm1/arm/command", 10);
  // publish at at least 5 Hz, or else ur10 switches back to Position mode and holds position
  ros::Rate loop_rate(10);


  trajectory_msgs::JointTrajectory traj;

  traj.joint_names.push_back("linear_arm_actuator_joint");
  traj.joint_names.push_back("shoulder_pan_joint");
  traj.joint_names.push_back("shoulder_lift_joint");
  traj.joint_names.push_back("elbow_joint");
  traj.joint_names.push_back("wrist_1_joint");
  traj.joint_names.push_back("wrist_2_joint");
  traj.joint_names.push_back("wrist_3_joint");


  traj.points.resize(1);//--number of trajectory points

  while(ros::ok()) {

  // //traj.header.stamp = ros::Time::now();
  // //--FIRST Point
  // unsigned short ind {0};
  // traj.points[ind].positions.resize(7);//7 joints
  // traj.points[ind].positions[0] = 0.15;
  // traj.points[ind].positions[1] = 3.14;
  // traj.points[ind].positions[2] = -1.570;
  // traj.points[ind].positions[3] = 2.14;
  // traj.points[ind].positions[4] = 3.1;
  // traj.points[ind].positions[5] = -1.59;
  // traj.points[ind].positions[6] = 0.126;
  //
  // // Velocities
  // traj.points[ind].velocities.resize(7);
  // for (size_t j = 0; j < 7; ++j){
  //   traj.points[ind].velocities[j] = 0.1;
  // }
  //
  // // Reach the first point with 2 seconds after starting along the traj
  // traj.points[ind].time_from_start = ros::Duration(2.0);
  //
  // //--SECOND Point
  // ind++;
  // traj.points[ind].positions.resize(7);//7 joints
  // traj.points[ind].positions[0] = -0.35;
  // traj.points[ind].positions[1] = 3.14;
  // traj.points[ind].positions[2] = -0.6;
  // traj.points[ind].positions[3] = 2.3;
  // traj.points[ind].positions[4] = 3.0;
  // traj.points[ind].positions[5] = -1.59;
  // traj.points[ind].positions[6] = 0.126;
  //
  // // Velocities
  // traj.points[ind].velocities.resize(7);
  // for (size_t j = 0; j < 7; ++j){
  //   traj.points[ind].velocities[j] = 0.1;
  // }
  //
  // // Reach the second point with 4 seconds after starting along the traj
  // traj.points[ind].time_from_start = ros::Duration(4.0);


  //--Only one point
  int ind{0};
  traj.points[ind].positions.resize(7);//7 joints
  traj.points[ind].positions[0] = -0.35;
  traj.points[ind].positions[1] = 3.14;
  traj.points[ind].positions[2] = -0.5;
  traj.points[ind].positions[3] = 2.3;
  traj.points[ind].positions[4] = 3.05;
  traj.points[ind].positions[5] = -1.59;
  traj.points[ind].positions[6] = 0.126;

  // Velocities
  traj.points[ind].velocities.resize(7);
  for (size_t j = 0; j < 7; ++j){
    traj.points[ind].velocities[j] = 0.1;
  }

  // Reach the second point with 4 seconds after starting along the traj
  traj.points[ind].time_from_start = ros::Duration(3.0);


    traj.header.stamp = ros::Time::now() + ros::Duration();
    arm1_cmd_pub.publish(traj);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
