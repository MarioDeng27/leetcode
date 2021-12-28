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
/**        \file  Client\someip-posix/\tongjidemo/ServiceInterface_proxy_someip_event_manager.h
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

#ifndef CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_EVENT_MANAGER_H_
#define CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_EVENT_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <mutex>
#include "com-common/internal/logging/ara_com_logging.h"
#include "socal/internal/proxy_event.h"
#include "socal/internal/proxy_impl_event.h"
#include "someip-protocol/internal/marshalling.h"
#include "someip_binding/internal/e2e_marshalling.h"
#include "someip_binding/internal/service_proxy_someip_event_interface.h"
#include "someip_daemon_client/internal/someip_daemon_client.h"
#include "tongjidemo/serviceinterface_common.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {


// Forward-declaration for back-reference
class ServiceInterfaceProxySomeIpBinding;


/*!
 * \brief SOME/IP Proxy event manager for event 'addInfo'.
 * \details Handles event subscriptions and notification deserialization.
 * \remark generated
 */
class ServiceInterfaceProxySomeIpEventManageraddInfo final : public amsr::someip_binding::internal::ServiceProxySomeIpEventInterface,
                                                            public ::amsr::socal::internal::ProxyImplEvent<std::uint32_t> {
 public:

  /*!
   * \brief Constructor
   * \param proxy_binding Reference to the SOME/IP proxy binding used for event subscription handling.
   */
  explicit ServiceInterfaceProxySomeIpEventManageraddInfo(ServiceInterfaceProxySomeIpBinding& proxy_binding);

  /*!
   * \brief Subscribe to the event 'addInfo'
   * \param service_event Related frontend event object. Used for notification handling
   * \param cache_policy Update policy of the event cache
   * \param cache_size Size limit of the event cache
   * \return true if subcription is successful, otherwise false.
   * \threadsafe FALSE When used with same proxy instance on same event.
   */
  bool Subscribe(::amsr::socal::internal::ProxyEventBase* service_event, ::ara::com::EventCacheUpdatePolicy cache_policy,
                 std::size_t cache_size);

  /*!
   * \brief Unsubscribe from the event 'addInfo'
   * \threadsafe FALSE When used with same proxy instance on same event.
   */
  void Unsubscribe();

  /*!
   * \brief Type-alias for shortening.
   */
  using RootDeserializerAlias = amsr::com_common::internal::serialization::Deserializer<amsr::someip_protocol::internal::serialization::BEPayloadNoLengthFieldPolicy>;

  /*!
   * \brief Handle a received event notification
   * \param deserializer Root deserializer containing the payload.
   * \trace SPEC-5951451
   * \trace SPEC-5951312
   */
  void HandleEventNotification(RootDeserializerAlias&& deserializer) override;

  /*!
   * \brief Receive buffer overflow handler for event notifications
   * \param header Deserialized SOME/IP header
   */
  void HandleBufferOverflow(const amsr::someip_protocol::internal::SomeIpMessageHeader& header) override;

  /*!
   * \brief Handle an update of the subscription state of the event
   * \param state the updated event subscription state
   */
  void HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state) override;

  /*!
   * \brief SOME/IP event identifier for this event.
   */
  static constexpr amsr::someip_protocol::internal::EventId event_id_{0x83E8U};

 private:
  /*!
   * \brief Subscription flag. True if the event is subscribed, false otherwise.
   */
  bool subscribed_{false};

  /*!
   * \brief Proxy binding used for event subscription handling
   */
  ServiceInterfaceProxySomeIpBinding& proxy_binding_;

  /*!
   * \brief The related frontend service event used to notify about new events.
   */
  ::amsr::socal::internal::ProxyEventBase* service_event_;

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};


/*!
 * \brief SOME/IP Proxy event manager for event 'addResult'.
 * \details Handles event subscriptions and notification deserialization.
 * \remark generated
 */
class ServiceInterfaceProxySomeIpFieldNotifieraddResult final : public amsr::someip_binding::internal::ServiceProxySomeIpEventInterface,
                                                            public ::amsr::socal::internal::ProxyImplEvent<std::uint32_t> {
 public:

  /*!
   * \brief Constructor
   * \param proxy_binding Reference to the SOME/IP proxy binding used for event subscription handling.
   */
  explicit ServiceInterfaceProxySomeIpFieldNotifieraddResult(ServiceInterfaceProxySomeIpBinding& proxy_binding);

  /*!
   * \brief Subscribe to the event 'addResult'
   * \param service_event Related frontend event object. Used for notification handling
   * \param cache_policy Update policy of the event cache
   * \param cache_size Size limit of the event cache
   * \return true if subcription is successful, otherwise false.
   * \threadsafe FALSE When used with same proxy instance on same event.
   */
  bool Subscribe(::amsr::socal::internal::ProxyEventBase* service_event, ::ara::com::EventCacheUpdatePolicy cache_policy,
                 std::size_t cache_size);

  /*!
   * \brief Unsubscribe from the event 'addResult'
   * \threadsafe FALSE When used with same proxy instance on same event.
   */
  void Unsubscribe();

  /*!
   * \brief Type-alias for shortening.
   */
  using RootDeserializerAlias = amsr::com_common::internal::serialization::Deserializer<amsr::someip_protocol::internal::serialization::BEPayloadNoLengthFieldPolicy>;

  /*!
   * \brief Handle a received event notification
   * \param deserializer Root deserializer containing the payload.
   * \trace SPEC-5951451
   * \trace SPEC-5951312
   */
  void HandleEventNotification(RootDeserializerAlias&& deserializer) override;

  /*!
   * \brief Receive buffer overflow handler for event notifications
   * \param header Deserialized SOME/IP header
   */
  void HandleBufferOverflow(const amsr::someip_protocol::internal::SomeIpMessageHeader& header) override;

  /*!
   * \brief Handle an update of the subscription state of the event
   * \param state the updated event subscription state
   */
  void HandleEventSubscriptionStateUpdate(::ara::com::SubscriptionState state) override;

  /*!
   * \brief SOME/IP event identifier for this event.
   */
  static constexpr amsr::someip_protocol::internal::EventId event_id_{0x83E9U};

 private:
  /*!
   * \brief Subscription flag. True if the event is subscribed, false otherwise.
   */
  bool subscribed_{false};

  /*!
   * \brief Proxy binding used for event subscription handling
   */
  ServiceInterfaceProxySomeIpBinding& proxy_binding_;

  /*!
   * \brief The related frontend service event used to notify about new events.
   */
  ::amsr::socal::internal::ProxyEventBase* service_event_;

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};


}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

#endif  // CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_EVENT_MANAGER_H_

