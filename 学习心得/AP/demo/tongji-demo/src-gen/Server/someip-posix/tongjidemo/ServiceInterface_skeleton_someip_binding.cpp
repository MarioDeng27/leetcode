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
/**        \file  Server\someip-posix/tongjidemo/ServiceInterface_skeleton_someip_binding.cpp
 *        \brief  SOME/IP skeleton binding of service 'ServiceInterface'
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
#include "tongjidemo/ServiceInterface_skeleton_someip_binding.h"
#include "someip-protocol/internal/marshalling.h"
#include "tongjidemo/ServiceInterface.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {

/*!
 * \brief Generated SOME/IP related service ID.
 */
constexpr amsr::someip_protocol::internal::ServiceId ServiceInterfaceSkeletonSomeIpBinding::kServiceId;

/*!
 * \brief SOME/IP major version of this service interface deployment.
 */
constexpr amsr::someip_protocol::internal::MajorVersion ServiceInterfaceSkeletonSomeIpBinding::kMajorVersion;

ServiceInterfaceSkeletonSomeIpBinding::ServiceInterfaceSkeletonSomeIpBinding(
    amsr::someip_protocol::internal::InstanceId instance_id,
    amsr::someip_binding::internal::AraComSomeIpBindingServerManagerInterface& someip_binding_server_manager,
    resources::ServiceInterfaceSkeletonResourceManager& resource_manager,
    skeleton::ServiceInterfaceSkeleton& skeleton)
    : instance_id_(instance_id),
      someip_binding_server_manager_(someip_binding_server_manager),
      resource_manager_(resource_manager),
      skeleton_(skeleton),
      methods_add_(*this, resource_manager_.GetMethodaddTxBufferAllocator()) ,
      event_manager_addInfo_(*this, resource_manager_.GetEventaddInfoTxBufferAllocator()),
      field_notifier_addResult_(*this, resource_manager_.GetFieldaddResultNotifierTxBufferAllocator()),
      field_manager_addResult_get_(*this, resource_manager_.GetFieldaddResultGetTxBufferAllocator()),
      field_manager_addResult_set_(*this, resource_manager_.GetFieldaddResultSetTxBufferAllocator())
{
  static constexpr amsr::someip_protocol::internal::ServiceId service_id = ServiceInterfaceSkeletonSomeIpBinding::kServiceId;
  // Register this skeleton binding for method requests and event requests in the AraComSomeIpBinding.
  someip_binding_server_manager_.RegisterSkeletonBinding(std::make_tuple(service_id, instance_id_), this);
}

ServiceInterfaceSkeletonSomeIpBinding::~ServiceInterfaceSkeletonSomeIpBinding() {
  static constexpr amsr::someip_protocol::internal::ServiceId service_id = ServiceInterfaceSkeletonSomeIpBinding::kServiceId;
  someip_binding_server_manager_.DeRegisterSkeletonBinding(std::make_tuple(service_id, instance_id_));
}

void ServiceInterfaceSkeletonSomeIpBinding::HandleMethodRequest(const amsr::someip_protocol::internal::SomeIpMessageHeader& header, amsr::someip_binding::internal::RootDeserializerAlias&& deserializer) {
  // Get method ID from header
  const amsr::someip_protocol::internal::MethodId method_id{header.method_id_};

  // Based on the method id -> static dispatching to the method request/response manager
  switch (method_id) {
    case someip_binding::internal::methods::Skeletonadd::kMethodId: {
      methods_add_.HandleMethodRequest(header, std::move(deserializer));
      break;
    }
    case someip_binding::internal::fields::SkeletonaddResultGet::kMethodId: {
      field_manager_addResult_get_.HandleMethodRequest(header, std::move(deserializer));
      break;
    }
    case someip_binding::internal::fields::SkeletonaddResultSet::kMethodId: {
      field_manager_addResult_set_.HandleMethodRequest(header, std::move(deserializer));
      break;
    }
    default: {
      // Method implementation is missing.
      SendErrorResponse<amsr::someip_protocol::internal::SomeIpReturnCode::kUnknownMethod>(header);
      break;
    }
  }
}

void ServiceInterfaceSkeletonSomeIpBinding::SendMethodResponse(amsr::com_common::internal::memory::MemoryBufferPtr packet) {
  someip_binding_server_manager_.SendMethodResponse(instance_id_, std::move(packet));
}

void ServiceInterfaceSkeletonSomeIpBinding::SendEventNotification(amsr::com_common::internal::memory::MemoryBufferPtr packet) {
  someip_binding_server_manager_.SendEventNotification(instance_id_, std::move(packet));
}

/* ---- Events ----------------------------------------------------------------------------------------------------- */

/* Event 'addInfo' */
void ServiceInterfaceSkeletonSomeIpBinding::SendEventaddInfo(const std::uint32_t& data) {
  event_manager_addInfo_.Send(data);
}
/* ---- Fields ----------------------------------------------------------------------------------------------------- */
/* Field 'addResult' */
void ServiceInterfaceSkeletonSomeIpBinding::UpdateFieldaddResult(const std::uint32_t& data) {
  field_notifier_addResult_.Send(data);
}

}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

