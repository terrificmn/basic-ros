#include "ros/ros.h"
#include "yh_210608_3/yh_msg_3.h"

void msgCallback (const yh_210608_3::yh_msg_3::ConstPtr&msg) {

    ROS_INFO("[odd number] received msg = %d", msg->stamp.sec);
    ROS_INFO("[odd number] received msg = %d", msg->stamp.nsec);
    ROS_INFO("[odd number] received msg = %d", msg->data);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "yh_sub_3"); //node 명 정하기
    ros::NodeHandle nh;

    ros::Subscriber sub_int = nh.subscribe("yh_topic_3", 100, msgCallback);

    ros::spin();

    return 0;
}