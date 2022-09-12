#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc, char *argv[])
{
    /*
        1.包含头文件
          ROS中文本类型 ---> std_msgs/String.h
        2.初始化ros节点

        3，创建节点句柄
        4.创建发布者对象
        5.编写发布逻辑并发布数据
    
    */
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"erGouzi");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);//（话题，缓冲长度）
    //先创建发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(10);
    //设置编号
    int count =0;
    //编译循环
    ros::Duration(3).sleep();
    while (ros::ok())
    {
        count++;
        // msg.data = "hello";
        // 实现字符串并接
        std::stringstream ss;
        ss << "hello --->" << count;

        msg.data= ss.str();

        pub.publish(msg);
        //添加日志：
        ROS_INFO("发布的数据：%s",ss.str().c_str());
        rate.sleep();

    }
    

    return 0;
}
