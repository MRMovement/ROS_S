#include "ros/ros.h"
#include "plumbing_srrver_client/AddInts.h"


/* 
    客户端：提交两个整数，并处理响应的结果。

    1.导入头文件
    2.初始化ROS节点
    3.创建ros节点句柄
    4.创建一个客户端对象
    5.提交请求并产生响应

    实现参数的动态提交：
        1.格式： rosrun xxx xxx 12 34
        2.节点执行时，需要获取命令中的参数，并组织进 requset
    
    问题：先启动客户端会有异常
    需求：启动客户端后挂起，等到服务等启动
    解决：ros中内置了相关函数，这些函数可以让客户端启动后挂起，等待客户端启动
 */

int main(int argc, char *argv[])
{
    //优化实现，获取命令中的参数
        if(argc!=3)
        return 1;



    setlocale(LC_ALL,"");
//     2.初始化ROS节点
        ros::init(argc,argv,"daBao");
//     3.创建ros节点句柄
        ros::NodeHandle nh;
//     4.创建一个客户端对象
        ros::ServiceClient client = nh.serviceClient<plumbing_srrver_client::AddInts>("addInts");
//     5.提交请求并产生响应
        //5.1组织请求
        plumbing_srrver_client::AddInts ai;
        ai.request.num1 = atoi(argv[1]);
        ai.request.num2 = atoi(argv[2]);
        //5.2处理响应
        //此处调用判断服务器状态的函数
        //函数一
        //client.waitForExistence();
        //函数二
        ros::service::waitForService("addInts");
        bool flag = client.call(ai);
        if(flag)
        ROS_INFO("处理数据是：%d",ai.response);
        else
        ROS_INFO("处理失败");

    
    return 0;
}
