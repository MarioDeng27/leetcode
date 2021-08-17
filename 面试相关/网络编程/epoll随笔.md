# epoll随笔

来源：https://zhuanlan.zhihu.com/p/64746509

要参看这本书：深入理解Nginx：模块开发与架构解析(第二版)

## 1. 理解epoll的四个前提要素

1. **网卡会把接收到的数据写入内存**：网络数据通过网线被网卡接收到，并且网卡将数据写入到内存中的某个地址上

2. **OS通过硬件中断知道数据的到来**：网卡向cpu发出一个中断信号，操作系统便能得知有新数据到来，再通过网卡中断程序去处理数据

3. **处于阻塞（等待）状态的进程不占用CPU资源：**这部分要通过操作系统的进程调度的角度来看数据的接收，阻塞是指进程在等待某事件（如接收到网络数据）发生之前的等待状态。阻塞的原理：

   - 工作队列：OS为了实现调度，将进程分为 运行、等待等几种状态。运行状态的进程是可以获得CPU使用权的，即正在执行代码的状态，OS会分时执行各个运行状态下的进程，由于速度很快，看上去就好像是同时执行多个任务

     <img src="https://pic3.zhimg.com/80/v2-2f3b71710f1805669a780a2d634f0626_720w.jpg" alt="img" style="zoom:50%;" />

   - 等待队列：**当进程执行到Socket时，OS会创建一个由文件系统管理的Socket对象，这个Socket对象包含了发送缓冲区（写缓冲区）、接收缓冲区（读缓冲区）、等待队列等成员。等待队列是指向所有需要等待该Socket事件的进程**。当程序执行到recv时，OS将对应的进程A将工作队列移到该Socket的等待队列中（这个等待队列只是对进程A的引用，表示其状态为等待/阻塞状态），所以根据进程调度，CPU会轮流执行另外进程的程序，不会执行A。所以进程A被阻塞后，不会往下执行代码，也不会占用CPU资源

     ![img](https://pic1.zhimg.com/80/v2-1c7a96c8da16f123388e46f88772e6d8_720w.jpg)

   - 唤醒进程：当Socket接收到数据后（网卡将数据写入到内存，产生中断后CPU将数据写入到对应Socket读缓冲区中），OS将该进程从Socket等待队列上放回到工作队列上，状态变成运行状态，继续执行代码，recv可以返回接收到的数据以及长度。

4. **内核接受网络数据全过程**：（进程由于调用recv进入阻塞后）

   1. 网卡收到来自网线的网络数据

   2. 网卡将网络数据写入内存

   3. 网卡内存写入数据完毕产生中断让CPU知道有数据到达，CPU执行对应的中断处理程序：

   4. OS将网络数据写入到对应Socket的接收缓冲区

   5. OS将该进程唤醒并将它放入工作队列中

      ![img](https://pic4.zhimg.com/80/v2-696b131cae434f2a0b5ab4d6353864af_720w.jpg)

      ![img](https://pic3.zhimg.com/80/v2-3e1d0a82cdc86f03343994f48d938922_720w.jpg)

   注意：思考题

   1. OS如何知道网络数据对应哪个Socket？

      答：Socket是由一个IP地址和端口号定义的，所以每个Socket对应一个端口号，而网络数据包中包含了IP和端口i西南西，内核可以通过端口号找到对应的Socket（这部分OS维护了一张端口号到Socket的索引结构，以便快速读取）

   2. 如何同时监视多个Socket数据？

      答：通过多路复用技术：Select、poll、epoll



## 2. 多路复用

#### 1. 同时监视多个Socket的简单方法：select

**来源**：服务端需要管理多个客户端连接，而recv只能监视单个socket，故**假如能够预先传入一个socket列表，如果列表中的socket都没有数据，挂起进程，直到有一个socket收到数据（接收缓冲区有数据），唤醒进程**

```C
int s = socket(AF_INET, SOCK_STREAM, 0);  
bind(s, ...)
listen(s, ...)

int fds[] =  存放需要监听的socket

while(1){
    int n = select(..., fds, ...)
    for(int i=0; i < fds.count; i++){
        if(FD_ISSET(fds[i], ...)){
            //fds[i]的数据处理
        }
    }
}
```



**select流程**：假设程序同时监视sock1、sock2、sock3三个socket，那么在调用select之后，OS会把进程A分别加入到这三个socket的等待队列中，进程A进入阻塞状态（等待三个socket中任何一个或多个可以读为止）

![img](https://pic4.zhimg.com/80/v2-0cccb4976f8f2c2f8107f2b3a5bc46b3_720w.jpg)



当任何一个socket收到数据后，中断程序将唤醒进程。

![img](https://pic1.zhimg.com/80/v2-85dba5430f3c439e4647ea4d97ba54fc_720w.jpg)

所谓的唤醒进程其实就是将进程从所有的Socket的等待队列中移除，加入到工作队列中。

![img](https://pic4.zhimg.com/80/v2-a86b203b8d955466fff34211d965d9eb_720w.jpg)

经过这些步骤后，进程A被唤醒，它明白有socket接收到数据了，但它不知道到底是哪一个，所以程序会遍历一遍socket列表，这样就可以得到就绪的socket了。



**缺点：**

1. <font color='red'>每次调用select都需要将进程加入到所有监视socket的等待队列</font>，每次唤醒都需要从每个队列中移除。这里涉及了两次遍历，<font color='red'>而且每次都要将整个fds列表传递给内核</font>，有一定的开销。正是因为遍历操作开销大，出于效率的考量，才会规定select的最大监视数量，默认只能监视1024个socket（如果需要修改这个值需要重新编译内核）

2. 进程被唤醒后，<font color='red'>程序并不知道哪些socket收到数据，还需要遍历一次</font>

#### 2. epoll的设计思路

**措施一：功能分离**（针对上述缺点1中的每次都要将整个fds列表传递给内核）

select低效的原因之一是将“维护等待队列”和“阻塞进程”两个步骤合二为一，每次调用select都需要先维护等待队列再阻塞进程，然而绝大多数应用场景中，要监视的socket相对固定，并不是每次都要修改。而epoll先用epoll_ctl维护等待队列，再调用epoll_wait阻塞进程，效率就能得到提升。

<img src="https://pic2.zhimg.com/80/v2-5ce040484bbe61df5b484730c4cf56cd_720w.jpg" alt="img" style="zoom:50%;" />

epoll的用法：先用epoll_create创建一个epoll对象epfd，再通过epoll_ctl将需要监视的socket添加到epfd中，最后调用epoll_wait等待数据

```c
int s = socket(AF_INET, SOCK_STREAM, 0);   
bind(s, ...)
listen(s, ...)

int epfd = epoll_create(...);
epoll_ctl(epfd, ...); //将所有需要监听的socket添加到epfd中

while(1){
    int n = epoll_wait(...)
    for(接收到数据的socket){
        //处理
    }
}
```



**措施二：就绪列表**（针对上述缺点2中的不确定哪些socket收到数据，需要重新遍历）

调用select返回之后，程序知道有socket收到数据，但只能一个一个遍历，如果内核维护一个“就绪列表”，引用收到数据的socket，这样就能避免遍历。

![img](https://pic4.zhimg.com/80/v2-5c552b74772d8dbc7287864999e32c4f_720w.jpg)

假如程序只监听3个socket，而socket2和socket3收到数据后被rdlist（就绪列表）所引用。当进程被唤醒后，只要获取rdlist的内容，就能够知道哪些socket收到数据。



#### 3. epoll的原理和流程

**创建epoll对象**：某个进程调用epoll_create方法时，内核会创建一个eventpoll对象（也就是程序中epfd所代表的对象）。eventpoll对象也是文件系统中的一员，和socket一样，它也有等待队列。

![img](https://pic4.zhimg.com/80/v2-e3467895734a9d97f0af3c7bf875aaeb_720w.jpg)

创建一个代表该epoll的eventpoll对象是必须的，因为从上述可知，内核要维护“就绪队列”等数据，而“就绪队列可以作为eventpoll的成员”



**维护<font color='red'>监视列表</font>**：创建eventpoll对象后，可以用epoll_ctl添加或删除所要监视的socket，如果通过cepoll_ctl添加sock1、sock2和sock3的监视，内核会将eventpoll添加到这三个socket的等待队列中。

![img](https://pic2.zhimg.com/80/v2-b49bb08a6a1b7159073b71c4d6591185_720w.jpg)

当socket收到数据后，中断程序会给eventpoll的“<font color='red'>就绪列表</font>”添加socket引用。如果sock2和sock3收到数据后，中断程序让rdlist引用这两个socket。

![img](https://pic1.zhimg.com/80/v2-18b89b221d5db3b5456ab6a0f6dc5784_720w.jpg)

eventpoll对象相当于是socket和进程之间的中介，socket的数据接收并不直接影响进程，而是通过改变eventpoll的就绪列表来改变进程状态。

当程序执行到epoll_wait时，如果rdlist已经引用了socket，那么epoll_wait直接返回，如果rdlist为空，阻塞进程。

**阻塞和唤醒进程**

假设计算机中正在运行进程A，在某时刻进程A运行到了epoll_wait语句。如下图所示，内核会将进程A放入eventpoll的等待队列中，阻塞进程。

![img](https://pic1.zhimg.com/80/v2-90632d0dc3ded7f91379b848ab53974c_720w.jpg)

当socket接收到数据，中断程序一方面修改rdlist，另一方面唤醒eventpoll等待队列中的进程，进程A再次进入运行状态（如下图）。通过rdlist，进程A可以知道哪些socket可以进行读或者写。

<img src="https://pic4.zhimg.com/80/v2-40bd5825e27cf49b7fd9a59dfcbe4d6f_720w.jpg" alt="img" style="zoom: 80%;" />



#### **4. epoll的实现细节**

问题1：**eventpoll的数据结构**是什么样子？

问题2：eventpoll对应的就绪队列应该使用什么数据结构？

问题3：eventpoll使用什么数据结构来管理通过epoll_ctl添加或删除的socket？



**主要关注rdlist和rbr**

![img](https://pic4.zhimg.com/80/v2-e63254878f67751dcc07a25b93f974bb_720w.jpg)

**就绪列表的数据结构**

就序列表**引用**就绪的socket，所以它要快速的插入数据

程序可能要随时调用epoll_ctl添加监视socket，也可能随时删除，当删除时，若该socket已经存放在就绪列表中，它也应该被移除。所以就绪列表应是一种能够快速插入和删除的数据结构。双向链表就是这样一种数据结构，epoll使用双向链表来实现就绪队列（对应上图的rdllist）。



**索引结构**：epoll_ctl中的添加和删除主要是在维护这个索引结构，并且还需要进行搜索以避免重复插入

epoll将”维护监视队列“和进程阻塞分离，也就意味着需要有个数据结构来保存监视的socket。这个结构能够方便的进行添加和删除，还要便于搜索。红黑树是一种自平衡二叉查找树，搜索、插入、删除的时间复杂度是O(log(N))。epoll使用了红黑树作为索引结构（对应上图的rbr）



> <font color='cornflowerblue'>ps：因为操作系统要兼顾多种功能，以及由更多需要保存的数据，rdlist并非直接引用socket，而是通过epitem间接引用，红黑树的节点也是epitem对象。同样，文件系统也并非直接引用着socket。为方便理解，本文中省略了一些间接结构。</font>





#### 5. 结论

epoll在select和poll（poll和select基本一样，有少量改进）的基础引入了eventpoll作为中间层，使用了先进的数据结构，是一种高效的多路复用技术。

![img](https://pic2.zhimg.com/80/v2-14e0536d872474b0851b62572b732e39_720w.jpg)
