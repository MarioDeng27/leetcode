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
/**        \file  Client\includes\tongjidemo/serviceinterface_proxy_resource_manager.h
 *        \brief  Header for resource manager of service 'ServiceInterface' proxy.
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

#ifndef CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_RESOURCE_MANAGER_H_
#define CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "com-common/internal/memory/flexible/flexible_unique_memory_buffer_allocator.h"

namespace tongjidemo {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'ServiceInterface' proxy
 */
class ServiceInterfaceProxyResourceManager {
 public:
   /*!
   * \brief Constructor
   */
  ServiceInterfaceProxyResourceManager();

  /*!
   * \brief Delete copy-construct
   */
  ServiceInterfaceProxyResourceManager(const ServiceInterfaceProxyResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  ServiceInterfaceProxyResourceManager(ServiceInterfaceProxyResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  ServiceInterfaceProxyResourceManager& operator=(const ServiceInterfaceProxyResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  ServiceInterfaceProxyResourceManager& operator=(ServiceInterfaceProxyResourceManager&&) = delete;

  /*!
   * \brief Get the transmit buffer allocator for service method 'add'
   * \return Buffer for serialization / transmission of 'add' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetMethodaddTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service field 'addResultGet'
   * \return Buffer for serialization / transmission of 'addResultGet' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldaddResultGetTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service field 'addResultSet'
   * \return Buffer for serialization / transmission of 'addResultSet' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldaddResultSetTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service field 'addResultNotifier'
   * \return Buffer for serialization / transmission of 'addResultNotifier' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetFieldaddResultNotifierTxBufferAllocator();


 private:

  /*!
   * \brief Transmit buffer allocator for service method 'add'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator method_add_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service field 'addResultGet'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_addresultget_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service field 'addResultSet'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_addresultset_tx_buffer_allocator_;


  /*!
   * \brief Transmit buffer allocator for service field 'addResultNotifier'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator field_addresultnotifier_tx_buffer_allocator_;

 };

}  // namespace resources
}  // namespace tongjidemo

#endif  // CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_RESOURCE_MANAGER_H_
