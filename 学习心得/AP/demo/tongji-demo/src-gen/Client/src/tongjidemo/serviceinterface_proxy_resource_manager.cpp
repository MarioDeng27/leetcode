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
/**        \file  Client\src/tongjidemo/serviceinterface_proxy_resource_manager.cpp
 *        \brief  Resource manager of service 'ServiceInterface' proxy.
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
#include "tongjidemo/serviceinterface_proxy_resource_manager.h"

namespace tongjidemo {
namespace resources {

ServiceInterfaceProxyResourceManager::ServiceInterfaceProxyResourceManager()
  : 
     method_add_tx_buffer_allocator_(),
     field_addresultget_tx_buffer_allocator_(),
     field_addresultset_tx_buffer_allocator_(),
     field_addresultnotifier_tx_buffer_allocator_()
    {}

amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceProxyResourceManager::GetMethodaddTxBufferAllocator() {
  return method_add_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceProxyResourceManager::GetFieldaddResultGetTxBufferAllocator() {
  return field_addresultget_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceProxyResourceManager::GetFieldaddResultSetTxBufferAllocator() {
  return field_addresultset_tx_buffer_allocator_;

}
amsr::com_common::internal::memory::MemoryBufferAllocator& ServiceInterfaceProxyResourceManager::GetFieldaddResultNotifierTxBufferAllocator() {
  return field_addresultnotifier_tx_buffer_allocator_;

}
}  // namespace resources
}  // namespace tongjidemo

