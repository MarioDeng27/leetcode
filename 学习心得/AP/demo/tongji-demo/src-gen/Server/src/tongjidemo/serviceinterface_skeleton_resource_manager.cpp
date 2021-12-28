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
/**        \file  Server\src/tongjidemo/serviceinterface_skeleton_resource_manager.cpp
 *        \brief  Resource manager of service 'ServiceInterface' skeleton.
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
#include "tongjidemo/serviceinterface_skeleton_resource_manager.h"

namespace tongjidemo {
namespace resources {

ServiceInterfaceSkeletonResourceManager::ServiceInterfaceSkeletonResourceManager()
  : 
     method_add_tx_buffer_allocator_(),
     event_addinfo_tx_buffer_allocator_(),
     field_addresultget_tx_buffer_allocator_(),
     field_addresultset_tx_buffer_allocator_(),
     field_addresultnotifier_tx_buffer_allocator_()
    {}

amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceSkeletonResourceManager::GetMethodaddTxBufferAllocator() {
  return method_add_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceSkeletonResourceManager::GetEventaddInfoTxBufferAllocator() {
  return event_addinfo_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceSkeletonResourceManager::GetFieldaddResultGetTxBufferAllocator() {
  return field_addresultget_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceSkeletonResourceManager::GetFieldaddResultSetTxBufferAllocator() {
  return field_addresultset_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceSkeletonResourceManager::GetFieldaddResultNotifierTxBufferAllocator() {
  return field_addresultnotifier_tx_buffer_allocator_;

}
}  // namespace resources
}  // namespace tongjidemo

