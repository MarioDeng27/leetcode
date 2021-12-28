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
/**        \file  Server\someip-posix/\tongjidemo/ServiceInterface_skeleton_someip_methods.h
 *        \brief  SOME/IP skeleton method de- /serialization handling for methods and field methods of service 'ServiceInterface'
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

#ifndef SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_METHODS_H_
#define SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_METHODS_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <map>
#include "ara/core/future.h"
#include "ara/core/promise.h"
#include "ara/core/result.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "com-common/internal/memory/memory_buffer_allocator.h"
#include "someip-protocol/internal/marshalling.h"
#include "someip-protocol/internal/message.h"
#include "someip_binding/internal/methods/skeleton_method_manager.h"
#include "someip_binding/internal/methods/skeleton_request_handler.h"
#include "someip_binding/internal/methods/skeleton_response_handler.h"
#include "someip_daemon_client/internal/someip_daemon_client.h"
#include "tongjidemo/ServiceInterface.h"
#include "tongjidemo/ServiceInterface_skeleton_fields_deserializer.h"
#include "tongjidemo/ServiceInterface_skeleton_fields_serializer.h"
#include "tongjidemo/ServiceInterface_skeleton_methods_deserializer.h"
#include "tongjidemo/ServiceInterface_skeleton_methods_serializer.h"
#include "tongjidemo/ServiceInterface_types.h"
#include "tongjidemo/serviceinterface_skeleton.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {

// Forward-declaration for back-reference
class ServiceInterfaceSkeletonSomeIpBinding;


namespace methods {

/*!
 * \brief Forward-declaration for back-reference
 */
class SkeletonaddAsyncRequest;

namespace add {

/*!
 * \brief Struct combining all required types/values for creating the method manager.
 *
 * \remark generated
 */
struct SkeletonConfiguration final {

/*!
 * \brief Method name string.
 */
static constexpr vac::container::CStringView kName{"add"_sv};

/*!
 * \brief Method Id
 */
static constexpr amsr::someip_protocol::internal::MethodId kMethodId{0x7D2U};

/*!
 * \brief Skeleton SomeIp Binding
 */
using SkeletonSomeIpBinding = ServiceInterfaceSkeletonSomeIpBinding;

/*!
 * \brief Method Input struct.
 */
using Input = tongjidemo::internal::methods::add::Input;

/*!
 * \brief Async request type.
 */
using AsyncRequest = SkeletonaddAsyncRequest;

/*!
 * \brief Method Request deserializer
 */
using MethodRequestDeserializer = addRequestDeserializer<tongjidemo::internal::methods::add::Input, amsr::someip_protocol::internal::serialization::DefaultRootDeserializer>;

};

/*!
 * \brief Method manager configuration class.
 *
 * \remark generated
 */
using SkeletonaddConfiguration = amsr::someip_binding::internal::methods::SkeletonMethodManagerConfiguration<SkeletonConfiguration::kMethodId, SkeletonConfiguration::kName, SkeletonConfiguration::SkeletonSomeIpBinding, SkeletonConfiguration::Input, SkeletonConfiguration::AsyncRequest, SkeletonConfiguration::MethodRequestDeserializer>;

} // namespace add

/*!
 * \brief SOME/IP Skeleton method class for method 'add'.
 * \details Handles SOME/IP de-/serialization.
 * \remark generated
 */
using Skeletonadd = amsr::someip_binding::internal::methods::SkeletonMethodManager<add::SkeletonaddConfiguration>;

/*!
 * \brief For each method request a task of this type is assembled and is passed to the skeleton's frontend,
 * where it is being executed asynchronously according to the chosen processing mode.
 */
class SkeletonaddAsyncRequest : public ::amsr::socal::internal::PendingRequest {
 public:
  /*!
   * \brief At initialization store all relevant information, to be able to invoke the method call and route the
   * response to the binding-related part again.
   * \param skeleton A pointer to the skeleton frontend for calling the concrete method asynchronously in a separate worker thread..
   * \param skeleton_method A pointer to the skeleton method class needed to send the response after processing the method request.
   * \param header The SOME/IP header which must be stored for a possible response (in case this method is not fire & forget).
   * \param input_arguments Deserialized input arguments of the received method request.
   */
  SkeletonaddAsyncRequest(skeleton::ServiceInterfaceSkeleton* skeleton,
                                       Skeletonadd& skeleton_method,
                                       amsr::someip_protocol::internal::SomeIpMessageHeader header,
                                     ::tongjidemo::internal::methods::add::Input input_arguments
                                     ) :
                                     ::amsr::socal::internal::PendingRequest{skeleton},
                                     skeleton_{skeleton},
                                     response_handler_{skeleton_method},
                                     header_{header}
                                     ,
                                        input_arguments_{input_arguments.num1, input_arguments.num2}
                                     {
                                     }

  /*!
   * \brief Operator gets called when method invocation is planned in the frontend.
   *
   * \pre The frontend needs to make sure that it can handle a method call. For this it needs an idle thread.
   * \threadsafe FALSE
   * \exceptionsafety STRONG No undefined behavior or side effects.
   *
   * \internal
   * - Execute the requested method call.
   * - Serialize and send the return values as method response.
   * \endinternal
   *
   * \trace SPEC-4980094, SPEC-4980129
   */
  void operator()() override {
    std::uint32_t const& arg_num1{input_arguments_.num1};
    std::uint32_t const& arg_num2{input_arguments_.num2};

    ara::core::Result<tongjidemo::internal::methods::add::Output> result{skeleton_->add(arg_num1,arg_num2).GetResult()};
    if (result.HasValue()) {
      response_handler_.SerializeAndSendMethodResponse<addResponseSerializer>(header_, result.Value());
    } else {
      response_handler_.SerializeAndSendApplicationErrorMethodResponse(header_, result.Error());
    }
  }

 private:
  /*!
  * \brief Pointer to the skeleton to invoke the method request call.
  */
  skeleton::ServiceInterfaceSkeleton* skeleton_;

  /*!
   * \brief Binding-related handler to serialize and send a response right after the method call.
   */
  amsr::someip_binding::internal::methods::SkeletonResponseHandler<Skeletonadd> response_handler_;

  /*!
   * \brief Buffer the SOME/IP header from the request for the response with the corresponding client ID and session ID.
   */
  amsr::someip_protocol::internal::SomeIpMessageHeader header_;

  /*!
   * \brief Stores context of the method's arguments for further processing.
   */
   ::tongjidemo::internal::methods::add::Input input_arguments_;
};

}  // namespace methods


namespace fields {

/*!
 * \brief Forward-declaration for back-reference
 */
class SkeletonaddResultGetAsyncRequest;

namespace addresultget {

/*!
 * \brief Struct combining all required types/values for creating the method manager.
 *
 * \remark generated
 */
struct SkeletonConfiguration final {

/*!
 * \brief Method name string.
 */
static constexpr vac::container::CStringView kName{"addResultGet"_sv};

/*!
 * \brief Method Id
 */
static constexpr amsr::someip_protocol::internal::MethodId kMethodId{0x7D0U};

/*!
 * \brief Skeleton SomeIp Binding
 */
using SkeletonSomeIpBinding = ServiceInterfaceSkeletonSomeIpBinding;

/*!
 * \brief Method Input struct.
 */
using Input = tongjidemo::internal::fields::addResultGet::Input;

/*!
 * \brief Async request type.
 */
using AsyncRequest = SkeletonaddResultGetAsyncRequest;

/*!
 * \brief Method Request deserializer
 */
using MethodRequestDeserializer = addResultGetRequestDeserializer<tongjidemo::internal::fields::addResultGet::Input, amsr::someip_protocol::internal::serialization::DefaultRootDeserializer>;

};

/*!
 * \brief Method manager configuration class.
 *
 * \remark generated
 */
using SkeletonaddResultGetConfiguration = amsr::someip_binding::internal::methods::SkeletonMethodManagerConfiguration<SkeletonConfiguration::kMethodId, SkeletonConfiguration::kName, SkeletonConfiguration::SkeletonSomeIpBinding, SkeletonConfiguration::Input, SkeletonConfiguration::AsyncRequest, SkeletonConfiguration::MethodRequestDeserializer>;

} // namespace addresultget

/*!
 * \brief SOME/IP Skeleton method class for method 'addResultGet'.
 * \details Handles SOME/IP de-/serialization.
 * \remark generated
 */
using SkeletonaddResultGet = amsr::someip_binding::internal::methods::SkeletonMethodManager<addresultget::SkeletonaddResultGetConfiguration>;

/*!
 * \brief For each method request a task of this type is assembled and is passed to the skeleton's frontend,
 * where it is being executed asynchronously according to the chosen processing mode.
 */
class SkeletonaddResultGetAsyncRequest : public ::amsr::socal::internal::PendingRequest {
 public:
  /*!
   * \brief At initialization store all relevant information, to be able to invoke the method call and route the
   * response to the binding-related part again.
   * \param skeleton A pointer to the skeleton frontend for calling the concrete method asynchronously in a separate worker thread..
   * \param skeleton_method A pointer to the skeleton method class needed to send the response after processing the method request.
   * \param header The SOME/IP header which must be stored for a possible response (in case this method is not fire & forget).
   * \param input_arguments Dummy value, because method has no input arguments
   */
  SkeletonaddResultGetAsyncRequest(skeleton::ServiceInterfaceSkeleton* skeleton,
                                       SkeletonaddResultGet& skeleton_method,
                                       amsr::someip_protocol::internal::SomeIpMessageHeader header,
                                     ::tongjidemo::internal::fields::addResultGet::Input input_arguments
                                     ) :
                                     ::amsr::socal::internal::PendingRequest{skeleton},
                                     skeleton_{skeleton},
                                     response_handler_{skeleton_method},
                                     header_{header}
                                                                          {
                                      (void)input_arguments;
                                     }

  /*!
   * \brief Operator gets called when method invocation is planned in the frontend.
   *
   * \pre The frontend needs to make sure that it can handle a method call. For this it needs an idle thread.
   * \threadsafe FALSE
   * \exceptionsafety STRONG No undefined behavior or side effects.
   *
   * \internal
   * - Execute the requested method call.
   * - Serialize and send the return values as method response.
   * \endinternal
   *
   * \trace SPEC-4980094, SPEC-4980129
   */
  void operator()() override {

    ara::core::Result<tongjidemo::internal::fields::addResult::Output> result{skeleton_->addResult.Get().GetResult()};
    if (result.HasValue()) {
      ::tongjidemo::internal::fields::addResultGet::Output result_value{result.Value()};
      response_handler_.SerializeAndSendMethodResponse<addResultGetResponseSerializer>(header_, result_value);
    } else {
      response_handler_.SerializeAndSendApplicationErrorMethodResponse(header_, result.Error());
    }
  }

 private:
  /*!
  * \brief Pointer to the skeleton to invoke the method request call.
  */
  skeleton::ServiceInterfaceSkeleton* skeleton_;

  /*!
   * \brief Binding-related handler to serialize and send a response right after the method call.
   */
  amsr::someip_binding::internal::methods::SkeletonResponseHandler<SkeletonaddResultGet> response_handler_;

  /*!
   * \brief Buffer the SOME/IP header from the request for the response with the corresponding client ID and session ID.
   */
  amsr::someip_protocol::internal::SomeIpMessageHeader header_;

};

}  // namespace fields


namespace fields {

/*!
 * \brief Forward-declaration for back-reference
 */
class SkeletonaddResultSetAsyncRequest;

namespace addresultset {

/*!
 * \brief Struct combining all required types/values for creating the method manager.
 *
 * \remark generated
 */
struct SkeletonConfiguration final {

/*!
 * \brief Method name string.
 */
static constexpr vac::container::CStringView kName{"addResultSet"_sv};

/*!
 * \brief Method Id
 */
static constexpr amsr::someip_protocol::internal::MethodId kMethodId{0x7D1U};

/*!
 * \brief Skeleton SomeIp Binding
 */
using SkeletonSomeIpBinding = ServiceInterfaceSkeletonSomeIpBinding;

/*!
 * \brief Method Input struct.
 */
using Input = tongjidemo::internal::fields::addResultSet::Input;

/*!
 * \brief Async request type.
 */
using AsyncRequest = SkeletonaddResultSetAsyncRequest;

/*!
 * \brief Method Request deserializer
 */
using MethodRequestDeserializer = addResultSetRequestDeserializer<tongjidemo::internal::fields::addResultSet::Input, amsr::someip_protocol::internal::serialization::DefaultRootDeserializer>;

};

/*!
 * \brief Method manager configuration class.
 *
 * \remark generated
 */
using SkeletonaddResultSetConfiguration = amsr::someip_binding::internal::methods::SkeletonMethodManagerConfiguration<SkeletonConfiguration::kMethodId, SkeletonConfiguration::kName, SkeletonConfiguration::SkeletonSomeIpBinding, SkeletonConfiguration::Input, SkeletonConfiguration::AsyncRequest, SkeletonConfiguration::MethodRequestDeserializer>;

} // namespace addresultset

/*!
 * \brief SOME/IP Skeleton method class for method 'addResultSet'.
 * \details Handles SOME/IP de-/serialization.
 * \remark generated
 */
using SkeletonaddResultSet = amsr::someip_binding::internal::methods::SkeletonMethodManager<addresultset::SkeletonaddResultSetConfiguration>;

/*!
 * \brief For each method request a task of this type is assembled and is passed to the skeleton's frontend,
 * where it is being executed asynchronously according to the chosen processing mode.
 */
class SkeletonaddResultSetAsyncRequest : public ::amsr::socal::internal::PendingRequest {
 public:
  /*!
   * \brief At initialization store all relevant information, to be able to invoke the method call and route the
   * response to the binding-related part again.
   * \param skeleton A pointer to the skeleton frontend for calling the concrete method asynchronously in a separate worker thread..
   * \param skeleton_method A pointer to the skeleton method class needed to send the response after processing the method request.
   * \param header The SOME/IP header which must be stored for a possible response (in case this method is not fire & forget).
   * \param input_arguments Deserialized input arguments of the received method request.
   */
  SkeletonaddResultSetAsyncRequest(skeleton::ServiceInterfaceSkeleton* skeleton,
                                       SkeletonaddResultSet& skeleton_method,
                                       amsr::someip_protocol::internal::SomeIpMessageHeader header,
                                     ::tongjidemo::internal::fields::addResultSet::Input input_arguments
                                     ) :
                                     ::amsr::socal::internal::PendingRequest{skeleton},
                                     skeleton_{skeleton},
                                     response_handler_{skeleton_method},
                                     header_{header}
                                     ,
                                        input_arguments_{input_arguments.in_val}
                                     {
                                     }

  /*!
   * \brief Operator gets called when method invocation is planned in the frontend.
   *
   * \pre The frontend needs to make sure that it can handle a method call. For this it needs an idle thread.
   * \threadsafe FALSE
   * \exceptionsafety STRONG No undefined behavior or side effects.
   *
   * \internal
   * - Execute the requested method call.
   * - Serialize and send the return values as method response.
   * \endinternal
   *
   * \trace SPEC-4980094, SPEC-4980129
   */
  void operator()() override {
    std::uint32_t const& arg_in_val{input_arguments_.in_val};

    ara::core::Result<tongjidemo::internal::fields::addResult::Output> result{skeleton_->addResult.Set(arg_in_val).GetResult()};
    if (result.HasValue()) {
      ::tongjidemo::internal::fields::addResultSet::Output result_value{result.Value()};
      response_handler_.SerializeAndSendMethodResponse<addResultSetResponseSerializer>(header_, result_value);
    } else {
      response_handler_.SerializeAndSendApplicationErrorMethodResponse(header_, result.Error());
    }
  }

 private:
  /*!
  * \brief Pointer to the skeleton to invoke the method request call.
  */
  skeleton::ServiceInterfaceSkeleton* skeleton_;

  /*!
   * \brief Binding-related handler to serialize and send a response right after the method call.
   */
  amsr::someip_binding::internal::methods::SkeletonResponseHandler<SkeletonaddResultSet> response_handler_;

  /*!
   * \brief Buffer the SOME/IP header from the request for the response with the corresponding client ID and session ID.
   */
  amsr::someip_protocol::internal::SomeIpMessageHeader header_;

  /*!
   * \brief Stores context of the method's arguments for further processing.
   */
   ::tongjidemo::internal::fields::addResultSet::Input input_arguments_;
};

}  // namespace fields

}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

#endif  // SERVER_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_SKELETON_SOMEIP_METHODS_H_

