#include "ros/ros.h"
#include "plubing_test/hello.h"

namespace hello_ns{
    
void Myhello::run(){
    ROS_INFO("run函数运行中....");

}

}



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_head");
    hello_ns::Myhello myHello;
    myHello.run();



    return 0;
}
