#include "ros/ros.h"
#include "yh_210609_3/yh_srv_3.h"

bool calculation(yh_210609_3::yh_srv_3::Request &req, yh_210609_3::yh_srv_3::Response &res) {
    // 먼저 큰 수, 작은 수로 무조건 지정
    int greater = req.a;
    int smaller = req.b;
    int temp;

    // 스몰러가 크면 바꿔주기, 아니면 그대로 나둠
    if (greater < smaller) {
        temp = greater;
        greater = smaller;
        smaller = temp;
    }

    res.result = greater - smaller;

    ROS_INFO("request : x= %ld, y = %ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sorted number : greater is %ld, smaller is %ld", (long int)greater, (long int)smaller);
    ROS_INFO("send back response : %ld", (long int)res.result);

    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "srv_server_3");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("yh_service_3", calculation);

    ROS_INFO("srv_3 ready...");

    ros::spin();
    return 0;
}