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
/**        \file  Client\src/ara/com/someip_resource_manager.cpp
 *        \brief  Resource manager of binding 'SomeIp'.
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
#include "ara/com/someip_resource_manager.h"

namespace amsr {
namespace socal {
namespace internal {

amsr::com_common::internal::memory::MemoryBufferAllocator& ::amsr::socal::internal::SomeIpResourceManager::GetRxBufferAllocator() {
  return rx_buffer_allocator_;
}

amsr::com_common::internal::memory::MemoryBufferAllocator& ::amsr::socal::internal::SomeIpResourceManager::GetErrorMessageMemoryBufferAllocator() {
  return err_buffer_allocator_;
}

}  // namespace internal
}  // namespace socal
}  // namespace amsr

