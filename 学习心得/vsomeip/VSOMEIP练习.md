# VSOMEIP练习

## Method

### 服务端有如下功能：

加法功能int add(int, int);

减法功能int subtract(int, int);

乘法功能int mult(int, int);

除法功能int division(int, int);

### 客户端使用四个功能：

输入4组参数分别对应于四个函数的入参

期望得到四个函数的结果

### 源码

#### service-method-example.cpp

```cpp
#include <iomanip>
#include <iostream>
#include <sstream>

#include <vsomeip/vsomeip.hpp>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421

std::shared_ptr<vsomeip::application> app;
int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int mult(int a, int b)
{
    return a * b;
}
int division(int a, int b)
{
    if (b == 0)
    {
        if (a < 0)
            return INT32_MIN;
        if (a > 0)
            return INT32_MAX;
        if (a == 0)
            return 0;
    }
    return a / b;
}
void on_message(const std::shared_ptr<vsomeip::message> &_request)
{

    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();

    vsomeip::length_t l = its_payload->get_length();

    // Get payload
    std::stringstream ss;
    ss << "The data is: ";
    for (vsomeip::length_t i = 0; i < l; i++)
    {
        ss << std::setw(2) << std::setfill('0') << std::dec
           << (int)*(its_payload->get_data() + i) << " ";
    }

    std::cout << "Mario SERVICE: Received message with [Client/Session] = ["
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_client() << "/"
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_session() << "] "
              << "and [ServiceID.InstanceID.MethodID] = ["
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_service() << "."
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_instance() << "."
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_method() << "]"
              << ss.str() << std::endl;

    vsomeip::method_t method_id = _request->get_method();
    vsomeip::byte_t *its_payload_data = its_payload->get_data();
    int a = its_payload_data[0];
    int b = its_payload_data[1];
    int cnt = its_payload_data[2];
    int res = 0;
    std::string output = "";
    if (SAMPLE_METHOD_ID == method_id)
    {
        res = add(a, b);
        output = "The Result of add function is " + std::to_string(res);
    }
    if (SAMPLE_METHOD_ID + 1 == method_id)
    {
        res = subtract(a, b);
        output = "The Result of subtract function is " + std::to_string(res);
    }
    if (SAMPLE_METHOD_ID + 2 == method_id)
    {
        res = mult(a, b);
        output = "The Result of multi function is " + std::to_string(res);
    }
    if (SAMPLE_METHOD_ID + 3 == method_id)
    {
        res = division(a, b);
        output = "The Result of division function is " + std::to_string(res);
    }

    std::cout << "Mario TEST: " << output << std::endl;

    // Send response
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> my_payload_data;
    my_payload_data.push_back(res);
    my_payload_data.push_back(cnt);
    its_payload->set_data(my_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
}

int main()
{

    app = vsomeip::runtime::get()->create_application("Service-Method-Example");

    app->init();
    //注册加法功能
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID, on_message);
    //注册减法功能
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID + 1, on_message);
    //注册乘法功能
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID + 2, on_message);
    //注册除法功能
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID + 3, on_message);

    app->offer_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);

    app->start();
}
```

#### client-method-example.cpp

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

std::shared_ptr<vsomeip::application> app;
std::mutex mutex;
std::condition_variable condition;
int cnt = 1;
void job1(int a, int b)
{
    std::cout << "No." << cnt << ": job1 with " << std::dec << a << " and " << std::dec << b << std::endl;
    std::shared_ptr<vsomeip::message> request;
    request = vsomeip::runtime::get()->create_request();
    request->set_service(SAMPLE_SERVICE_ID);
    request->set_instance(SAMPLE_INSTANCE_ID);
    request->set_method(SAMPLE_METHOD_ID);

    std::shared_ptr<vsomeip::payload> its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    its_payload_data.push_back(a);
    its_payload_data.push_back(b);
    its_payload_data.push_back(cnt++);
    its_payload->set_data(its_payload_data);
    request->set_payload(its_payload);
    app->send(request);
    
}

void job2(int a, int b)
{
    std::cout << "No." << cnt << ": job2 with " << std::dec << a << " and " << std::dec << b << std::endl;
    std::shared_ptr<vsomeip::message> request;
    request = vsomeip::runtime::get()->create_request();
    request->set_service(SAMPLE_SERVICE_ID);
    request->set_instance(SAMPLE_INSTANCE_ID);
    request->set_method(SAMPLE_METHOD_ID + 1);
    std::shared_ptr<vsomeip::payload> its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    its_payload_data.push_back(a);
    its_payload_data.push_back(b);
    its_payload_data.push_back(cnt++);
    its_payload->set_data(its_payload_data);
    request->set_payload(its_payload);
    app->send(request);
}

void job3(int a, int b)
{
    std::cout << "No." << cnt << ": job3 with " << std::dec << a << " and " << std::dec << b << std::endl;
    std::shared_ptr<vsomeip::message> request;
    request = vsomeip::runtime::get()->create_request();
    request->set_service(SAMPLE_SERVICE_ID);
    request->set_instance(SAMPLE_INSTANCE_ID);
    request->set_method(SAMPLE_METHOD_ID + 2);

    std::shared_ptr<vsomeip::payload> its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    its_payload_data.push_back(a);
    its_payload_data.push_back(b);
    its_payload_data.push_back(cnt++);
    its_payload->set_data(its_payload_data);
    request->set_payload(its_payload);
    app->send(request);
}

void job4(int a, int b)
{
    std::cout << "No." << cnt << ": job4 with " << std::dec << a << " and " << std::dec << b << std::endl;
    std::shared_ptr<vsomeip::message> request;
    request = vsomeip::runtime::get()->create_request();
    request->set_service(SAMPLE_SERVICE_ID);
    request->set_instance(SAMPLE_INSTANCE_ID);
    request->set_method(SAMPLE_METHOD_ID + 3);

    std::shared_ptr<vsomeip::payload> its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    its_payload_data.push_back(a);
    its_payload_data.push_back(b);
    its_payload_data.push_back(cnt++);
    its_payload->set_data(its_payload_data);
    request->set_payload(its_payload);
    app->send(request);
    
}

void run()
{
    std::unique_lock<std::mutex> its_lock(mutex);
    condition.wait(its_lock);

    // Send Request
    job1(20, 10);
    job2(20, 10);
    job3(20, 10);
    job4(20, 10);

    /*job1(100, 0);
    job2(100, 0);
    job3(100, 0);
    job4(100, 0);*/

    /*job1(-100, 0);
    job2(-100, 0);
    job3(-100, 0);
    job4(-100, 0);*/
}

void on_message(const std::shared_ptr<vsomeip::message> &_response)
{

    std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
    vsomeip::length_t l = its_payload->get_length();

    // Get payload
    std::stringstream ss;
    ss << "The data is: ";
    for (vsomeip::length_t i = 0; i < l; i++)
    {
        ss << std::setw(2) << std::setfill('0') << std::dec
           << (int)*(its_payload->get_data() + i) << " ";
    }

    std::stringstream its_message;
    std::cout << "Mario CLIENT: Received message with [Client/Session] = ["
              << std::setw(4) << std::setfill('0') << std::hex << _response->get_client() << "/"
              << std::setw(4) << std::setfill('0') << std::hex << _response->get_session() << "] "
              << "and [ServiceID.InstanceID.MethodID] = ["
              << std::setw(4) << std::setfill('0') << std::hex << _response->get_service() << "."
              << std::setw(4) << std::setfill('0') << std::hex << _response->get_instance() << "."
              << std::setw(4) << std::setfill('0') << std::hex << _response->get_method() << "]"
              << ss.str() << std::endl;

    vsomeip::byte_t *its_payload_data = its_payload->get_data();
    int res = its_payload_data[0];
    int cnt = its_payload_data[1];
    if (_response->get_method() == SAMPLE_METHOD_ID)
        std::cout << "The result of No." << std::dec<< cnt << " job1 is " << std::dec<< res << std::endl;
    if (_response->get_method() == SAMPLE_METHOD_ID + 1)
        std::cout << "The result of No." << std::dec<< cnt << " job2 is " << std::dec<< res << std::endl;
    if (_response->get_method() == SAMPLE_METHOD_ID + 2)
        std::cout << "The result of No." << std::dec<< cnt << " job3 is " << std::dec<< res << std::endl;
    if (_response->get_method() == SAMPLE_METHOD_ID + 3)
        std::cout << "The result of No." << std::dec<< cnt << " job4 is "<< std::dec << res << std::endl;
}

void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available)
{
    std::cout << "CLIENT: Service ["
              << std::setw(4) << std::setfill('0') << std::hex << _service << "." << _instance
              << "] is "
              << (_is_available ? "available." : "NOT available.")
              << std::endl;
    if (_is_available)
    {
        condition.notify_one();
    }
}

int main()
{

    app = vsomeip::runtime::get()->create_application("Client-Method-Example");

    app->init();
    app->register_availability_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, on_availability);
    app->request_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);

    //注册加法功能
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID, on_message);
    //注册减法功能
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID + 1, on_message);
    //注册乘法功能
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID + 2, on_message);
    //注册除法功能
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID + 3, on_message);

    std::thread sender(run);
    app->start();
}
```

### Service和Client在同一PC上运行

```shell
./service-method-example
```

```shell
./client-method-example
```

### Service和Client在不同PC上运行

设置网卡接受多播消息（注意网卡名字如eth0）

```shell
route add -nv 224.224.224.245 dev eth0
```

Service运行在ip:192.168.199.107

```shell
env VSOMEIP_CONFIGURATION=./vsomeip-service-example.json VSOMEIP_APPLICATION_NAME=Service-Method-Example ./service-method-example
```

Client运行在ip:192.168.199.127

```shell
env VSOMEIP_CONFIGURATION=./vsomeip-client-example.json VSOMEIP_APPLICATION_NAME=Client-Method-Example ./client-method-example
```

#### Service端的Json配置文件:vsomeip-service-example.json

```json
{
    "unicast" : "192.168.199.107",
    "logging" :
    { 
        "level" : "debug",
        "console" : "true",
        "file" : { "enable" : "false", "path" : "/tmp/vsomeip.log" },
        "dlt" : "false"
    },
    "applications" : 
    [
        {
            "name" : "Service-Method-Example",
            "id" : "0x1212"
        }
    ],
    "services" :
    [
        {
            "service" : "0x1234",
            "instance" : "0x5678",
            "unreliable" : "30509"
        }
    ],
    "routing" : "Service-Method-Example",
    "service-discovery" :
    {
        "enable" : "true",
        "multicast" : "224.224.224.245",
        "port" : "30490",
        "protocol" : "udp",
        "initial_delay_min" : "10",
        "initial_delay_max" : "100",
        "repetitions_base_delay" : "200",
        "repetitions_max" : "3",
        "ttl" : "3",
        "cyclic_offer_delay" : "2000",
        "request_response_delay" : "1500"
    }
}
```

#### Client端的Json配置文件:vsomeip-client-example.json

注意：Client端网上例子说了好像要设置成routing,但设置成routing会出错，所以就没设成，能正常通信

```json
{
    "unicast" : "192.168.199.127",
    "logging" :
    { 
        "level" : "debug",
        "console" : "true",
        "file" : { "enable" : "false", "path" : "/tmp/vsomeip.log" },
        "dlt" : "false"
    },
    "applications" : 
    [
        {
            "name" : "Client-Method-Example",
            "id" : "0x1313"
        }
    ],
    "service-discovery" :
    {
        "enable" : "true",
        "multicast" : "224.224.224.245",
        "port" : "30490",
        "protocol" : "udp",
        "initial_delay_min" : "10",
        "initial_delay_max" : "100",
        "repetitions_base_delay" : "200",
        "repetitions_max" : "3",
        "ttl" : "3",
        "cyclic_offer_delay" : "2000",
        "request_response_delay" : "1500"
    }
}
```

#### Service端的log

```
2021-11-10 21:29:57.098535 [info] Parsed vsomeip configuration in 0ms
2021-11-10 21:29:57.099815 [info] Using configuration file: "./vsomeip-service-example.json".
2021-11-10 21:29:57.100111 [info] Configuration module loaded.
2021-11-10 21:29:57.100324 [info] Initializing vsomeip application "Service-Method-Example".
2021-11-10 21:29:57.101551 [info] Instantiating routing manager [Host].
2021-11-10 21:29:57.102084 [info] create_local_server Routing endpoint at /tmp/vsomeip-0
2021-11-10 21:29:57.103004 [info] Service Discovery enabled. Trying to load module.
2021-11-10 21:29:57.106883 [info] Service Discovery module loaded.
2021-11-10 21:29:57.107387 [info] Application(Service-Method-Example, 1212) is initialized (11, 100).
2021-11-10 21:29:57.107535 [info] OFFER(1212): [1234.5678:0.0] (true)
2021-11-10 21:29:57.107931 [info] Listening at /tmp/vsomeip-1212
2021-11-10 21:29:57.108079 [info] Starting vsomeip application "Service-Method-Example" (1212) using 2 threads I/O nice 255
2021-11-10 21:29:57.109422 [info] main dispatch thread id from application: 1212 (Service-Method-Example) is: 7f927c517700 TID: 22965
2021-11-10 21:29:57.109422 [info] shutdown thread id from application: 1212 (Service-Method-Example) is: 7f927bd16700 TID: 22966
2021-11-10 21:29:57.109622 [info] Watchdog is disabled!
2021-11-10 21:29:57.111828 [info] io thread id from application: 1212 (Service-Method-Example) is: 7f927e733280 TID: 22964
2021-11-10 21:29:57.113015 [info] io thread id from application: 1212 (Service-Method-Example) is: 7f927ad14700 TID: 22968
2021-11-10 21:29:57.113841 [info] Network interface "wlp6s0" state changed: up
2021-11-10 21:29:57.113163 [info] vSomeIP 3.1.20.3 | (default)
2021-11-10 21:29:57.114151 [info] Route "default route (0.0.0.0/0) if: wlp6s0 gw: 192.168.199.1" state changed: up
2021-11-10 21:29:57.114436 [info] udp_server_endpoint_impl: SO_RCVBUF is: 212992
2021-11-10 21:29:57.114583 [debug] Joining to multicast group 224.224.224.245 from 192.168.199.107
2021-11-10 21:29:57.114694 [info] udp_server_endpoint_impl: SO_RCVBUF (Multicast) is: 212992
2021-11-10 21:29:57.115815 [info] udp_server_endpoint_impl: SO_RCVBUF is: 212992
2021-11-10 21:29:57.115880 [info] SOME/IP routing ready.
2021-11-10 21:29:57.115996 [warning] Route "224.224.224.245/32 if: wlp6s0 gw: n/a" state changed: up
Mario SERVICE: Received message with [Client/Session] = [1313/0001] and [ServiceID.InstanceID.MethodID] = [1234.5678.0421]The data is: 20 10 01 
Mario TEST: The Result of add function is 30
Mario SERVICE: Received message with [Client/Session] = [1313/0002] and [ServiceID.InstanceID.MethodID] = [1234.5678.0422]The data is: 20 10 02 
Mario TEST: The Result of subtract function is 10
Mario SERVICE: Received message with [Client/Session] = [1313/0003] and [ServiceID.InstanceID.MethodID] = [1234.5678.0423]The data is: 20 10 03 
Mario TEST: The Result of multi function is 200
Mario SERVICE: Received message with [Client/Session] = [1313/0004] and [ServiceID.InstanceID.MethodID] = [1234.5678.0424]The data is: 20 10 04 
Mario TEST: The Result of division function is 2
2021-11-10 21:30:07.116475 [info] vSomeIP 3.1.20.3 | (default)
2021-11-10 21:30:08.224525 [warning] Didn't receive a multicast SD message for 2200ms.
2021-11-10 21:30:08.225594 [debug] Leaving the multicast group 224.224.224.245 from 192.168.199.107
2021-11-10 21:30:08.251505 [debug] Joining to multicast group 224.224.224.245 from 192.168.199.107
2021-11-10 21:30:08.252197 [info] udp_server_endpoint_impl: SO_RCVBUF (Multicast) is: 212992
2021-11-10 21:30:11.256130 [warning] Didn't receive a multicast SD message for 2200ms.
2021-11-10 21:30:11.257138 [debug] Leaving the multicast group 224.224.224.245 from 192.168.199.107
2021-11-10 21:30:11.283113 [debug] Joining to multicast group 224.224.224.245 from 192.168.199.107
2021-11-10 21:30:11.283805 [info] udp_server_endpoint_impl: SO_RCVBUF (Multicast) is: 212992

```

#### Client端的log

```
2021-11-10 21:30:06.455851 [info] Parsed vsomeip configuration in 0ms
2021-11-10 21:30:06.456217 [info] Using configuration file: "./vsomeip-client-example.json".
2021-11-10 21:30:06.456294 [info] Configuration module loaded.
2021-11-10 21:30:06.456342 [info] Initializing vsomeip application "Client-Method-Example".
2021-11-10 21:30:06.457714 [info] Instantiating routing manager [Host].
2021-11-10 21:30:06.458452 [info] create_local_server Routing endpoint at /tmp/vsomeip-0
2021-11-10 21:30:06.463002 [info] Service Discovery enabled. Trying to load module.
2021-11-10 21:30:06.466739 [info] Service Discovery module loaded.
2021-11-10 21:30:06.467559 [info] Application(Client-Method-Example, 1313) is initialized (11, 100).
2021-11-10 21:30:06.468732 [info] REQUEST(1313): [1234.5678:255.4294967295]
2021-11-10 21:30:06.471965 [info] Listening at /tmp/vsomeip-1313
2021-11-10 21:30:06.472879 [info] Starting vsomeip application "Client-Method-Example" (1313) using 2 threads I/O nice 255
2021-11-10 21:30:06.474701 [info] Watchdog is disabled!
2021-11-10 21:30:06.475414 [info] io thread id from application: 1313 (Client-Method-Example) is: 7fa00f1aa3c0 TID: 27154
2021-11-10 21:30:06.476325 [info] Network interface "enp0s3" state changed: up
2021-11-10 21:30:06.476926 [info] Route "default route (0.0.0.0/0) if: enp0s3 gw: 192.168.199.1" state changed: up
2021-11-10 21:30:06.477461 [info] udp_server_endpoint_impl: SO_RCVBUF is: 212992
2021-11-10 21:30:06.477836 [debug] Joining to multicast group 224.224.224.245 from 192.168.199.127
2021-11-10 21:30:06.478184 [info] udp_server_endpoint_impl: SO_RCVBUF (Multicast) is: 212992
2021-11-10 21:30:06.482678 [info] SOME/IP routing ready.
2021-11-10 21:30:06.483213 [warning] Route "224.224.224.245/32 if: enp0s3 gw: n/a" state changed: up
2021-11-10 21:30:06.484506 [info] vSomeIP 3.1.20.3 | (default)
2021-11-10 21:30:06.484897 [info] io thread id from application: 1313 (Client-Method-Example) is: 7fa00af8a700 TID: 27159
2021-11-10 21:30:06.485472 [info] shutdown thread id from application: 1313 (Client-Method-Example) is: 7fa00bf8c700 TID: 27157
2021-11-10 21:30:06.485928 [info] main dispatch thread id from application: 1313 (Client-Method-Example) is: 7fa00c78d700 TID: 27156
CLIENT: Service [1234.5678] is NOT available.
2021-11-10 21:30:06.302781 [info] udp_client_endpoint_impl::connect: SO_RCVBUF is: 212992
CLIENT: Service [1234.5678] is available.
No.1: job1 with 20 and 10
No.2: job2 with 20 and 10
No.3: job3 with 20 and 10
No.4: job4 with 20 and 10
Mario CLIENT: Received message with [Client/Session] = [1313/0001] and [ServiceID.InstanceID.MethodID] = [1234.5678.0421]The data is: 30 01 
The result of No.1 job1 is 30
Mario CLIENT: Received message with [Client/Session] = [1313/0002] and [ServiceID.InstanceID.MethodID] = [1234.5678.0422]The data is: 10 02 
The result of No.2 job2 is 10
Mario CLIENT: Received message with [Client/Session] = [1313/0003] and [ServiceID.InstanceID.MethodID] = [1234.5678.0423]The data is: 200 03 
The result of No.3 job3 is 200
Mario CLIENT: Received message with [Client/Session] = [1313/0004] and [ServiceID.InstanceID.MethodID] = [1234.5678.0424]The data is: 02 04 
The result of No.4 job4 is 2
CLIENT: Service [1234.5678] is NOT available.
2021-11-10 21:30:14.919511 [warning] Didn't receive a multicast SD message for 2200ms.
2021-11-10 21:30:14.919911 [debug] Leaving the multicast group 224.224.224.245 from 192.168.199.127
2021-11-10 21:30:14.924576 [debug] Joining to multicast group 224.224.224.245 from 192.168.199.127
2021-11-10 21:30:14.924804 [info] udp_server_endpoint_impl: SO_RCVBUF (Multicast) is: 212992
```

