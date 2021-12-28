1.初始条件
SIP/build下必须有各个模块的build信息，否则工程编译缺少依赖

2.编译
新建build目录
进入build目录执行 cmake .. -DSIP_Dir:PATH="/home/lpz/SIP/CBD2000241" -Dinstall_Dir:PATH="/home/lpz/install"
两个参数一个填SIP目录，另一个填安装位置
cmake .. -DSIP_Dir:PATH="/home/mario/SIP/CBD2000241_D00" -Dinstall_Dir:PATH="/home/mario/eclipse-workspace/without-em/simple-demo-v1/install"

cmake .. -DSIP_Dir:PATH="/SIP/CBD2000241" -Dinstall_Dir:PATH="/SIP/workspace/tongji-demo/install"
3.将已有的someipd程序拷入安装位置

4.编译程序
在build中执行make install以编译安装程序

5.配置网络
sudo ifconfig lo:0 192.168.7.2
sudo ip link set lo multicast on
sudo ip route add ff01::0/16 dev lo:0

6. 启动client、server和someip守护进程
/install/opt/someipd_posix下执行./bin/someipd_posix -c ./etc/someipd-posix.json启动someip deamon
/install/opt/saicDemoServer下执行./bin/saicDemoServer启动saicDemoServer
/install/opt/saicDemoClient下执行./bin/saicDemoClient启动saicDemoClient
