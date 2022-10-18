#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

/*          订阅方：1.计算son1与son2的相对关系，2.计算son1中的某一个座标点在son2中的坐标值

            需求1：换算出 turtle1 相对于 turtle2的关系
            需求2：计算角速度和线速度并发布
 */


int main(int argc, char *argv[])
{
    // 2.编码，初始化，NodeHandle；
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tfs_sub");
    ros::NodeHandle nh;
    //             3.创建订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    //创建发布对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);



    //             4.编写解析逻辑

    ros::Rate rate(10);
    while (ros::ok())
    {
        try
        {
            //1.计算son1和son2的相对关系

            geometry_msgs::TransformStamped son1Toson2 = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
             ROS_INFO("son1 相对于 son2 的信息：父级：%s,子级：%s 偏移量(%.2f,%.2f,%.2f)",
                        son1Toson2.header.frame_id.c_str(),
                        son1Toson2.child_frame_id.c_str(),
                        son1Toson2.transform.translation.x,
                        son1Toson2.transform.translation.y,
                        son1Toson2.transform.translation.z
                        );
            geometry_msgs::Twist twist;
            /* 
                组织速度，只需要设置线速度X与角速度Z
                X=系数*开方（y^2+x^2）
                Z=系数*反正切（对边，邻边）
             */
            twist.linear.x = 0.5 * sqrt(pow(son1Toson2.transform.translation.x,2)+pow(son1Toson2.transform.translation.y,2));
            twist.linear.z = 4 * atan2(son1Toson2.transform.translation.y,son1Toson2.transform.translation.x);

            pub.publish(twist);

        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示：%s",e.what());
        }
        

        rate.sleep();
        ros::spinOnce();
    }
    
    //             5.spinOnce()


    return 0;
}
