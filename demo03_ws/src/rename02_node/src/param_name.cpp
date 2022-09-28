#include "ros/ros.h"






int main(int argc, char *argv[])
{
    //全局
    ros::param::set("/raduis",1);
    //相对
    ros::param::set("raduis",10);
    //私有
    ros::param::set("~raduis",100);



    return 0;
}
