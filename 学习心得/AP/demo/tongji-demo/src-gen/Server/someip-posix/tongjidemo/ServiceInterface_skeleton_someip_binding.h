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
/**        \file  Server\someip-posix/\tongjidemo/ServiceInterface_skeleton_someip_binding.h
 *        \brief  SOME/IP binding of service skeleton for service 'ServiceInterface'
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

#ifndef SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_BINDING_H_
#define SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <map>
#include <utility>
#include "ara/core/promise.h"
#include "someip_binding/internal/aracom_someip_binding_server_manager_interface.h"
#include "someip_binding/internal/aracom_someip_skeleton_interface.h"
#include "tongjidemo/ServiceInterface_skeleton_impl_interface.h"
#include "tongjidemo/ServiceInterface_skeleton_someip_event_manager.h"
#include "tongjidemo/ServiceInterface_skeleton_someip_methods.h"
#include "tongjidemo/serviceinterface_skeleton.h"
#include "tongjidemo/serviceinterface_skeleton_resource_manager.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {
/*!
 * \brief SOME/IP skeleton binding of Service 'ServiceInterface'.
 * \details Handles serialization and deserialization of all method calls, events, etc.
 * \remark generated
 */
class ServiceInterfaceSkeletonSomeIpBinding final :
    public tongjidemo::internal::ServiceInterfaceSkeletonImplInterface,
    public amsr::someip_binding::internal::AraComSomeIpSkeletonInterface {
 public:
  /*!
   * \brief Type alias for used skeleton frontend.
   */
  using SkeletonFrontend = skeleton::ServiceInterfaceSkeleton;
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
   * \param instance_id SOME/IP service instance ID offered by this skeleton.
   * \param someip_binding_server_manager Reference to the related SOME/IP transport binding manager.
   * \param resource_manager Reference to service skeleton specific resource manager.
   * \param skeleton Reference to the related frontend skeleton.
   */
  ServiceInterfaceSkeletonSomeIpBinding(amsr::someip_protocol::internal::InstanceId instance_id,
                                                        amsr::someip_binding::internal::AraComSomeIpBindingServerManagerInterface& someip_binding_server_manager,
                                                        resources::ServiceInterfaceSkeletonResourceManager& resource_manager,
                                                        skeleton::ServiceInterfaceSkeleton& skeleton);

  /*!
   * \brief Default destructor must de-register the implementation from the AraComSomeIpBinding.
   */
  ~ServiceInterfaceSkeletonSomeIpBinding();

  /*!
   * \brief Get the SkeletonId this SkeletonImplInterface can handle.
   * \returns The SkeletonId this SkeletonImplInterface can handle.
   */
  ::amsr::socal::internal::SkeletonId GetSkeletonId() const override {
    return skeleton::ServiceInterfaceSkeleton::GetSkeletonIdStatic();
  }

  /*!
   * \brief Getter for accessing the related frontend skeleton.
   */
  SkeletonFrontend& GetSkeleton() const noexcept { return skeleton_; }

  /*!
   * \brief Receive handler for method requests.
   *
   * \param header Deserialized SOME/IP header.
   * \param deserializer Root deserializer holding the packet buffer.
   */
  void HandleMethodRequest(const amsr::someip_protocol::internal::SomeIpMessageHeader& header, amsr::someip_binding::internal::RootDeserializerAlias&& deserializer) override;

  /*!
   * \brief Forward a prepared packet to the AraComSomeIpBinding.
   * \param packet the serialized response packet.
   */
  void SendMethodResponse(amsr::com_common::internal::memory::MemoryBufferPtr packet);

  /*!
   * \brief Send a SOME/IP error response packet. Used in case of:
   *  - Infrastructural checks failed (protocol version, return code, message type)
   *  - Deserialization failed
   *  - Serialization of method responses failed
   *  - Service / Method is not implemented.
   *
   * \tparam ReturnCode The error return code as template parameter to make a compile-time check.
   * \param request_header The unmodified SOME/IP header.
   */
  template <typename amsr::someip_protocol::internal::ReturnCode ReturnCode>
  void SendErrorResponse(const amsr::someip_protocol::internal::SomeIpMessageHeader& request_header) {
    static_assert((ReturnCode >= amsr::someip_protocol::internal::SomeIpReturnCode::kNotOk) &&
                      (ReturnCode <= amsr::someip_protocol::internal::SomeIpReturnCode::kRangeServiceErrorsEnd),
                  "Return code for errors must be in the range of 0x01 .. 0x5E.");
    someip_binding_server_manager_.SendErrorResponse(ReturnCode, instance_id_, request_header);
  }

  /*!
   * \brief Send an error response if the SOME/IP request is malformed. This method is invoked
   * when the return code of the error response is only known during runtime.
   * \param return_code The return code to send.
   * \param request_header The header taken from the request.
   */
  void SendErrorResponse(const amsr::someip_protocol::internal::ReturnCode return_code,
                         const amsr::someip_protocol::internal::SomeIpMessageHeader& request_header) {
    someip_binding_server_manager_.SendErrorResponse(return_code, instance_id_, request_header);
  }

  /*!
   * \brief Send an event notification
   * \param packet SOME/IP packet with header and payload.
   */
  void SendEventNotification(amsr::com_common::internal::memory::MemoryBufferPtr packet);

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Called by frontend skeleton on event notification for service event 'addInfo'.
   * \param data Event sample of type uint32_t
   */
  void SendEventaddInfo(const std::uint32_t& data) override;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */
  /*!
   * \brief Called by the frontend skeleton on event notification for service field 'addResult'.
   * \param data Current data for the field 'addResult'.
   */
  void UpdateFieldaddResult(const std::uint32_t& data) override;

 private:
  /** SOME/IP instance ID offered by this skeleton */
  amsr::someip_protocol::internal::InstanceId instance_id_;

  /** Related SOME/IP binding */
  amsr::someip_binding::internal::AraComSomeIpBindingServerManagerInterface& someip_binding_server_manager_;

  /** Related service skeleton specific resource manager */
  resources::ServiceInterfaceSkeletonResourceManager& resource_manager_;

  /** Reference to the related frontend skeleton */
  skeleton::ServiceInterfaceSkeleton& skeleton_;

  /* ---- Methods ------------------------------------------------------------------------------------------ */
  /** Method request/response class for skeleton method 'add' */
  someip_binding::internal::methods::Skeletonadd methods_add_;

  /* ---- Event manager -------------------------------------------------------------------------------------------- */
  /** Event manager for skeleton event 'addInfo' */
  ServiceInterfaceSkeletonSomeIpEventManageraddInfo event_manager_addInfo_;

  /* ---- Field manager -------------------------------------------------------------------------------------------- */

  /* ---- Field 'addResult' ---- */

  /** Field notifier for the the skeleton field 'addResult' */
  ServiceInterfaceSkeletonSomeIpFieldNotifieraddResult field_notifier_addResult_;

  /** Field method manager for method Get of skeleton field 'addResult' */
  someip_binding::internal::fields::SkeletonaddResultGet field_manager_addResult_get_;

  /** Field method manager for method Set of skeleton field 'addResult' */
  someip_binding::internal::fields::SkeletonaddResultSet field_manager_addResult_set_;
};

}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

#endif  // SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_BINDING_H_

