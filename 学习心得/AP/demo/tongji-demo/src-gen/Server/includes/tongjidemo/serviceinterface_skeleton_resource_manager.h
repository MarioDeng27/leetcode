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
/**        \file  Server\includes\tongjidemo/serviceinterface_skeleton_resource_manager.h
 *        \brief  Header for resource manager of service 'ServiceInterface' skeleton.
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

#ifndef SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_RESOURCE_MANAGER_H_
#define SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "com-common/internal/memory/flexible/flexible_unique_memory_buffer_allocator.h"

namespace tongjidemo {
namespace resources {

/*!
 * \brief ara::com resource manager for service 'ServiceInterface' skeleton
 */
class ServiceInterfaceSkeletonResourceManager {
 public:
   /*!
   * \brief Constructor
   */
  ServiceInterfaceSkeletonResourceManager();

  /*!
   * \brief Delete copy-construct
   */
  ServiceInterfaceSkeletonResourceManager(const ServiceInterfaceSkeletonResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  ServiceInterfaceSkeletonResourceManager(ServiceInterfaceSkeletonResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  ServiceInterfaceSkeletonResourceManager& operator=(const ServiceInterfaceSkeletonResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  ServiceInterfaceSkeletonResourceManager& operator=(ServiceInterfaceSkeletonResourceManager&&) = delete;

  /*!
   * \brief Get the transmit buffer allocator for service method 'add'
   * \return Buffer for serialization / transmission of 'add' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetMethodaddTxBufferAllocator();


  /*!
   * \brief Get the transmit buffer allocator for service event 'addInfo'
   * \return Buffer for serialization / transmission of 'addInfo' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetEventaddInfoTxBufferAllocator();


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
   * \brief Transmit buffer allocator for service event 'addInfo'
   * \details Configured memory mode: 'Flexible'. 
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator event_addinfo_tx_buffer_allocator_;


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

#endif  // SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_RESOURCE_MANAGER_H_
