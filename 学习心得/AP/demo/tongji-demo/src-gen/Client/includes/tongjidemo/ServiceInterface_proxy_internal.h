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
/**        \file  Client\includes\tongjidemo/ServiceInterface_proxy_internal.h
 *        \brief  Proxy implementation interface of service 'ServiceInterface'.
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

#ifndef CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_INTERNAL_H_
#define CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_INTERNAL_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "ara/core/future.h"
#include "socal/internal/proxy_impl_event.h"
#include "tongjidemo/ServiceInterface_types.h"

namespace tongjidemo {
namespace internal {


/*!
 * \brief Proxy HandleType for the Service 'ServiceInterface'.
 * \trace SPEC-4980259
 */
class ServiceInterfaceHandleType final : public ::amsr::socal::internal::HandleType {
  public:
  /*!
   * \brief Inherit constructor.
   */
  using HandleType::HandleType;
};


/*!
 * \brief Proxy implementation interface for the Service 'ServiceInterface'
 * \remark generated
 */
class ServiceInterfaceProxyImplInterface : public ::amsr::socal::internal::ProxyImplInterface {
 public:
  /*!
   * \brief Define default constructor.
   */
  ServiceInterfaceProxyImplInterface() = default;
  /*!
   * \brief Define default destructor.
   */
  virtual ~ServiceInterfaceProxyImplInterface() = default;
  /*!
   * \brief Delete copy constructor.
   */
  ServiceInterfaceProxyImplInterface(ServiceInterfaceProxyImplInterface const &) = delete;
  /*!
   * \brief Delete move constructor.
   */
  ServiceInterfaceProxyImplInterface(ServiceInterfaceProxyImplInterface &&) = delete;
  /*!
   * \brief Delete copy assignment.
   */
  ServiceInterfaceProxyImplInterface &operator=(ServiceInterfaceProxyImplInterface const &) & = delete;
  /*!
   * \brief Delete move assignment.
   */
  ServiceInterfaceProxyImplInterface &operator=(ServiceInterfaceProxyImplInterface &&) & = delete;

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  virtual ara::core::Future<methods::add::Output> Methodadd(const std::uint32_t& num1, const std::uint32_t& num2) = 0;

  /* ---- Events --------------------------------------------------------------------------------------------------- */
  /*!
   * \brief Get the event manager object for the service event 'addInfo'
   * \return A proxy event object supporting event sample and subscription.
   */
  virtual ::amsr::socal::internal::ProxyImplEvent<std::uint32_t >* GetEventManageraddInfo() = 0;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /* ---- Field 'addResult' ---- */
  /*!
   * \brief Get the field notifier object for the service field 'addResult'
   * \return A proxy event object supporting event sample and subscription.
   */
  virtual ::amsr::socal::internal::ProxyImplEvent<std::uint32_t>*
  GetFieldNotifieraddResult() = 0;

  /*!
   * \brief Getter for the field 'addResult'
   * \return ara::core::Future with Field data element.
   */
  virtual ara::core::Future<fields::addResult::Output> FieldaddResultMethodGet() = 0;

  /*!
   * \brief Setter for the field 'addResult'
   * \param value Field value of type std::uint32_t ()
   * \return ara::core::Future with Field data element.
   */
  virtual ara::core::Future<fields::addResult::Output> FieldaddResultMethodSet(const std::uint32_t& value) = 0;
};

} //namespace internal
}  // namespace tongjidemo

#endif  // CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_INTERNAL_H_
