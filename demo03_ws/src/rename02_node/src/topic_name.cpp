#include "ros/ros.h"
#include "std_msgs/String.h"



int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");
    // ros::NodeHandle nh;
    //全局话题
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/xxx/ybb",1000);
    //相对话题，对版节点
    // ros::Publisher pub = nh.advertise<std_msgs::String>("ggg/ybb",1000);
    //私有话题
    
    ros::NodeHandle nh("~");

    ros::Publisher pub = nh.advertise<std_msgs::String>("ggg/ybb",1000);
    
    while (ros::ok())
    {
        
    }
  
    return 0;
}
