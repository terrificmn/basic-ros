#include "ros/ros.h"
#include "yh_tuto_service/yh_srv.h"

// 패키지이름::서비스이름::Request 참조연산& 변수
bool calculation(yh_tuto_service::yh_srv::Request &req, yh_tuto_service::yh_srv::Response &res) {

    res.result = req.a + req.b;

    ROS_INFO("request : x= %ld, y = %ld", (long int)req.a, (long int)req.b); //%ld 는 long int
    ROS_INFO("sending back response : %ld", (long int)res.result);

    return true;  //리턴을 bool 로 선언했음
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "srv_server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("hamburger", calculation); //service에서는 advertiseService()를 사용,이하 문자열은 서비스명

    ROS_INFO("ready srv server!!");

    ros::spin(); // 응답이 있을 때까지 계속 spin()함수에서 들어가 있게 됨

    return 0;
}
