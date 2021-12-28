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
/**        \file  Client\someip-posix/\tongjidemo/ServiceInterface_proxy_someip_binding.h
 *        \brief  SOME/IP binding of service proxy for service 'ServiceInterface'
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

#ifndef CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_BINDING_H_
#define CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <map>
#include <memory>
#include <tuple>
#include "com-common/internal/logging/ara_com_logging.h"
#include "someip_binding/internal/aracom_someip_binding_client_manager_interface.h"
#include "someip_binding/internal/aracom_someip_proxy_interface.h"
#include "someip_binding/internal/service_proxy_someip_event_interface.h"
#include "tongjidemo/ServiceInterface_proxy_internal.h"
#include "tongjidemo/ServiceInterface_proxy_someip_event_manager.h"
#include "tongjidemo/ServiceInterface_proxy_someip_methods.h"
#include "tongjidemo/serviceinterface_proxy.h"
#include "tongjidemo/serviceinterface_proxy_resource_manager.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {


/*!
 * \brief SOME/IP proxy binding of Service 'ServiceInterface'.
 * \details Handles serialization and deserialization of all method calls, events, etc.
 * \remark generated
 */
class ServiceInterfaceProxySomeIpBinding final : public tongjidemo::internal::ServiceInterfaceProxyImplInterface,
                                                            public amsr::someip_binding::internal::AraComSomeIpProxyInterface,
                                                            public std::enable_shared_from_this<ServiceInterfaceProxySomeIpBinding> {
 public:
  /*!
   * \brief Generated SOME/IP related service ID.
   */
  static constexpr amsr::someip_protocol::internal::ServiceId kServiceId{0x64U};

  /*!
   * \brief SOME/IP major version of this service interface deployment.
   */
  static constexpr amsr::someip_protocol::internal::MajorVersion kMajorVersion{1U};

  /*!
   * \brief Constructor
   * \param instance_id SOME/IP instance identifier to be used
   * \param someip_binding_client_manager Reference to the related SOME/IP transport binding manager
   * \param resource_manager Reference to service proxy specific resource manager
   */
  ServiceInterfaceProxySomeIpBinding(const amsr::someip_protocol::internal::InstanceId instance_id,
                                                      amsr::someip_binding::internal::AraComSomeIpBindingClientManagerInterface& someip_binding_client_manager,
                                                      resources::ServiceInterfaceProxyResourceManager& resource_manager);

  /*!
   * \brief Destructor.
   */
  virtual ~ServiceInterfaceProxySomeIpBinding() = default;

  /*!
   * \brief Requests the proxy-binding instance in the AraComSomeIpBinding.
   */
  void Initialize() override;

  /*!
   * \brief Releases the proxy-binding instance in the AraComSomeIpBinding.
   */
  void DeInitialize() override;

  /*!
   * \brief Get the ProxyId this ProxyImplInterface can handle.
   * \returns The ProxyId this ProxyImplInterface can handle.
   */
  ::amsr::socal::internal::ProxyId GetProxyId() const override { return proxy::ServiceInterfaceProxy::GetProxyIdStatic(); }

  /*!
   * \brief Receive handler for method responses.
   * \details At the point of this method call from AraComSomeIpBinding, we only have to dispatch method id and session
   * id and look in the correct pending request container, to serve the promise.
   * \throws std::runtime_error exception is set in the promise and then thrown when future.get() is called if the deserialization fails.
   *
   * \error ::ara::com::ComErrc::service_not_available is set in the promise and then thrown when future.get() is called if SOME/IP return code was kUnknownService
   *
   * \param header The deserialized SOME/IP header for direct access.
   * \param deserializer Root deserializer containing the bytestream to deserialize.
   */
  void HandleMethodResponse(const amsr::someip_protocol::internal::SomeIpMessageHeader& header,
                            amsr::someip_binding::internal::RootDeserializerAlias&& deserializer) override;

  /*!
   * \brief Receive handler for event notifications.
   * \param header The deserialized SOME/IP header for direct access.
   * \param deserializer Root deserializer containing the bytestream to deserialize.
   *
   * \trace SPEC-4980079
   */
  void HandleEventNotification(const amsr::someip_protocol::internal::SomeIpMessageHeader& header,
                               amsr::someip_binding::internal::RootDeserializerAlias&& deserializer) override;

  /*!
   * \brief Handle an update of the subscription state of the event
   * \param event_id The event identifier
   * \param state The updated event subscription state
   */
  void HandleEventSubscriptionStateUpdate(const amsr::someip_protocol::internal::EventId event_id, const ::ara::com::SubscriptionState state) override;

  /*!
   * \brief Receive buffer overflow handler for method responses.
   *
   * \param header SOME/IP header.
   */
  void HandleMethodResponseBufferOverflow(const amsr::someip_protocol::internal::SomeIpMessageHeader& header) override;

  /*!
   * \brief Receive buffer overflow handler for event notifications.
   *
   * \param header SOME/IP header.
   */
  void HandleEventNotificationBufferOverflow(const amsr::someip_protocol::internal::SomeIpMessageHeader& header) override;

  /*!
   * \brief Forward a prepared packet to the AraComSomeIpBinding.
   *
   * \param packet the serialized packet from the method.
   *
   * \return true if the transmission has been started and false otherwise.
   */
  bool SendMethodRequest(amsr::com_common::internal::memory::MemoryBufferPtr packet);

  /*!
   * \brief Subscribe to an event
   * \param event_id The SOME/IP event ID to subscribe to
   * \param event_manager The related event manager instance subscribing to the event
   *
   * \throws ::ara::com::InternalComException If SOME/IP daemon is not running (errc: backend_not_available).
   */
  void SubscribeEvent(const amsr::someip_protocol::internal::EventId event_id,
                      amsr::someip_binding::internal::ServiceProxySomeIpEventInterface* event_manager);

  /*!
   * \brief Unsubscribe from an event
   * \param event_id The SOME/IP event ID to unsubscribe from
   *
   * \throws ::ara::com::InternalComException If SOME/IP daemon is not running (errc: backend_not_available).
   */
  void UnsubscribeEvent(const amsr::someip_protocol::internal::EventId event_id);

  /*!
   * \brief Getter for accessing the SOME/IP binding.
   */
  amsr::someip_binding::internal::AraComSomeIpBindingClientManagerInterface& GetBinding() { return someip_binding_client_manager_; }

  /*!
   * \brief Getter for the client id, that was assigned on construction of this object.
   */
  amsr::someip_protocol::internal::ClientId GetClientId() const { return client_id_; }

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  ara::core::Future<proxy::methods::add::Output> Methodadd(const std::uint32_t& num1, const std::uint32_t& num2) override {
    // Build struct with all input arguments
    ::tongjidemo::internal::methods::add::Input input_struct{num1, num2};
    return method_add_.HandleMethodRequest(input_struct);
  }

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Get the event manager object for event 'addInfo'
   */
  ServiceInterfaceProxySomeIpEventManageraddInfo* GetEventManageraddInfo() override {
    return &event_manager_addInfo_;
  }

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /* ---- Field 'addResult' ---- */
  /*!
   * \brief Get the field notifier object for field 'addResult'.
   */
  ServiceInterfaceProxySomeIpFieldNotifieraddResult* GetFieldNotifieraddResult() override { return &field_notifier_addResult_; }

  /*!
   * \brief Realized getter for the field 'addResult' on SOME/IP level.
   * \return a future object
   */
  ara::core::Future<proxy::fields::addResult::FieldType> FieldaddResultMethodGet() override {
    ::tongjidemo::internal::fields::addResultGet::Input input_struct{};
    return field_manager_addResult_get_.HandleMethodRequest(input_struct);
  }

  /*!
   * \brief Realized setter for the field 'addResult' on SOME/IP level.
   * \param value Field value of type uint32_t
   * \return a future object that contains the value after the promise is served.
   */
  ara::core::Future<proxy::fields::addResult::FieldType> FieldaddResultMethodSet(const
      std::uint32_t& value) override {
    // Build struct with all input arguments
    ::tongjidemo::internal::fields::addResultSet::Input input_struct{value};
    return field_manager_addResult_set_.HandleMethodRequest(input_struct);
  }

 private:
  /** Subscribed events with the related event manager */
  using EventSubscriptionsMap =
      std::map<amsr::someip_protocol::internal::EventId, amsr::someip_binding::internal::ServiceProxySomeIpEventInterface*>;

  /** SOME/IP instance ID used by this binding. */
  amsr::someip_protocol::internal::InstanceId instance_id_;

  /** SOME/IP related client ID used by this concrete proxy instance. */
  amsr::someip_protocol::internal::ClientId client_id_;

  /** Related SOME/IP binding */
  amsr::someip_binding::internal::AraComSomeIpBindingClientManagerInterface& someip_binding_client_manager_;

  /** Related service proxy specific resource manager */
  resources::ServiceInterfaceProxyResourceManager& resource_manager_;

  /** Logger for tracing and debugging */
  amsr::com_common::internal::logging::AraComLogger logger_;

  /** Event subscriptions */
  EventSubscriptionsMap event_subscriptions_;

  /** Mutex for protection of event_subscriptions_ */
  std::mutex event_subscriptions_lock_;

  /* ---- Methods ------------------------------------------------------------------------------------------ */

  /** Method request/response class for proxy method 'add' */
  someip_binding::internal::methods::Proxyadd method_add_;

  /* ---- Event manager -------------------------------------------------------------------------------------------- */

  /** Event  manager for proxy event 'addInfo' */
  ServiceInterfaceProxySomeIpEventManageraddInfo event_manager_addInfo_;

  /* ---- Field method/event manager ------------------------------------------------------------------------------- */
  /** Field notifier for the the proxy field 'addResult' */
  ServiceInterfaceProxySomeIpFieldNotifieraddResult field_notifier_addResult_;

  /** Field method manager for method Get of proxy field 'addResult' */
  someip_binding::internal::fields::ProxyaddResultGet field_manager_addResult_get_;

  /** Field method manager for method Set of proxy field 'addResult' */
  someip_binding::internal::fields::ProxyaddResultSet field_manager_addResult_set_;

};

}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

#endif  // CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_BINDING_H_

