#include "ros/ros.h"

/* 
    演示删除：
        实现
            ros::NodeHandle
                delparam()
            ros::Parm
                del()


 */

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_del_c");
    ros::NodeHandle nh;
    //删除 NodeHandle
    bool flag = nh.deleteParam("radois");
    if(flag)
        ROS_INFO("删除成功");
    else
        ROS_INFO("删除失败");
    //删除 param
    bool flag2 = ros::param::del("type");
    if(flag2)
        ROS_INFO("删除成功");
    else
        ROS_INFO("删除失败");
    return 0;
}
