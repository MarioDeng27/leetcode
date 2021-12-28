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
/**        \file  Client\src/ara/com/runtime_init.cpp
 *        \brief  Runtime initialization with all deployment bindings
 *
 *      \details
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_api
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/



#include <stdexcept>
#include "ara/com/resource_manager.h"
#include "ara/com/runtime.h"
#include "ara/core/optional.h"
#include "socal/internal/configuration/configuration.h"
#include "someip_binding/internal/aracom_someip_binding.h"

namespace ara {
namespace com {

/*!
 * \brief Resource manager.
 */
ara::core::Optional<::amsr::socal::internal::ResourceManager> aracom_resource_manager_;

/*!
 * \brief Static instantiation of binding 'SomeIp'.
 */
ara::core::Optional<amsr::someip_binding::internal::AraComSomeIpBinding<
    ::amsr::socal::internal::ResourceManager, ::amsr::someip_daemon_client::internal::SomeIpPosix<::amsr::someip_daemon_client::internal::SomeIpPosixDefaultTemplateConfiguration>>>
    aracom_someip_binding_;

void Runtime::SetTraceImpl(trace::IpcBindingTraceIf* trace_if) {
  (void)trace_if;
  throw std::invalid_argument("SOME/IP Binding doesn't support Tracing");
}

void Runtime::InitializeResourceManager() {
  /* Initialize binding independent ara::com resource manager */
  aracom_resource_manager_.emplace();
}

void Runtime::InitializeBindings() {
  {
    /* Initialize binding 'SomeIp' */
    std::function<void()> poll_function{[this]() { ProcessNextPacket(); }};
    aracom_someip_binding_.emplace(config_, aracom_resource_manager_.value(), poll_function, &reactor_);
    // Call Binding initialization. Binding registers all InstanceSpecifier to InstanceIdentifier mappings at the InstanceSpecifierTable.
    aracom_someip_binding_.value().Initialize(instance_specifier_table_);
  }
}

void Runtime::DeinitializeBindings() {
  {
    /* Deinitialize binding 'SomeIp' */
    aracom_someip_binding_.value().DeInitialize();
    aracom_someip_binding_.reset();
  }
}

}  // namespace com
}  // namespace ara

