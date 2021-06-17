#include "ros/ros.h"
#include "yh_210609_2/yh_srv_2.h"

bool calculation(yh_210609_2::yh_srv_2::Request &req, yh_210609_2::yh_srv_2::Response &res) {

    res.result = req.a + req.b + req.c;

    ROS_INFO("request is accepted : a= %ld, b = %ld, c = %ld", (long int)req.a, (long int)req.b, (long int)req.c);
    ROS_INFO("send back result to client : %ld", (long int)res.result);

    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "srv_server_2");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("yh_service_pls_abc", calculation);

    ROS_INFO("yh_server_2 is ready!");

    ros::spin();
    return 0;
}