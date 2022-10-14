#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"
/* 
            需求：使用 rosbag 向磁盘写出数据


            1.导包
            2，初始化
            3.创建rosbag对象
            4.打开文件流
            5.写数据
            6.关闭文件流

 */



int main(int argc, char *argv[])
{
    
        setlocale(LC_ALL,"");
            // 2，初始化
            ros::init(argc,argv,"bag_write");
            ros::NodeHandle nh;
            // 3.创建rosbag对象
            rosbag::Bag bag;
            // 4.打开文件流
            bag.open("hello.bag",rosbag::BagMode::Write);
            // 5.写数据
            std_msgs::String msg;
            msg.data = "hello xxx";
            //话题，时间厝，消息
            bag.write("/chatter",ros::Time::now(),msg);

            // 6.关闭文件流
            bag.close();




    return 0;
}
