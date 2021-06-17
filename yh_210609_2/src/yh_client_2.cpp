#include "ros/ros.h"
#include "yh_210609_2/yh_srv_2.h"
#include <cstdlib>

int main(int argc, char **argv) {
    ros::init(argc, argv, "yh_client2");

    if (argc != 4) { // 사용자가 입력값이 안 들어왔을 때 안내 메세지 띄움
        ROS_INFO("cmd: rosrun yh_tuto_service srv_client arg0 arg1 arg2");
        ROS_INFO("arg0 : double number, arg1 : double number, arg2 : double number");

        return 1;
    }

    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<yh_210609_2::yh_srv_2>("yh_service_pls_abc");

    yh_210609_2::yh_srv_2 srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);
    srv.request.c = atoll(argv[3]);

    if (client.call(srv)) {
        ROS_INFO("send to service-server... srv.Request.a : %ld,  b : %ld, and c : %ld", (long int)srv.request.a, (long int)srv.request.b, (long int)srv.request.c);
        ROS_INFO("received srv.Response.result : %ld", (long int)srv.response.result);
    
    } else {
        ROS_ERROR("Failed to call service");
        return 1;
    }
    
    return 0;
    
}