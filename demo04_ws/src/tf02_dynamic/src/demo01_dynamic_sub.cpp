#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

/* 
    订阅发布的坐标系相对关系，传入一个坐标点，调用tf实现转换

    流程：
        1.包含头文件
        2.编码，初始化，NodeHandle（必需）
        3.创建订阅对象；-->订阅坐标系相对关系
        4.组织一个坐标点数据
        5.转换算法，需要调用tf内置实现
        6.输出结果
 */

int main(int argc, char *argv[])
{
    //     2.编码，初始化，NodeHandle（必需）
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;
    //     3.创建订阅对象；-->订阅坐标系相对关系
    //创建一个buf缓存，再创建监听对象，监听对象可以将订阅数据存入buf
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    //     4.组织一个坐标点数据
    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "turtle1";
    ps.header.stamp = ros::Time(0.0);
    ps.point.x =2.0;
    ps.point.y =3.0;
    ps.point.z =5.0;

    ros::Duration(2).sleep();
    //     5.转换算法，需要调用tf内置实现
    ros::Rate rate(10);
    while (ros::ok())
    {
        //核心代码实现
        geometry_msgs::PointStamped ps_out;
        ps_out = buffer.transform(ps,"world");


    //     6.输出结果
        ROS_INFO("转换后的坐标值:(%.2f,%.2f,%.2f)，参考坐标系:%s",
                                ps_out.point.x,
                                ps_out.point.y,
                                ps_out.point.z,
                                ps_out.header.frame_id.c_str()
                                );


        rate.sleep();
        ros::spinOnce();
    }


    return 0;
}
