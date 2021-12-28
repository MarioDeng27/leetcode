/*
 * @Author: your name
 * @Date: 2021-12-09 20:58:34
 * @LastEditTime: 2021-12-20 18:27:47
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \vsomeip-masterf:\cpp\vsomeip\vsomeip_method\client-method-example.cpp
 */
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
    //job2(20, 10);
    //job3(20, 10);
    //job4(20, 10);

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
