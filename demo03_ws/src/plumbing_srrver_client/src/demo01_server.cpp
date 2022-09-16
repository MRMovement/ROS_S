#include "ros/ros.h"
#include "plumbing_srrver_client/AddInts.h"

/* 
    服务端实现：解析客户端提交的数据，再运算后产生响应
    1.导入头文件
    2.初始化ROS节点
    3.创建ros节点句柄
    4.创建一个服务对象
    5.处理请求并产生响应
    6.spin（）


 */

bool doNums(plumbing_srrver_client::AddInts::Request &request,
            plumbing_srrver_client::AddInts::Response &response){
        //处理请求
        int num1 = request.num1;
        int num2 = request.num2;
        ROS_INFO("解析出来的数是：%d, %d",num1,num2);

        //组织响应
        int sum = num1+num2;
        response.sum = sum;
        ROS_INFO("求和结果是：%d",sum);

    return true;
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化ROS节点
    ros::init(argc,argv,"heishui");
    // 3.创建ros节点句柄
    ros::NodeHandle nh;
    // 4.创建一个服务对象
    ros::ServiceServer server = nh.advertiseService("addInts",doNums);
    // 5.处理请求并产生响应

    // 6.spin（）
    ros::spin();
    return 0;
}
