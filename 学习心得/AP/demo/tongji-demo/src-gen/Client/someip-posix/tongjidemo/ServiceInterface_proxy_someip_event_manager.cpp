/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Client\someip-posix/tongjidemo/ServiceInterface_proxy_someip_event_manager.cpp
 *        \brief  SOME/IP proxy event handling for events and field notifications of service 'ServiceInterface'
 *
 *      \details
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_someip
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "tongjidemo/ServiceInterface_proxy_someip_event_manager.h"
#include <string>
#include <tuple>
#include <utility>
#include "tongjidemo/ServiceInterface.h"
#include "tongjidemo/ServiceInterface_proxy_someip_binding.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {

/* ---- Event 'addInfo' ------------------------------------------- */

ServiceInterfaceProxySomeIpEventManageraddInfo::ServiceInterfaceProxySomeIpEventManageraddInfo(
    ServiceInterfaceProxySomeIpBinding& proxy_binding)
    : ProxyImplEvent(),
      proxy_binding_(proxy_binding),
      service_event_(nullptr),
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "ServiceInterfaceProxySomeIpEventManageraddInfo") {}

bool ServiceInterfaceProxySomeIpEventManageraddInfo::Subscribe(::amsr::socal::internal::ProxyEventBase* service_event,
                                                                    ::ara::com::EventCacheUpdatePolicy cache_policy,
                                                                    std::size_t cache_size) {
  bool is_subscription_successful{false};

  // Check for validity of service_event. (This is passed by ara::com, so it is ok to assert its correctness)
  assert((service_event != nullptr) && "No event frontend for subscription state handling given.");

  if (!subscribed_) {
    policy_ = cache_policy;    // Update Policy
    cache_size_ = cache_size;  // Update Cache Size
    service_event_ = service_event;
    // set subscribed_ to true before calling SubscribeEvent, as HandleEventSubscriptionStateUpdate might then be called
    // at any moment even before SubscribeEvent is returned.
    subscribed_ = true;
    proxy_binding_.SubscribeEvent(event_id_, this);
    is_subscription_successful = true;
  } else {
    logger_.LogWarn([](ara::log::LogStream& s) { s << "ServiceInterface: addInfo is already subscribed. Subscription ignored."; },
                    __func__, __LINE__);
  }
  return is_subscription_successful;
}

void ServiceInterfaceProxySomeIpEventManageraddInfo::Unsubscribe() {
  if (subscribed_) {
    std::lock_guard<std::mutex> guard(sample_cache_lock_);
    proxy_binding_.UnsubscribeEvent(event_id_);

    // Clean the cache to save memory and to make sure that cache size is correct by next subscription.
    invisible_sample_cache_.clear();

    subscribed_ = false;
  }
}

/*!
 * \brief Deserializer for argument 'data' (AsrPath: /AUTOSAR/StdTypes/uint32_t)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class ServiceInterfaceaddInfodataDeserializer {
 public:
  /*!
   * \brief Constructor for ServiceInterfaceaddInfodataDeserializer
   * \param deserializer Used root deserializer
   */
  explicit ServiceInterfaceaddInfodataDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "ServiceInterfaceaddInfodataDeserializer") {}

/*!
 * \brief Deserialize argument 'data'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<std::uint32_t, bool> Deserialize() {
  return Deserializedata<RootDeserializer>(deserializer_);
}

private:
/*!
 * \brief CppImplDataTypeValue deserialization for element 'data' (/AUTOSAR/StdTypes/uint32_t)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<std::uint32_t, bool> Deserializedata(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialization result of element 'data'
  bool deserialization_ok{true};

std::uint32_t data{};
  ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data{parent};
deserialization_ok &= deserializer__data.PopFront(data) > 0U;
  return std::make_pair(data, deserialization_ok);
}

  /*!
   * \brief Root deserializer
   */
  RootDeserializer* deserializer_;
  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};



void ServiceInterfaceProxySomeIpEventManageraddInfo::HandleEventNotification(RootDeserializerAlias&& deserializer) {
  // shortening
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialize event sample
  ServiceInterfaceaddInfodataDeserializer<typename std::decay<decltype(deserializer)>::type> arg_data_deserializer{&deserializer};
std::pair<std::uint32_t, bool> ret_data{arg_data_deserializer.Deserialize()};

  // Deserialization successful?
  if(ret_data.second) {
    logger_.LogDebug([](ara::log::LogStream& s) {
                      s << "Received and deserialized sample for event 'addInfo'."; },
                      __func__, __LINE__);

    // Store data in invisible sample cache
    this->push(ret_data.first);

    if (subscribed_) {
      // If subscribed_, then service_event_ must have been set.
      assert((service_event_ != nullptr) && "No event frontend for subscription state handling given.");

      // Notify EventReceiveHandler
      service_event_->Notify();
    }
    /* else silently discard the event. */
  } else {
    logger_.LogError([](ara::log::LogStream& s) { s << "Deserialization error occurred for event 'addInfo'."; },
                      __func__, __LINE__);
  }
}

void ServiceInterfaceProxySomeIpEventManageraddInfo::HandleBufferOverflow(
    const amsr::someip_protocol::internal::SomeIpMessageHeader& header) {
  const amsr::someip_protocol::internal::SessionId session_id{header.session_id_};
  logger_.LogDebug([&session_id](ara::log::LogStream& s) { s << "(addInfo): session ID: " << session_id; },
                    __func__, __LINE__);

  if (subscribed_) {
    logger_.LogError([&header](ara::log::LogStream& s) {
                      s << "Event message is larger than the configured receive buffer - ("
                        << ara::log::LogHex16{header.service_id_} << "): "
                        << "method ID: " << header.method_id_ << ", session ID: " << header.session_id_
                        << ", original message body length: " << header.length_;
},
__func__, __LINE__);
  }
}

void ServiceInterfaceProxySomeIpEventManageraddInfo::HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state) {
  if (subscribed_) {
    // If subscribed_, then service_event_ must have been set.
    assert((service_event_ != nullptr) && "No event frontend for subscription state handling given.");

    // Notify the subscription handler.
    service_event_->NotifySubscriptionStateUpdate(state);
  } else {
    // service_event_ might have already been unset after Unsubscribe call.
    if (state != ::ara::com::SubscriptionState::kNotSubscribed) {
      logger_.LogError([](ara::log::LogStream& s) {
      s << "Routing of event subscription state update failed. No subscription found for event 'addInfo'"; },
      __func__, __LINE__);
    }
  }
}

/* ---- Field notifier 'addResult' ------------------------------------------- */

ServiceInterfaceProxySomeIpFieldNotifieraddResult::ServiceInterfaceProxySomeIpFieldNotifieraddResult(
    ServiceInterfaceProxySomeIpBinding& proxy_binding)
    : ProxyImplEvent(),
      proxy_binding_(proxy_binding),
      service_event_(nullptr),
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "ServiceInterfaceProxySomeIpFieldNotifieraddResult") {}

bool ServiceInterfaceProxySomeIpFieldNotifieraddResult::Subscribe(::amsr::socal::internal::ProxyEventBase* service_event,
                                                                    ::ara::com::EventCacheUpdatePolicy cache_policy,
                                                                    std::size_t cache_size) {
  bool is_subscription_successful{false};

  // Check for validity of service_event. (This is passed by ara::com, so it is ok to assert its correctness)
  assert((service_event != nullptr) && "No event frontend for subscription state handling given.");

  if (!subscribed_) {
    policy_ = cache_policy;    // Update Policy
    cache_size_ = cache_size;  // Update Cache Size
    service_event_ = service_event;
    // set subscribed_ to true before calling SubscribeEvent, as HandleEventSubscriptionStateUpdate might then be called
    // at any moment even before SubscribeEvent is returned.
    subscribed_ = true;
    proxy_binding_.SubscribeEvent(event_id_, this);
    is_subscription_successful = true;
  } else {
    logger_.LogWarn([](ara::log::LogStream& s) { s << "ServiceInterface: addResult is already subscribed. Subscription ignored."; },
                    __func__, __LINE__);
  }
  return is_subscription_successful;
}

void ServiceInterfaceProxySomeIpFieldNotifieraddResult::Unsubscribe() {
  if (subscribed_) {
    std::lock_guard<std::mutex> guard(sample_cache_lock_);
    proxy_binding_.UnsubscribeEvent(event_id_);

    // Clean the cache to save memory and to make sure that cache size is correct by next subscription.
    invisible_sample_cache_.clear();

    subscribed_ = false;
  }
}

/*!
 * \brief Deserializer for argument 'data' (AsrPath: /AUTOSAR/StdTypes/uint32_t)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class ServiceInterfaceaddResultdataDeserializer {
 public:
  /*!
   * \brief Constructor for ServiceInterfaceaddResultdataDeserializer
   * \param deserializer Used root deserializer
   */
  explicit ServiceInterfaceaddResultdataDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "ServiceInterfaceaddResultdataDeserializer") {}

/*!
 * \brief Deserialize argument 'data'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<std::uint32_t, bool> Deserialize() {
  return Deserializedata<RootDeserializer>(deserializer_);
}

private:
/*!
 * \brief CppImplDataTypeValue deserialization for element 'data' (/AUTOSAR/StdTypes/uint32_t)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<std::uint32_t, bool> Deserializedata(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialization result of element 'data'
  bool deserialization_ok{true};

std::uint32_t data{};
  ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__data{parent};
deserialization_ok &= deserializer__data.PopFront(data) > 0U;
  return std::make_pair(data, deserialization_ok);
}

  /*!
   * \brief Root deserializer
   */
  RootDeserializer* deserializer_;
  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};



void ServiceInterfaceProxySomeIpFieldNotifieraddResult::HandleEventNotification(RootDeserializerAlias&& deserializer) {
  // shortening
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialize event sample
  ServiceInterfaceaddResultdataDeserializer<typename std::decay<decltype(deserializer)>::type> arg_data_deserializer{&deserializer};
std::pair<std::uint32_t, bool> ret_data{arg_data_deserializer.Deserialize()};

  // Deserialization successful?
  if(ret_data.second) {
    logger_.LogDebug([](ara::log::LogStream& s) {
                      s << "Received and deserialized sample for event 'addResult'."; },
                      __func__, __LINE__);

    // Store data in invisible sample cache
    this->push(ret_data.first);

    if (subscribed_) {
      // If subscribed_, then service_event_ must have been set.
      assert((service_event_ != nullptr) && "No event frontend for subscription state handling given.");

      // Notify EventReceiveHandler
      service_event_->Notify();
    }
    /* else silently discard the event. */
  } else {
    logger_.LogError([](ara::log::LogStream& s) { s << "Deserialization error occurred for event 'addResult'."; },
                      __func__, __LINE__);
  }
}

void ServiceInterfaceProxySomeIpFieldNotifieraddResult::HandleBufferOverflow(
    const amsr::someip_protocol::internal::SomeIpMessageHeader& header) {
  const amsr::someip_protocol::internal::SessionId session_id{header.session_id_};
  logger_.LogDebug([&session_id](ara::log::LogStream& s) { s << "(addResult): session ID: " << session_id; },
                    __func__, __LINE__);

  if (subscribed_) {
    logger_.LogError([&header](ara::log::LogStream& s) {
                      s << "Event message is larger than the configured receive buffer - ("
                        << ara::log::LogHex16{header.service_id_} << "): "
                        << "method ID: " << header.method_id_ << ", session ID: " << header.session_id_
                        << ", original message body length: " << header.length_;
},
__func__, __LINE__);
  }
}

void ServiceInterfaceProxySomeIpFieldNotifieraddResult::HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state) {
  if (subscribed_) {
    // If subscribed_, then service_event_ must have been set.
    assert((service_event_ != nullptr) && "No event frontend for subscription state handling given.");

    // Notify the subscription handler.
    service_event_->NotifySubscriptionStateUpdate(state);
  } else {
    // service_event_ might have already been unset after Unsubscribe call.
    if (state != ::ara::com::SubscriptionState::kNotSubscribed) {
      logger_.LogError([](ara::log::LogStream& s) {
      s << "Routing of event subscription state update failed. No subscription found for event 'addResult'"; },
      __func__, __LINE__);
    }
  }
}


}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

