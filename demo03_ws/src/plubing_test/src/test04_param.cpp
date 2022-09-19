#include "ros/ros.h"

/* 
    需求：修改服务器中turtlesim背景色相关的参数

    1.初始化ROS节点
    2.不一定需要创建节点句柄（和后续API有关）
    3.修改参数



 */


int main(int argc, char *argv[])
{
    // 1.初始化ROS节点
    ros::init(argc,argv,"chang_bgcolor");
    // 2.不一定需要创建节点句柄（和后续API有关）

    // 3.修改参数
    ros::param::set("/turtlesim/background_r",0);
    ros::param::set("/turtlesim/background_g",0);
    ros::param::set("/turtlesim/background_b",0);

    
    return 0;
}
