#include "ros/ros.h";
#include "yh_210608_2/yh_msg_2.h";

void msgCallback (const yh_210608_2::yh_msg_2::ConstPtr&msg) {
    ROS_INFO("received msg = %d", msg->stamp.sec);
    ROS_INFO("received msg = %d", msg->stamp.nsec);
    ROS_INFO("received msg = %d", msg->data);
    
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "yh_sub_2_time"); //node 명 정하기
    ros::NodeHandle nh;

    ros::Subscriber sub_int = nh.subscribe("yh_topic_2", 100, msgCallback);

    ros::spin();

    return 0;
}