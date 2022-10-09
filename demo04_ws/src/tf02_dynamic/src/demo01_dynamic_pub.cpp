#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"
/* 

    需求：实现发布方，订阅乌龟的位姿信息
        准备：
            话题： /turtle1/pose
            消息: /turtlesim/Pose

        流程：
            1.包含头文件
            2.设置编码，初始化，NodeHandle
            3.创建订阅对象
            4.回调处理订阅的消息：
            5.spin()



 */
void doPose(const turtlesim::Pose::ConstPtr& pose){
    //获取位姿信息，换算成坐标相对关系，并发布
    //a.创建发布对象
    static tf2_ros::TransformBroadcaster pub;
    //b租住被发布的数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = "turtle1";
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;
    //四元数设置
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);

    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    //发布。
    pub.sendTransform(ts);
}

int main(int argc, char *argv[])
{
    //         2.设置编码，初始化，NodeHandle
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;
    //         3.创建订阅对象
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);
    //         4.回调处理订阅的消息：

    //         5.spin()
    ros::spin();
    return 0;
}
