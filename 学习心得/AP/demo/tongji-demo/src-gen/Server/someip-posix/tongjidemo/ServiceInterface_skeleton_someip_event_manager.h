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
/**        \file  Server\someip-posix/\tongjidemo/ServiceInterface_skeleton_someip_event_manager.h
 *        \brief  SOME/IP skeleton event handling for events and field notifications of service 'ServiceInterface'
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

#ifndef SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_EVENT_MANAGER_H_
#define SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_EVENT_MANAGER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <atomic>
#include "com-common/internal/logging/ara_com_logging.h"
#include "socal/internal/session_handler.h"
#include "someip-protocol/internal/marshalling.h"
#include "someip_binding/internal/e2e_marshalling.h"
#include "tongjidemo/serviceinterface_common.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {

// Forward-declaration for back-reference
class ServiceInterfaceSkeletonSomeIpBinding;

/* ---- Event 'addInfo' ------------------------------------------- */
/*!
 * \brief SOME/IP Skeleton event manager for event 'addInfo'.
 * \details Handles event and field notification serialization.
 * \remark generated
 */
class ServiceInterfaceSkeletonSomeIpEventManageraddInfo final {
 public:
  /*!
   * \brief Constructor
   * \param skeleton_binding Related SOME/IP skeleton binding to be used
   * \param tx_buffer_allocator Reference to memory buffer allocator for packet transmission
   */
  ServiceInterfaceSkeletonSomeIpEventManageraddInfo(
      ServiceInterfaceSkeletonSomeIpBinding& skeleton_binding,
      amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator);

  /*!
   * \brief Send a event sample of skeleton event 'addInfo'.
   *
   * \param data Event sample of type uint32_t
   *
   * \throws ::ara::com::InternalComException If serialization has failed (errc: serialization_error).
   * \trace SPEC-4981292, SPEC-4980077
   */
  void Send(const std::uint32_t& data);

 private:

  /*!
   * \brief Returns a reference to the session handler.
   *
   * \pre -
   * \threadsafe TRUE
   * \exceptionsafety STRONG No undefined behavior or side effects.
   *
   * \return reference to the session handler.
   */
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId>& GetSessionHandler() noexcept { return session_; }

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /*!
   * \brief Skeleton binding for event transmission
   */
  ServiceInterfaceSkeletonSomeIpBinding& skeleton_binding_;

  /*!
   * \brief Reference to buffer allocator for packet transmission
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator_;

  /*!
   * \brief Provides functionality to create unique IDs for each request (session)
   */
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId> session_;

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

/* ---- Field notifier 'addResult' ------------------------------------------- */
/*!
 * \brief SOME/IP Skeleton event manager for event 'addResult'.
 * \details Handles event and field notification serialization.
 * \remark generated
 */
class ServiceInterfaceSkeletonSomeIpFieldNotifieraddResult final {
 public:
  /*!
   * \brief Constructor
   * \param skeleton_binding Related SOME/IP skeleton binding to be used
   * \param tx_buffer_allocator Reference to memory buffer allocator for packet transmission
   */
  ServiceInterfaceSkeletonSomeIpFieldNotifieraddResult(
      ServiceInterfaceSkeletonSomeIpBinding& skeleton_binding,
      amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator);

  /*!
   * \brief Send a event sample of skeleton event 'addResult'.
   *
   * \param data Event sample of type uint32_t
   *
   * \throws ::ara::com::InternalComException If serialization has failed (errc: serialization_error).
   * \trace SPEC-4981292, SPEC-4980112
   */
  void Send(const std::uint32_t& data);

 private:

  /*!
   * \brief Returns a reference to the session handler.
   *
   * \pre -
   * \threadsafe TRUE
   * \exceptionsafety STRONG No undefined behavior or side effects.
   *
   * \return reference to the session handler.
   */
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId>& GetSessionHandler() noexcept { return session_; }

  /*!
   * \brief Returns a reference to the logger.
   * \return reference to the logger.
   */
  amsr::com_common::internal::logging::AraComLogger& GetLogger() noexcept { return logger_; }

  /*!
   * \brief Skeleton binding for event transmission
   */
  ServiceInterfaceSkeletonSomeIpBinding& skeleton_binding_;

  /*!
   * \brief Reference to buffer allocator for packet transmission
   */
  amsr::com_common::internal::memory::MemoryBufferAllocator& tx_buffer_allocator_;

  /*!
   * \brief Provides functionality to create unique IDs for each request (session)
   */
  ::amsr::socal::internal::SessionHandler<amsr::someip_protocol::internal::SessionId> session_;

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};

}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

#endif  // SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_EVENT_MANAGER_H_

