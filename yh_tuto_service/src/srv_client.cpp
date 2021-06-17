#include "ros/ros.h"
#include "yh_tuto_service/yh_srv.h"
#include <cstdlib>  //atoll() 함수를 사용하기 위해서 인쿠르드

int main(int argc, char **argv) {
    ros::init(argc, argv, "srv_client");
    
    if (argc != 3) { // 사용자가 입력값이 안 들어왔을 때 안내 메세지 띄움
        ROS_INFO("cmd: rosrun yh_tuto_service srv_client arg0 arg1");
        ROS_INFO("arg0 : double number, arg1 : double number");

        return 1;
    }
    
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<yh_tuto_service::yh_srv>("hamburger"); //serviceClient를 선언
    // < 안에 자료형이 들어간다 >

    yh_tuto_service::yh_srv srv;  //srv를 만들어 줌
    srv.request.a = atoll(argv[1]);  //입력되는 값을 분리해서 넣어주는 함수
    srv.request.b = atoll(argv[2]);  

    if (client.call(srv)) {  //srv를 요청하는 곳 
        ROS_INFO("send srv, srv.Request.a and b : %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
        ROS_INFO("receive srv, srv.Response.result : %ld", (long int)srv.response.result);
        
    
    } else {  //에러처리
        ROS_ERROR("Failed to call service"); //에러표시를 빨간색으로 해줌
        // call이 제대로 안되는 경우는 server노드가 작동을 안하고 있거나
        // client에서 서비스명을 제대로 입력을 못했을 경우에 여기 else문에 들어오게 된다
        return 1;
    }
    return 0;

}