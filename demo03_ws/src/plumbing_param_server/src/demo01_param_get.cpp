#include "ros/ros.h"

/* 
    演示参数查询
        实现
        ros::NodeHandle
            ros::NodeHandle

        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量


 */

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"get_param_C");

    ros::NodeHandle nh;

    //1.param
    // double radius = nh.param("radius",0.5);
    //2.getParam
    // double radius2 = 0.0;
    // bool result = nh.getParam("radius",radius2);
    //3.getParamCached 与getParam类似，但性能提升
    // bool result = nh.getParamCached("radius",radius2);
    // if(result)
    // {
    //     ROS_INFO("获取半径是：%.2f",radius2);
    // }
    //4.getParamNames
    // std::vector<std::string> names;
    // nh.getParamNames(names);
    // for (auto &&name : names)
    // {
    //     ROS_INFO("得到的名称是：%s",name.c_str());
    // }
    //5.hasParam
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxxxx");
    ROS_INFO("FLAG1 %d",flag1);
    ROS_INFO("FLAG2 %d",flag2);
    //------------------------------------------------------------------------
    
    //ros::param
    // double radius3 = ros::param::param("radius",5);



    return 0;
}
