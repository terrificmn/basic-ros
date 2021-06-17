#include "ros/ros.h" //ROS 기본 헤더파일 추가하기 - 기본 함수들을 사용하기 위해서
#include "yh_210611/topic_wherefrom.h" // 패키지 이름/메세지파일이름.h 


int main(int argc, char **argv) {
    ros::init(argc, argv, "pub1_add1_a_sec");  // 위의 ros.h 파일을 가져왔기 때문에 ros를 사용할 수 있다
    // init()으로 노드명을 초기화 해준다

    ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드 핸들을 nh 로 만들어 준다

    // 퍼블리시어 선언, [패키지명] 즉, yh_210611 의 [메시지파일] 즉, topic_wherefrom을 이용해서
    // 퍼블리시어 작성한다. pub 으로 작성
    // 토픽명은 > "yh_topic", 퍼블리시어 큐 사이즈를 100 개로 설정
    ros::Publisher pub = nh.advertise < yh_210611::topic_wherefrom >("topic_wherefrom", 100);
    // yh_210611(패키지명)::topic_wherefrom(msg의 파일명) > 이하는 topic명을 정해준다, 100개의 que를 만들어 준다

    ros::Rate loop_rate(1); // 루프 주기를 1Hz로 설정 (1초에 반복되는 횟수) : 루프 한번이 1초에 한번 돌아간다

    yh_210611::topic_wherefrom msg;  //yh_210611의 topic_wherefrom 의 내가 만든 메시지 파일 형식으로 msg를 선언해준다

    int count = 0;

    while(ros::ok()) { // ros가 실행이 되면 ok()가 활성화가 된다.
        msg.stamp = ros::Time::now();  //현재 시간을 msg 객체의 stamp에 저장
        
        msg.data = count;   //count값을 msg객체의 data 에 저장
        msg.pubNum = 1; //pub 1 의미
        ROS_INFO("send msg = %d", msg.stamp.sec);  // ros의 prinft 함수 
        ROS_INFO("send msg = %d", msg.stamp.nsec); //Time::now()에서 받아온 시간이 .sec .nsec 이 있으므로 붙여준다
        ROS_INFO("send msg = %d", msg.data);

        pub.publish(msg);  //publish() 함수로 메세지를 발행한다
        loop_rate.sleep();
        ++count; // /1초에 한번씩

        
    }

    return 0;
}