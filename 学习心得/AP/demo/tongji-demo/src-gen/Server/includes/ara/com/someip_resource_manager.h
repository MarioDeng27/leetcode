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
/**        \file  Server\includes\ara/com/someip_resource_manager.h
 *        \brief  Header for resource manager of binding 'SomeIp'.
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

#ifndef SERVER_INCLUDES_ARA_COM_SOMEIP_RESOURCE_MANAGER_H_
#define SERVER_INCLUDES_ARA_COM_SOMEIP_RESOURCE_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "com-common/internal/memory/flexible/flexible_unique_memory_buffer_allocator.h"

namespace amsr {
namespace socal {
namespace internal {

/*!
 * \brief ara::com resource manager for binding 'SomeIp'
 */
class SomeIpResourceManager final {
 public:
  /*!
   * \brief Default constructor
   */
  SomeIpResourceManager() = default;

  /*!
   * \brief Delete copy-construct
   */
  SomeIpResourceManager(const SomeIpResourceManager&) = delete;

  /*!
   * \brief Delete move-constructor
   */
  SomeIpResourceManager(SomeIpResourceManager&&) = delete;

  /*!
   * \brief Delete copy-assignment operator
   */
  SomeIpResourceManager& operator=(const SomeIpResourceManager&) = delete;

  /*!
   * \brief Delete move-assignment operator
   */
  SomeIpResourceManager& operator=(SomeIpResourceManager&&) = delete;

  /*!
   * \brief Get the receive buffer allocator for binding 'SomeIp'
   * \return Allocator for buffers meant to accomodate received 'SomeIp' packets
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetRxBufferAllocator();

  /*!
   * \brief Get the error buffer allocator for binding 'SomeIp'
   * \return Allocator for buffers meant to accomodate 'SomeIp' error messages
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& GetErrorMessageMemoryBufferAllocator();


 private:
  /*!
   * \brief Receive buffer allocator for binding 'SomeIp'
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator rx_buffer_allocator_;
  /*!
   * \brief Error buffer allocator for binding 'SomeIp'
   */
  amsr::com_common::internal::memory::flexible::FlexibleUniqueMemoryBufferAllocator err_buffer_allocator_;
 };

}  // namespace internal
}  // namespace socal
}  // namespace amsr

#endif  // SERVER_INCLUDES_ARA_COM_SOMEIP_RESOURCE_MANAGER_H_
