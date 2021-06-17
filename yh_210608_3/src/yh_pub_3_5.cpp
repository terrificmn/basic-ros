#include "ros/ros.h";
#include "yh_210608_3/yh_msg_3.h";


int main(int argc, char **argv) {

    ros::init(argc, argv, "yh_pub_3_5"); //node 이름 설정
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise < yh_210608_3::yh_msg_3 >("yh_topic_3", 100);
    ros::Rate loop_rate(10);  //0.2초마다 2씩 증가

    yh_210608_3::yh_msg_3 msg;

    int count = 0;

    while(ros::ok()) {
        msg.stamp = ros::Time::now();
        msg.data = count;

        ROS_INFO("send msg = %d", msg.stamp.sec);
        ROS_INFO("send msg = %d", msg.stamp.nsec);
        ROS_INFO("send msg = %d", msg.data);

        pub.publish(msg);
        loop_rate.sleep();
        //루프가 5의 배수일때만 카운트 해주기, 5번 루프 (한번 0.1초) 돌면 카운트 5해주기
        if (count % 5 == 0) {
            count += 5;
        }
    }

    return 0;
}