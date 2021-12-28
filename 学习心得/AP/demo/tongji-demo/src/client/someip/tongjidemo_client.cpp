/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  tongjidemo_client.cpp
 *        \brief  Main entry point of the tongjiDemoClient, used for testing the  service.
 *
 *      \details  -
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "tongjidemo_client.h"
#include "ara/core/instance_specifier.h"
#include "vac/container/string_literals.h"

using vac::container::literals::operator""_sv;


namespace someip {

std::atomic<bool> tongjiDemoClient::server_found{false};
std::shared_ptr<tongjidemo::proxy::ServiceInterfaceProxy> tongjiDemoClient::tongjidemo_service_proxy;
std::atomic<bool> tongjiDemoClient::add_event_received{false};


ara::log::Logger& tongjiDemoClient::GetLogger() {
  static ara::log::Logger& logger{ara::log::CreateLogger("TJCC", "Context for tongji demo client")};
  return logger;
}

void tongjiDemoClient::FindService() {
  // Search for Service. When a calculatorService instance is found, the function FindServiceHandler gets
  // called
  GetLogger().LogInfo() << "Searching for Service";
  ara::core::InstanceSpecifier const tongji_demo_client_port{
	  "Client/RootSwComponentPrototype/RPort_ServiceInterface"_sv};
  ara::com::FindServiceHandle find_service_handle =
		  tongjidemo::proxy::ServiceInterfaceProxy::StartFindService(FindServiceHandler,
				  tongji_demo_client_port);

  // Wait until calculatorSerice is found
  while (!server_found.load(std::memory_order_seq_cst)) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  // Stop searching for further services
  tongjidemo::proxy::ServiceInterfaceProxy::StopFindService(find_service_handle);
}


ara::core::Future<tongjidemo::proxy::methods::add::Output> tongjiDemoClient::CallAdd(
    std::uint32_t num1, std::uint32_t num2) {
  auto add_future = tongjiDemoClient::tongjidemo_service_proxy->add(num1, num2);
  return add_future;
}

void tongjiDemoClient::addInfoHandler(void) { GetLogger().LogError() << "Division by zero!"; }

void tongjiDemoClient::addResultHandler(void) {
  // Check if new events are placed into the local cache
  if (tongjidemo_service_proxy->addResult.Update()) {
    GetLogger().LogInfo() << "Last valid add result is: "
                          << **(tongjidemo_service_proxy->addResult.GetCachedSamples().begin());
    add_event_received = true;
  }
}

void tongjiDemoClient::SubscribeToEvents() {
  // Subscribe to events and set handlers
	tongjidemo_service_proxy->addInfo.SetReceiveHandler(
      []() { addInfoHandler(); });
	tongjidemo_service_proxy->addInfo.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN,
                                                                             1);

    // Subscribe to addResult field (notify event)
  tongjidemo_service_proxy->addResult.SetReceiveHandler([]() { addResultHandler(); });
  tongjidemo_service_proxy->addResult.Subscribe(ara::com::EventCacheUpdatePolicy::kLastN, 1);
}

void tongjiDemoClient::UnsubscribeToEvents() {
  // Unsubscribe from divisionByZero event
	tongjidemo_service_proxy->addInfo.Unsubscribe();
  // Unsubscribe from divideResult field notify event
	tongjidemo_service_proxy->addResult.Unsubscribe();
	tongjidemo_service_proxy.reset();
}

void tongjiDemoClient::FindServiceHandler(
    ara::com::ServiceHandleContainer<tongjidemo::proxy::ServiceInterfaceProxy::HandleType>
        tongjiDemo_services) {
  if (tongjiDemo_services.size() == 0) {
    GetLogger().LogInfo() << "No Service instance found";
    return;
  } else if (tongjiDemo_services.size() == 1) {
    GetLogger().LogInfo() << "Found one Service instance";
    // Get proxy instance
    tongjidemo_service_proxy =
        std::make_shared<tongjidemo::proxy::ServiceInterfaceProxy>(tongjiDemo_services[0]);
    server_found.store(true);
  } else {
    // The example doesn't handle this case
    GetLogger().LogInfo() << "Found multiple instances of Service";
  }
}

void tongjiDemoClient::Initialize(std::string cfg_path_) {
  ara::com::Runtime::getInstance().Initialize(cfg_path_);
}

}  // namespace someip
