[中文翻译]: https://blog.csdn.net/ckr__/article/details/109134174
[英文原文]: https://blog.csdn.net/u011086209/article/details/100152421?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Ede

### 注意：

因为官方vsomeip的版本升级为3，有局部地方和该博客不太一致，修改部分为：

1. cmakelist.txt: 将vsomeip变为vsomeip3，将find_package(vsome ...)删除

2. 源代码：两个example中的include <vsomeip>路径改成\#include <vsomeip/vsomeip.hpp>

3. send方法的使用，删除最后一个bool参数
4. client的源码中request_event的使用参考最新版本的3的方法调用
5. service的源码中的offer_event的使用参考最新版本的3的方法调用

### 源码：

#### cmakelists.txt

```cmake
PROJECT(vSomeIPExample LANGUAGES CXX C)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set (CMAKE_CXX_FLAGS "-g -std=c++0x")

find_package( Boost 1.55 COMPONENTS system thread log REQUIRED )

include_directories (
    ${Boost_INCLUDE_DIR}
    ${VSOMEIP_INCLUDE_DIRS}
)

add_executable(service-example service-example.cpp)
add_executable(client-example client-example.cpp)
target_link_libraries(service-example vsomeip3 ${Boost_LIBRARIES})
target_link_libraries(client-example vsomeip3 ${Boost_LIBRARIES})

```



#### client-example

```cpp
#include <iomanip>
#include <iostream>
#include <sstream>

#include <condition_variable>
#include <thread>

#include <vsomeip/vsomeip.hpp>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421
#define SAMPLE_EVENTGROUP_ID 0x001
#define SAMPLE_EVENT_ID 0x002

std::shared_ptr< vsomeip::application > app;
std::mutex mutex;
std::condition_variable condition;

void run() {
    std::unique_lock<std::mutex> its_lock(mutex);
    condition.wait(its_lock);

    std::set<vsomeip::eventgroup_t> its_groups;
    its_groups.insert(SAMPLE_EVENTGROUP_ID);
    app->request_event(
                SAMPLE_SERVICE_ID,
                SAMPLE_INSTANCE_ID,
                SAMPLE_EVENT_ID,
                its_groups,
                vsomeip::event_type_e::ET_FIELD);
    app->subscribe(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENTGROUP_ID);

    // Send Request
    std::shared_ptr< vsomeip::message > request;
    request = vsomeip::runtime::get()->create_request();
    request->set_service(SAMPLE_SERVICE_ID);
    request->set_instance(SAMPLE_INSTANCE_ID);
    request->set_method(SAMPLE_METHOD_ID);

    std::shared_ptr< vsomeip::payload > its_payload = vsomeip::runtime::get()->create_payload();
    std::vector< vsomeip::byte_t > its_payload_data;
    for (vsomeip::byte_t i=0; i<10; i++) {
    its_payload_data.push_back(i % 256);
    }
    its_payload->set_data(its_payload_data);
    request->set_payload(its_payload);
    app->send(request);
}

void on_message(const std::shared_ptr<vsomeip::message> &_response) {
    
    std::stringstream its_message;
    its_message << "CLIENT: received a notification for event ["
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_service() << "."
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_instance() << "."
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_method() << "] to Client/Session ["
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_client() << "/"
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_session()
            << "] = ";
    std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
    its_message << "(" << std::dec << its_payload->get_length() << ") ";
    for (uint32_t i = 0; i < its_payload->get_length(); ++i)
        its_message << std::hex << std::setw(2) << std::setfill('0')
            << (int) its_payload->get_data()[i] << " ";
    std::cout << its_message.str() << std::endl;

    // std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
    // vsomeip::length_t l = its_payload->get_length();

    // // Get payload
    // std::stringstream ss;
    // for (vsomeip::length_t i=0; i<l; i++) {
    //     ss << std::setw(2) << std::setfill('0') << std::hex
    //         << (int)*(its_payload->get_data()+i) << " ";
    // }

    // std::cout << "CLIENT: Received message with Client/Session ["
    //           << std::setw(4) << std::setfill('0') << std::hex << _response->get_client() << "/"
    //           << std::setw(4) << std::setfill('0') << std::hex << _response->get_session() << "] "
    //           << ss.str() << std::endl;
}
    

void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
    std::cout << "CLIENT: Service ["
              << std::setw(4) << std::setfill('0') << std::hex << _service << "." << _instance
              << "] is "
              << (_is_available ? "available." : "NOT available.")
              << std::endl;
    if (_is_available) { condition.notify_one(); }
}

int main() {

    app = vsomeip::runtime::get()->create_application("Hello");
    
    app->init();
    app->register_availability_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, on_availability);
    app->request_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
    // app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID, on_message);
    app->register_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD, on_message);
    std::thread sender(run);
    app->start();
}

```

#### service-example

```cpp
/*
 * @Author: your name
 * @Date: 2021-12-08 21:17:58
 * @LastEditTime: 2021-12-08 22:38:55
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \vsomeip-masterf:\cpp\vsomeip\vsomeip_demo\service-example.cpp
 */
#include <iomanip>
#include <iostream>
#include <sstream>

#include <vsomeip/vsomeip.hpp>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421
#define SAMPLE_EVENTGROUP_ID 0x001
#define SAMPLE_EVENT_ID 0x002

std::shared_ptr< vsomeip::application > app;

void on_message(const std::shared_ptr<vsomeip::message> &_request) {

    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();

    // Get payload
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++) {
       ss << std::setw(2) << std::setfill('0') << std::hex
          << (int)*(its_payload->get_data()+i) << " ";
    }

    std::cout << "SERVICE: Received message with Client/Session ["
        << std::setw(4) << std::setfill('0') << std::hex << _request->get_client() << "/"
        << std::setw(4) << std::setfill('0') << std::hex << _request->get_session() << "] "
        << ss.str() << std::endl;

    // Send response
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    for (int i=9; i>=0; i--) {
        its_payload_data.push_back(i % 256);
    }
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);

    // Notify event
    const vsomeip::byte_t its_data[] = { 0x10 };
	its_payload = vsomeip::runtime::get()->create_payload();
	its_payload->set_data(its_data, sizeof(its_data));
    app->notify(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENT_ID, its_payload);
}

int main() {

    app = vsomeip::runtime::get()->create_application("World");
    
	std::set<vsomeip::eventgroup_t> its_groups;
	its_groups.insert(SAMPLE_EVENTGROUP_ID);

    app->init();
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID, on_message);
    app->offer_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
    app->offer_event(
                SAMPLE_SERVICE_ID,
                SAMPLE_INSTANCE_ID,
                SAMPLE_EVENT_ID,
                its_groups,
                vsomeip::event_type_e::ET_FIELD, std::chrono::milliseconds::zero(),
                false, true, nullptr, vsomeip::reliability_type_e::RT_UNKNOWN);
    app->start();
}
```

### 编译

在存放源码和cmakelists的目录下：

1. cmake .
2. make
3. ./service
4. ./client

### 运行日志

#### client-example

2021-11-08 22:49:14.884907 [info] Parsed vsomeip configuration in 0ms
2021-11-08 22:49:14.885536 [info] Configuration module loaded.
2021-11-08 22:49:14.885669 [info] Initializing vsomeip application "Hello".
2021-11-08 22:49:14.886103 [info] Instantiating routing manager [<u>Host</u>].
2021-11-08 22:49:14.886377 [info] create_local_server Routing endpoint at /tmp/vsomeip-0
2021-11-08 22:49:14.886801 [info] Service Discovery enabled. Trying to load module.
2021-11-08 22:49:14.888751 [info] Service Discovery module loaded.
2021-11-08 22:49:14.894132 [info] Application(<u>Hello, 1000</u>) is initialized (11, 100).
2021-11-08 22:49:14.894970 [info] REQUEST(1000): [1234.5678:255.4294967295]
2021-11-08 22:49:14.896091 [info] Listening at /tmp/vsomeip-1000
2021-11-08 22:49:14.897294 [info] Starting vsomeip application "Hello" (1000) using 2 threads I/O nice 255
2021-11-08 22:49:14.899806 [info] Watchdog is disabled!
2021-11-08 22:49:14.901365 [info] io thread id from application: 1000 (Hello) is: 7f756a2133c0 TID: 7981
2021-11-08 22:49:14.902895 [info] vSomeIP 3.1.20.3 | (default)
2021-11-08 22:49:14.904011 [info] Network interface "lo" state changed: up
2021-11-08 22:49:14.905563 [info] shutdown thread id from application: 1000 (Hello) is: 7f7566fed700 TID: 7984
2021-11-08 22:49:14.906463 [info] io thread id from application: 1000 (Hello) is: 7f7565feb700 TID: 7986
2021-11-08 22:49:14.907251 [info] main dispatch thread id from application: 1000 (Hello) is: 7f75677ee700 TID: 7983
CLIENT: Service [1234.5678] is NOT available.
2021-11-08 22:49:24.904099 [info] vSomeIP 3.1.20.3 | (default)
2021-11-08 22:49:24.164903 [info] Application/Client 1001 is registering.
2021-11-08 22:49:24.166304 [info] <u>Client [1000] is connecting to [1001] at /tmp/vsomeip-1001</u>
2021-11-08 22:49:24.168682 [info] REGISTERED_ACK(1001)
2021-11-08 22:49:24.170525 [info] OFFER(1001): [1234.5678:0.0] (true)
2021-11-08 22:49:24.171216 [info] Port configuration missing for [1234.5678]. Service is internal.
CLIENT: Service [1234.5678] is available.
2021-11-08 22:49:24.173500 [info] REGISTER EVENT(1000): [1234.5678.0002:is_provider=false]
2021-11-08 22:49:24.174154 [info] SUBSCRIBE(1000): [1234.5678.0001:ffff:0]
2021-11-08 22:49:24.177537 [info] SUBSCRIBE ACK(1001): [1234.5678.0001.ffff]
CLIENT: received a notification for event [1234.5678.0421] to Client/Session [1000/0001] = (10) 09 08 07 06 05 04 03 02 01 00 
CLIENT: received a notification for event [1234.5678.0002] to Client/Session [0000/0001] = (1) 10 



#### service-example

2021-11-08 22:49:24.152864 [info] Parsed vsomeip configuration in 0ms
2021-11-08 22:49:24.153476 [info] Configuration module loaded.
2021-11-08 22:49:24.153564 [info] Initializing vsomeip application "World".
2021-11-08 22:49:24.153738 [info] Instantiating routing manager [<u>Proxy</u>].
2021-11-08 22:49:24.153877 [info] Client [ffff] is connecting to [0] at /tmp/vsomeip-0
2021-11-08 22:49:24.154030 [info] Application(<u>World, ffff</u>) is initialized (11, 100).
2021-11-08 22:49:24.154346 [info] Starting vsomeip application "World" (ffff) using 2 threads I/O nice 255
2021-11-08 22:49:24.157225 [info] io thread id from application: ffff (World) is: 7fc4aa14e280 TID: 7987
2021-11-08 22:49:24.163255 [info] Listening at <u>/tmp/vsomeip-1001</u>
2021-11-08 22:49:24.164113 [info] Client 1001 (World) successfully connected to routing  ~> registering..
2021-11-08 22:49:24.167845 [info] Application/Client 1001 (World) is registered.
2021-11-08 22:49:24.169651 [info] REGISTER EVENT(1001): [1234.5678.0002:is_provider=1]
2021-11-08 22:49:24.175832 [info] Client [1001] is connecting to [1000] at /tmp/vsomeip-1000
2021-11-08 22:49:24.178413 [info] notify_one_unlocked: Notifying 2 to client 1000 failed. Event payload not set!
2021-11-08 22:49:24.179091 [info] SUBSCRIBE(1000): [1234.5678.0001:ffff:0]
2021-11-08 22:49:24.179912 [info] shutdown thread id from application: 1001 (World) is: 7fc4a797c700 TID: 7989
2021-11-08 22:49:24.180852 [info] main dispatch thread id from application: 1001 (World) is: 7fc4a817d700 TID: 7988
SERVICE: Received message with Client/Session [1000/0001] 00 01 02 03 04 05 06 07 08 09 
2021-11-08 22:49:24.185123 [info] io thread id from application: 1001 (World) is: 7fc4a717b700 TID: 7990