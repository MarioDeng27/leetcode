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
/**        \file  Client\src/tongjidemo/serviceinterface_proxy.cpp
 *        \brief  Proxy for service 'ServiceInterface'.
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
#include "tongjidemo/serviceinterface_proxy.h"
#include "tongjidemo/ServiceInterface_proxy_internal.h"


/*!
 * \trace SPEC-4980240
 * \trace SPEC-4980242
 */
namespace tongjidemo {
namespace proxy {

ServiceInterfaceProxy::ServiceInterfaceProxy(const ServiceInterfaceProxy::HandleType& handle)
    : Base{ConstructInterface(handle)},
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
             "ServiceInterfaceProxy"),
      add{this},
      addInfo{this},
      addResult{this} {
  // Register the proxy. After this call, callbacks might be received.
  // This must be the LAST thing to do while creating the proxy, otherwise, race-conditions during
  // construction might happen.
  proxy_impl_interface_ptr_->Initialize();
}

ServiceInterfaceProxy::~ServiceInterfaceProxy() {
  // Unregister the proxy. After this call, no more callbacks might be received.
  // This must be the FIRST thing to do while destroying the proxy, otherwise, race-conditions during
  // destruction might happen.
  proxy_impl_interface_ptr_->DeInitialize();
}

}  // namespace proxy
}  // namespace tongjidemo

