/*
 * @Author: your name
 * @Date: 2021-12-09 20:20:00
 * @LastEditTime: 2021-12-09 22:31:16
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \vsomeip-masterf:\cpp\vsomeip\vsomeip_method\service-method-example.cpp
 */

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