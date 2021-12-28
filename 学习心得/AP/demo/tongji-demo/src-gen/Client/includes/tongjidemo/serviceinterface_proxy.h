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
/**        \file  Client\includes\tongjidemo/serviceinterface_proxy.h
 *        \brief  Proxy for service 'ServiceInterface'.
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

#ifndef CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_H_
#define CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_H_

/*!
 * \trace SPEC-4980240
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>
#include "ara/com/runtime.h"
#include "socal/internal/fields/proxy_field.h"
#include "socal/internal/find_service_observers_manager.h"
#include "socal/internal/handle_type.h"
#include "socal/internal/methods/proxy_method.h"
#include "socal/internal/proxy.h"
#include "socal/internal/proxy_event.h"
#include "tongjidemo/ServiceInterface_proxy_internal.h"
#include "tongjidemo/ServiceInterface_types.h"
#include "tongjidemo/serviceinterface_common.h"

/*!
 * \trace SPEC-4980240
 */
namespace tongjidemo {

/*!
 * \trace SPEC-4980242
 */
namespace proxy {

/*!
 * \trace SPEC-4980244
 */
namespace methods {


/*!
 * \brief Type alias for service method 'add', that is part of the proxy.
 *
 * \trace SPEC-4980346 (Service proxy method class)
 */
using add = ::amsr::socal::internal::methods::MethodParameters<
  
    std::uint32_t const&,std::uint32_t const&>::
        ProxyMethod<tongjidemo::ServiceInterface, tongjidemo::internal::ServiceInterfaceProxyImplInterface, tongjidemo::internal::ServiceInterfaceHandleType, tongjidemo::internal::methods::add,
                    &tongjidemo::internal::ServiceInterfaceProxyImplInterface::Methodadd>;

}  // namespace methods

/*!
 * \trace SPEC-4980243
 */
namespace events {

/*!
 * \brief Type alias for service event 'addInfo', that is part of the proxy.
 *
 * \trace SPEC-4980345 (Service proxy Event class)
 */
using addInfo =
    ::amsr::socal::internal::ProxyEvent<tongjidemo::ServiceInterface, tongjidemo::internal::ServiceInterfaceProxyImplInterface, tongjidemo::internal::ServiceInterfaceHandleType, std::uint32_t,
                                   ::amsr::socal::internal::ProxyImplEvent<std::uint32_t
                                                                      >,
                                   &tongjidemo::internal::ServiceInterfaceProxyImplInterface::GetEventManageraddInfo>;

}  // namespace events

/*!
 * \trace SPEC-4980245
 */
namespace fields {
/* ---- Type aliases for field 'addResult' ---- */

/*!
 * \brief Type alias for the notifier of service field 'addResult'.
 */
using FieldNotifieraddResult =
    ::amsr::socal::internal::ProxyEvent<tongjidemo::ServiceInterface, tongjidemo::internal::ServiceInterfaceProxyImplInterface, tongjidemo::internal::ServiceInterfaceHandleType, std::uint32_t,
                                   ::amsr::socal::internal::ProxyImplEvent<std::uint32_t
                                   >,
                                   &tongjidemo::internal::ServiceInterfaceProxyImplInterface::GetFieldNotifieraddResult>;
/*!
 * \brief Type alias for the notifier configuration of field 'addResult'.
 */
using FieldNotifierConfigaddResult = ::amsr::socal::internal::fields::ProxyFieldParams::HasNotifier<true, FieldNotifieraddResult>;
/*!
 * \brief Type alias for the getter method of service field 'addResult'.
 */
using FieldMethodGetaddResult = ::amsr::socal::internal::methods::MethodParameters<void>::ProxyMethod<tongjidemo::ServiceInterface, tongjidemo::internal::ServiceInterfaceProxyImplInterface, tongjidemo::internal::ServiceInterfaceHandleType, tongjidemo::internal::fields::addResult, &tongjidemo::internal::ServiceInterfaceProxyImplInterface::FieldaddResultMethodGet>;

/*!
 * \brief Type alias for the getter configuration of field 'addResult'.
 */
using FieldGetterConfigaddResult = ::amsr::socal::internal::fields::ProxyFieldParams::HasGetter<true, FieldMethodGetaddResult>;

/*!
 * \brief Type alias for the setter method of service field 'addResult'.
 */
using FieldMethodSetaddResult = ::amsr::socal::internal::methods::MethodParameters<const std::uint32_t&>::ProxyMethod<tongjidemo::ServiceInterface, tongjidemo::internal::ServiceInterfaceProxyImplInterface, tongjidemo::internal::ServiceInterfaceHandleType, tongjidemo::internal::fields::addResult, &tongjidemo::internal::ServiceInterfaceProxyImplInterface::FieldaddResultMethodSet>;
/*!
 * \brief Type alias for the setter configuration of field 'addResult'.
 */
using FieldSetterConfigaddResult = ::amsr::socal::internal::fields::ProxyFieldParams::HasSetter<true, FieldMethodSetaddResult>;

/*!
 * \brief Field name.
 */
struct addResultName {
  /*!
   * \brief Field name string.
   */
  static constexpr vac::container::CStringView Name = "addResult"_sv;
};

/*!
 * \brief Type alias for the parameterization of field 'addResult'.
 */
using FieldConfigaddResult = ::amsr::socal::internal::fields::ProxyFieldConfig<tongjidemo::internal::ServiceInterfaceProxyImplInterface, FieldNotifierConfigaddResult, FieldGetterConfigaddResult, FieldSetterConfigaddResult, addResultName>;

/*!
 * \brief Type alias for the field 'addResult'.
 *
 * \trace SPEC-5951150 (Service proxy field class)
 */
using addResult =
    ::amsr::socal::internal::fields::ProxyField<tongjidemo::ServiceInterface, tongjidemo::internal::ServiceInterfaceHandleType, std::uint32_t, FieldConfigaddResult>;

}  // namespace fields

/*!
 * \brief Proxy class for the service 'ServiceInterface'.
 * \vpublic
 *
 * \trace SPEC-4980344 (Service proxy class)
 */
class ServiceInterfaceProxy : public ::amsr::socal::internal::Proxy<tongjidemo::ServiceInterface, tongjidemo::internal::ServiceInterfaceProxyImplInterface, tongjidemo::internal::ServiceInterfaceHandleType> {
 public:

  /*!
   * \brief Type alias for the ProxyImplInterface.
   */
  using ProxyImplInterface = tongjidemo::internal::ServiceInterfaceProxyImplInterface;

  /*!
   * \brief Constructor of ServiceInterfaceProxy. Constructor takes a handle returned by
   * ServiceInterfaceProxy::FindService() method or provided as parameter to the callback handler of
   * ServiceInterfaceProxy::StartFindService().
   *
   * \details Because of internal resource management strategy, all created proxies shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   *
   * \param handle The identification of the service the proxy should represent. Handles are generated by synchronous
   * ServiceInterfaceProxy::FindService or asynchronous ServiceInterfaceProxy::StartFindService.
   * The handle object passed as a parameter shall be a handle returned by a FindService call for this specific service.
   * Passing handles from different services is currently possible, but is detected. An exception is raised as documented below.
   *
   * \throws ara::com::ComException (ComErrc::unknown_instance_identifier) If the InstanceIdentifier could not be resolved.
   * \throws std::bad_alloc if the proxy backend could not be spawned.
   * \throws std::bad_cast if the given handle object does not match the handle of the service and thus a dynamic_cast to the concrete
   * service type fails.
   *
   * \vpublic
   * \trace SPEC-4980371 (Creation of service proxy)
   */
  explicit ServiceInterfaceProxy(HandleType const& handle);

  /*!
   * \brief Unregister the proxy from the communication middleware.
   *
   * \details This call will be blocked until all current events/methods' callbacks are finished/canceled.
   *
   * \vpublic
   */
  virtual ~ServiceInterfaceProxy();

 private:
  /*!
   * \brief Type alias for the base class.
   */
  using Base = ::amsr::socal::internal::Proxy<tongjidemo::ServiceInterface, ProxyImplInterface, tongjidemo::internal::ServiceInterfaceHandleType>;

  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;

 public:

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

    /*!
     * \brief Call of service method 'add'.
     * \vpublic
     * \threadsafe TRUE
     *
     * \param num1 IN parameter of type std::uint32_t
     * \param num2 IN parameter of type std::uint32_t
     * \return ara::core::Future which gets resolved with an ara::core::Result on reception of a positive or negative
     *         response or if any binding internal error occurred.
     *         Output arguments:
     *         - result OUT parameter of type std::uint32_t
     *         Possible error codes:
     *         - ara::com::ComErrC::service_not_available
     *         - ara::com::ComErrC::network_binding_failure
     *
     * \trace SPEC-4980380
     */
  methods::add add;

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Event 'addInfo' which can be used by application developer.
   * \details
   * Data of type std::uint32_t 
   * \vpublic
   */
  events::addInfo addInfo;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Field 'addResult' which can be used by application developer.
   * \details
   * Data of type std::uint32_t 
   * \vpublic
   */
  fields::addResult addResult;
};

}  // namespace proxy
}  // namespace tongjidemo

#endif  // CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_PROXY_H_

