/*
 * @Author: your name
 * @Date: 2021-12-09 20:20:00
 * @LastEditTime: 2021-12-13 13:52:30
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \vsomeip-masterf:\cpp\vsomeip\vsomeip_method\service-method-example.cpp
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include <condition_variable>
#include <vsomeip/vsomeip.hpp>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421
#define SAMPLE_EVENTGROUP_ID 0x001
#define SAMPLE_EVENT_ID 0x002

std::shared_ptr<vsomeip::application> app;

void run()
{
    std::cout << "Starting to notify..." << std::endl;
    std::shared_ptr<vsomeip::payload> its_payload = vsomeip::runtime::get()->create_payload();
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 256; i++)
        {
            vsomeip::byte_t its_data[] = {i};

            its_payload = vsomeip::runtime::get()->create_payload();

            its_payload->set_data(its_data, sizeof(its_data));

            app->notify(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENT_ID, its_payload);

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
}

void on_message(const std::shared_ptr<vsomeip::message> &_request)
{
    std::stringstream ss;
    std::cout << "Mario SERVICE: Starting to send event-data to Client = ["
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_client() << "] "
              << "and [ServiceID.InstanceID.MethodID] = ["
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_service() << "."
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_instance() << "."
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_method() << "]"
              << ss.str() << std::endl;
}

int main()
{

    app = vsomeip::runtime::get()->create_application("Service-Event-Example");

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
    std::thread reciever(run);
    app->start();
}