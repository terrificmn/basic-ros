#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& masg) {
    std::cout << "I heard:" << msg->data.c_str() << std::endl;
}

int main(int argc, char **argv) {
    ros::int(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    ros::spin();

    return 0;
}