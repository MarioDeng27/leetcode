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
/**        \file  Client\/someip-posix/ara/com//aracom_someip_binding_init.cpp
 *        \brief  ara::com SOME/IP binding initialization
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
#include "ara/com/resource_manager.h"
#include "ara/core/optional.h"
#include "someip_binding/internal/aracom_someip_binding.h"
#include "tongjidemo/ServiceInterface_someip_proxy_factory.h"

namespace amsr {
namespace someip_binding {
namespace internal {

/*!
 * \brief Literals namespace needed for StringView _sv literal.
 */
using namespace vac::container::literals;  // NOLINT(build/namespaces)


namespace tongjidemo {

/*!
 * \brief Static instantiation of a proxy factory for the service 'ServiceInterface'.
 */
ara::core::Optional<::tongjidemo::someip_binding::internal::ServiceInterfaceSomeIpProxyFactory>
    ServiceInterface_someip_proxy_factory_;

}  // namespace tongjidemo


template <>
void AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager,
    ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>::InitializeInstanceSpecifierMappings(::amsr::socal::internal::InstanceSpecifierLookupTable& instance_specifier_table) {
  // ---- Register all known R-Port InstanceSpecifiers ----

  // Map R-Port /Applications/ClientSwComponentType/RPort_ServiceInterface to instance /ServiceInstances/ClientServiceInstance/RequiredServiceInterfaceDeployment 
  instance_specifier_table.MapInstanceSpecifierToInstanceId(
      this, ::ara::core::InstanceSpecifier{"Client/RootSwComponentPrototype/RPort_ServiceInterface"_sv},
      ::ara::com::InstanceIdentifier{"SomeIp:1"_sv},"/ServiceInterfaces/ServiceInterface"_sv);

  // ---- Register all known P-Port InstanceSpecifiers ----
  // No P-Ports configured
}

template <>
void AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager,
    ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>::InitializeServiceInterfaceProxyFactories() {

  // Instantiate and register a proxy factory for the service
  // 'tongjidemo::ServiceInterface'.
  tongjidemo::ServiceInterface_someip_proxy_factory_.emplace(
      client_manager_, resource_manager_.GetResourceManager<::tongjidemo::ServiceInterface>().GetProxyResourceManager());
  client_manager_.AddProxyFactory(tongjidemo::ServiceInterface_someip_proxy_factory_.value());
}

template <>
void AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager,
    ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>::InitializeServiceInterfaceSkeletonFactories() {
  // No provided service interfaces configured
}

template <>
void AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager,
    ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>::InitializeHook(::amsr::socal::internal::InstanceSpecifierLookupTable& instance_specifier_table) {
  InitializeInstanceSpecifierMappings(instance_specifier_table);

  // Initialize factories for service interface creation
  InitializeServiceInterfaceProxyFactories();
  InitializeServiceInterfaceSkeletonFactories();

  // Connect to the SOME/IP daemon
  someip_posix_.Connect();
}

}  // namespace internal
}  // namespace someip_binding
}  // namespace amsr

