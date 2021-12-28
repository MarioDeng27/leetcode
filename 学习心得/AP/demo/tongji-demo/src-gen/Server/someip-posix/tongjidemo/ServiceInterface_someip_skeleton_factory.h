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
/**        \file  Server\someip-posix/\tongjidemo/ServiceInterface_someip_skeleton_factory.h
 *        \brief  SOME/IP skeleton factory for service 'ServiceInterface'
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

#ifndef SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SOMEIP_SKELETON_FACTORY_H_
#define SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SOMEIP_SKELETON_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "someip_binding/internal/aracom_someip_skeleton_factory.h"
#include "tongjidemo/ServiceInterface_skeleton_someip_binding.h"
#include "tongjidemo/serviceinterface_skeleton.h"
#include "tongjidemo/serviceinterface_skeleton_resource_manager.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {

/*!
 * \brief SOME/IP skeleton factory for the service interface 'ServiceInterface'
 * \remark generated
 */
using ServiceInterfaceSomeIpSkeletonFactory = amsr::someip_binding::internal::AraComSomeIpSkeletonFactory<resources::ServiceInterfaceSkeletonResourceManager, skeleton::ServiceInterfaceSkeleton, ServiceInterfaceSkeletonSomeIpBinding>;

}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

#endif  // SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SOMEIP_SKELETON_FACTORY_H_

