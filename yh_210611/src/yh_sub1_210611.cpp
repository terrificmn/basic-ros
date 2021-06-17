#include "ros/ros.h"
#include "iostream"
#include "yh_210611/topic_wherefrom.h"

using namespace std;

void msgCallback (const yh_210611::topic_wherefrom::ConstPtr&msg) { // 파라미터를 상수 형태로 끊어서 사용하겠다

    if (msg->pubNum == 1) {
        cout << "received msg from yh_pub1_210611 node" << endl;
        cout << "received msg is " << msg->data << endl;
    } else if  (msg->pubNum == 2) {
        cout << "received msg from yh_pub2_210611 node" << endl;
        cout << "received msg is " << msg->data << endl;
    }

        cout << "------------------------------------" << endl;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "sub_star"); //ros 초기화 하면서 노드명을 만들어 준다
    ros::NodeHandle nh; //NodeHandle 을 nh로 만들어 준다 . 현재 노드에 해당한다

    //Subscriber 이용해서 sub 객체로 만들어 준다
    //nh.subscribe() 을 사용해서 서브스크라이드를 해주는데 topic은 yh_topic 으로 해준다
    // msgCallback을 호출한다
    ros::Subscriber sub = nh.subscribe("topic_wherefrom", 100, msgCallback);

    ros::spin();
    // spin() 함수는 publisher에서 메세지가 있을 때까지 기다린다

    return 0;
}