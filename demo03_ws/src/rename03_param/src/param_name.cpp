#include "ros/ros.h"



int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;
    //全局
    ros::param::set("/raduis",1);
    //相对
    ros::param::set("raduis",10);
    //私有
    ros::param::set("~raduis",100);
    //全局
    nh.setParam("/ccnd",100000);
    //相对
    nh.setParam("ccnd",1000);
    //私有
    ros::NodeHandle nh2("~");
    nh2.setParam("ccnd",10000);
    return 0;
}
