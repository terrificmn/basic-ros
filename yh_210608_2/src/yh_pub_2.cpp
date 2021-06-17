#include "ros/ros.h";
#include "yh_210608_2/yh_msg_2.h";


int main(int argc, char **argv) {

    ros::init(argc, argv, "yh_pub_2"); //node 이름 설정
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise < yh_210608_2::yh_msg_2 >("yh_topic_2", 100);
    ros::Rate loop_rate(5);

    yh_210608_2::yh_msg_2 msg;

    int count = 0;

    while(ros::ok()) {
        msg.stamp = ros::Time::now();
        msg.data = count;

        ROS_INFO("send msg = %d", msg.stamp.sec);
        ROS_INFO("send msg = %d", msg.stamp.nsec);
        ROS_INFO("send msg = %d", msg.data);

        pub.publish(msg);
        loop_rate.sleep();
        ++count;
    }

    return 0;
}
