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
/**        \file  Client\src/ara/com/resource_manager.cpp
 *        \brief  Binding independent resource manager
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
#include "ara/com/resource_manager.h"
#include "tongjidemo/ServiceInterface.h"

namespace amsr {
namespace socal {
namespace internal {

/*!
 * \brief Template specialization for resource manager of service 'tongjidemo::ServiceInterface'
 */
template <>
tongjidemo::resources::ServiceInterfaceResourceManager&
ResourceManager::GetResourceManager<tongjidemo::ServiceInterface>() {
  return tongjidemo_serviceinterface_resource_manager_;
}

::amsr::socal::internal::SomeIpResourceManager&
::amsr::socal::internal::ResourceManager::GetSomeIpResourceManager() {
  return someip_resource_manager_;
}

}  // namespace internal
}  // namespace socal
}  // namespace amsr

