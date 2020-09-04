#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

int main(int argc, char** argv){

  ros::Publisher  pub;

  ros::init(argc, argv, "init_pose");

  ros::NodeHandle nh;
  pub= nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("initialpose", 2, true);

  ros::Time tmp_time = ros::Time::now();

  geometry_msgs::PoseWithCovarianceStamped initPose;

  initPose.header.stamp = tmp_time;  //  時間
  initPose.header.frame_id = "map";  //  フレーム
  initPose.pose.pose.position.x = 0;
  initPose.pose.pose.position.y = 0;
  initPose.pose.pose.position.z = 0;
  initPose.pose.pose.orientation.w = 1.0;

  // パブリッシュ amclパッケージに初期位置を送る
  pub.publish(initPose);
  
  ROS_INFO("The server comes up");

  while (ros::ok()) {

  }
  return 0;
}
