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
/**        \file  Client\includes\tongjidemo/serviceinterface_resource_manager.h
 *        \brief  Header for resource manager of service 'ServiceInterface'.
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

#ifndef CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_RESOURCE_MANAGER_H_
#define CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "tongjidemo/serviceinterface_proxy_resource_manager.h"

namespace tongjidemo {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'ServiceInterface'
 */
class ServiceInterfaceResourceManager final {
 public:
  /*!
   * \brief Default constructor
   */
  ServiceInterfaceResourceManager() = default;

  /*!
   * \brief Delete copy-construct
   */
  ServiceInterfaceResourceManager(const ServiceInterfaceResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  ServiceInterfaceResourceManager(ServiceInterfaceResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  ServiceInterfaceResourceManager& operator=(const ServiceInterfaceResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  ServiceInterfaceResourceManager& operator=(ServiceInterfaceResourceManager&&) = delete;
  /*!
   * \brief Get resource manager for service 'ServiceInterface' proxy
   * \return Resource manager for service 'ServiceInterface' proxy
   */
  ServiceInterfaceProxyResourceManager& GetProxyResourceManager();

 private:
  /*!
   * \brief Resource manager for service 'ServiceInterface' proxy
   */
  ServiceInterfaceProxyResourceManager proxy_resource_manager_;

};

}  // namespace resources
}  // namespace tongjidemo

#endif  // CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_RESOURCE_MANAGER_H_
