#include "ros/ros.h"
#include "turtlesim/Spawn.h"
/* 
    需求:向服务端发送请求,生成一只新乌龟
        话题: /spawn
        消息: turtlesim/Spawnd
        1.包含头文件
        2.初始化ros节点
        3.创建ros节点句柄
        4.创建客户端对象
        5.组织数据并发送
        6.处理响应


 */



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //     2.初始化ros节点
    ros::init(argc,argv,"service_call");
    //     3.创建ros节点句柄
    ros::NodeHandle nh;
    //     4.创建客户端对象
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("spawn");
    //     5.组织数据并发送
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
    ros::service::waitForService("/spawm");
    bool flag = client.call(spawn);
    if (flag)
    {
        ROS_INFO("乌龟生成成功,新乌龟叫:%d",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("生成失败");
    }
    //     6.处理响应

    
    return 0;
}
