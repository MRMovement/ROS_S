#include "ros/ros.h"

/* 
    需求实现参数的新增与修改
    需求：首先设置机器人的共享数据，类型，半径（0.15）
        再修改半径（0.2）
    实现：
        ros::NodeHandle()
            setParam()
        ros::param()
            set()

 */

int main(int argc, char *argv[])
{
    //初始化
    ros::init(argc,argv,"set_param_c");
    //创建节点句柄
    ros::NodeHandle nh;
    //参数增
    //1.使用nh
    nh.setParam("type","xiaohuang");
    nh.setParam("radius",0.15);


    //2 使用param
    ros::param::set("type_parrm","xiaobai");
    ros::param::set("radius_param",0.15);

    //参数改
        //1.nh
        nh.setParam("radius",0.2);
        //2,param
        ros::param::set("radius_param",0.2);




    return 0;
}
