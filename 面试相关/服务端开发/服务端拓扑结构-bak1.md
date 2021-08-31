# 服务端拓扑结构

## 一、 服务端组内通信框架

1. 相关进程（每个进程可被看成是一种服务）：
   - Gas: 服务端组内核心的服务，有计算统计数据功能
   - Gateway：路由服务，Gac和Gas通过Gateway做中转
   - Master：管理服务的服务，Master用于注册管理组内其他的服务
   - Database：数据存储服务
   - HttpProxy：Http相关的代理服务
   - InnerSwitcher：内部总线服务，中间桥梁，帮助组内其他服务进行信息交互
   - OuterSwitcher：外部总线服务，类似内部，但可以通过它将其他服务端组连接起来，进行全局的信息交互
   - ...
   
2. 为什么要InnerSwitcher？
   - 如果没有InnerSwitcher，服务端组内的进程要管理多个连接，比如，Master要和Gas，Login，Database等连接通信，每个连接管理的代码都得重写并且很难写对。一个完善的连接至少包括以下几个方面：
     - 监听/连接失败的处理，包括记日志，定时重连等
     - 连接检查，需要有个注册的过程，两端必须是期望的进程，不然可能出现连错地址但迟迟没有发现的情况
     - 心跳检测，如果对方进程死循环或者adb调试挂起，能过够及早发现
     - 状态同步，比如gas需要在全部模块启动好以后，master才应该让它创建场景
     - 状态广播，比如playershop和gas并不直连，但是gas需要直到playershop是否存活这个状态，这就需要相关进程自己做状态广播。
   - 如果没有InnerSwitcher，组内部的连接数是N的平方，且当多添加一个进程（服务）就得添加这个进程与其他组内进程的连接管理代码，连接数变为N+1的平方
   - 如果有InnerSwitcher，服务端组内的进程只需管理自己与InnerSwitcher的连接，通过InnerSwitcher可以将消息转发到目标进程
   - 如果有InnerSwitcher，组内部的连接数是N，当多添加一个进程，连接数只是变为N+1，即添加了新进程与InnerSwitcher的连接
   - 如果有InnerSwitcher，可以在基础上很方便做寻址、广播、组播、服务发现这类功能
   
3. 为什么Gac与Gas不直连，要通过Gateway做中转？https://blog.csdn.net/larry_zeng1/article/details/78436765

   - ~~不让Gac干扰服务内部的通信，如Gac和Gateway可以用enet，服务器进程之间走tcp~~
   - ~~分担Gas网络流量的压力，Gas和Gateway内网千兆网通信，而Gateway这种无重状态的服务很容易横向扩展~~
   - ~~避免设计上的一些问题，如：切Gas时不用切连接，保持原来和Gateway连接即可~~
   - 作为网络通信的中转站，负责维护将内网和外网隔离开，使外部无法直接访问内部服务器，保障内网服务器的安全，一定程度上减少外挂的攻击。
   - 网关服务器负责解析数据包、加解密、超时处理和一定逻辑处理，这样可以提前过滤掉错误包和非法数据包。
   - 客户端程序只需建立与网关服务器的连接即可进入游戏，无需与其它游戏服务器同时建立多条连接，节省了客户端和服务器程序的网络资源开销。

4. 为什么Gas与Gateway在组内是直连？

   - 出于延时考虑，Gas和Gac要通过Gateway进行交互，已经多增加了一层数据的接收和转发，如果再通过InnerSwitcher又会多一次。
   - Gac从外部OuterSwitcher与某个组内的Gas进行交互，消息路径(简单猜测)：Gac->OuterSwitcher->InnerSwitcher->Gateway->Gas
   
5. 服务端高度模块化

   大厅服务端将登录、用户信息、房间信息、日常任务、道具、银行、比赛、排行、活动、网站等11个功能拆分成11个独立的服务端子模块，模块之间不会相互影响，即使某模块出错也不会影响全局，提高了服务端的稳定性；与子模块平行的新功能可以自由新增挂载，扩展性强。


## 二、 服务端组间通信框架

组间只是多了一层OuterSwitcher，它是组内的某个进程比如Gas向外发送至Gac或者其他组的Gas，则信息路径为Gas->Gateway->InnerSwitcher->OuterSwitcher(本组)->（多个OuterSwitcher）->OuterSwitcher(其他组)->InnerSwitcher->Gateway->Gas
