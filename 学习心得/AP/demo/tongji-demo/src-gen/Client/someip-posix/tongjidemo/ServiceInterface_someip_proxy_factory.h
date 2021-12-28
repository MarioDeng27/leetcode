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
/**        \file  Client\someip-posix/\tongjidemo/ServiceInterface_someip_proxy_factory.h
 *        \brief  SOME/IP proxy factory for service 'ServiceInterface'
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

#ifndef CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SOMEIP_PROXY_FACTORY_H_
#define CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SOMEIP_PROXY_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "someip_binding/internal/aracom_someip_proxy_factory.h"
#include "tongjidemo/ServiceInterface_proxy_someip_binding.h"
#include "tongjidemo/serviceinterface_proxy.h"
#include "tongjidemo/serviceinterface_proxy_resource_manager.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {


/*!
 * \brief SOME/IP proxy factory for the service interface 'ServiceInterface'
 * \remark generated
 */
using ServiceInterfaceSomeIpProxyFactory = amsr::someip_binding::internal::AraComSomeIpProxyFactory<resources::ServiceInterfaceProxyResourceManager, proxy::ServiceInterfaceProxy, ServiceInterfaceProxySomeIpBinding>;

}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

#endif  // CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SOMEIP_PROXY_FACTORY_H_

