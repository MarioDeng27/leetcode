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
/**        \file  Client\someip-posix/\tongjidemo/ServiceInterface_proxy_someip_methods.h
 *        \brief  SOME/IP proxy method de- /serialization handling for methods and field methods of service 'ServiceInterface'
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

#ifndef CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_METHODS_H_
#define CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_METHODS_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "ara/com/com_error_domain.h"
#include "com-common/internal/memory/memory_buffer_allocator.h"
#include "someip_binding/internal/methods/proxy_method_manager.h"
#include "tongjidemo/ServiceInterface_proxy_fields_deserializer.h"
#include "tongjidemo/ServiceInterface_proxy_fields_serializer.h"
#include "tongjidemo/ServiceInterface_proxy_methods_deserializer.h"
#include "tongjidemo/ServiceInterface_proxy_methods_serializer.h"
#include "tongjidemo/ServiceInterface_types.h"

namespace tongjidemo {
namespace someip_binding {
namespace internal {

// Forward-declaration for back-reference
class ServiceInterfaceProxySomeIpBinding;


namespace methods {

namespace add {

/*!
 * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
 */
class LocalErrorCodeBuilder {
 public:
  /*!
   * \brief Constructor.
   * \param logger Passed in by the method to log errors and debug messages.
   */
  explicit LocalErrorCodeBuilder(amsr::com_common::internal::logging::AraComLogger& logger) : logger_{logger} {}

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   *
   * \details The builder supports all error domains that are referenced by errors in \c
   * ClientServerOperation.possibleApError and \c ClientServerOperation.possibleApErrorSet.
   * If an error domain id is passed that is not supported, an \c ComErrc::network_binding_failure error code
   * is created.
   *
   * \param error_domain_id The unique error domain identifier.
   * \param error_code_value  The value of the error code.
   * \param support_data The support data.
   * \param user_message  The user message.
   *
   * \trace SWS_CM_10440 If the error domain id or the error code value are invalid an \c ErrorCode(ComErrc::network_binding_failure) is returned.
   *
   * \return The error code.
   */
  ara::core::ErrorCode CreateErrorCode(ara::core::ErrorDomain::CodeType const error_code_value,
                                       ara::core::ErrorDomain::IdType const error_domain_id,
                                       ara::core::ErrorDomain::SupportDataType const support_data,
                                       ara::core::ErrorDomain::StringType const user_message) const {
    logger_.LogDebug(
        [&error_code_value, &error_domain_id, &support_data, &user_message](ara::log::LogStream& s) {
          s << "Create ErrorCode with error code value ='" << error_code_value << "', domain id '" << error_domain_id
            << "', support data '" << support_data << "', user message '" << user_message << "'";
        },
        __func__, __LINE__);

    switch (error_domain_id) {
      default: {
        // invalid error domain id
        std::stringstream error_message;
        error_message << "Unknown error domain id ' " << error_domain_id << "'" << error_domain_id << "'";
        logger_.LogError([&error_message](ara::log::LogStream& s) { s << error_message.str(); }, __func__, __LINE__);
        return {::ara::com::ComErrc::network_binding_failure, error_message.str().c_str()};
      }
    }

  }

 private:


  /*!
   * \brief Reference to the logger of the builder.
   */
  amsr::com_common::internal::logging::AraComLogger& logger_;
};


/*!
 * \brief Struct combining all required types/values for creating the method manager.
 *
 * \remark generated
 */
struct ProxyConfiguration {

/*!
 * \brief Proxy SomeIp Binding
 */
using ProxySomeIpBinding = ServiceInterfaceProxySomeIpBinding;

/*!
 * \brief Request serializer
 */
using RequestSerializer = addRequestSerializer;

/*!
 * \brief Method name string.
 */
static constexpr vac::container::CStringView kName{"add"_sv};

/*!
 * \brief Method Id
 */
static constexpr amsr::someip_protocol::internal::MethodId kMethodId{0x7D2U};

/*!
 * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
 */
using ErrorCodeBuilder = LocalErrorCodeBuilder;

/*!
 * \brief Method Input struct.
 */
using Input = tongjidemo::internal::methods::add::Input;

/*!
 * \brief Method Output struct.
 */
using Output = tongjidemo::internal::methods::add::Output;

/*!
 * \brief OK Response deserializer
 */
using ResponseOkDeserializer = addResponseOkDeserializer<tongjidemo::internal::methods::add::Output, amsr::someip_protocol::internal::serialization::DefaultRootDeserializer>;

};


/*!
 * \brief Method manager configuration class.
 *
 * \remark generated
 */
using ProxyaddConfiguration = amsr::someip_binding::internal::methods::ProxyMethodManagerConfiguration<ProxyConfiguration::kMethodId, ProxyConfiguration::kName, ProxyConfiguration::ErrorCodeBuilder, ProxyConfiguration::ProxySomeIpBinding, ProxyConfiguration::Input, ProxyConfiguration::RequestSerializer, ProxyConfiguration::Output, ProxyConfiguration::ResponseOkDeserializer>;

}  // namespace add

/*!
 * \brief SOME/IP Proxy method class for 'add'.
 * \details Handles SOME/IP de-/serialization.
 *
 * \remark generated
 */
using Proxyadd = amsr::someip_binding::internal::methods::ProxyMethodManager<add::ProxyaddConfiguration>;

}  // namespace methods

namespace fields {

namespace addresultget {

/*!
 * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
 */
class LocalErrorCodeBuilder {
 public:
  /*!
   * \brief Constructor.
   * \param logger Passed in by the method to log errors and debug messages.
   */
  explicit LocalErrorCodeBuilder(amsr::com_common::internal::logging::AraComLogger& logger) : logger_{logger} {}

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   *
   * \details The builder supports all error domains that are referenced by errors in \c
   * ClientServerOperation.possibleApError and \c ClientServerOperation.possibleApErrorSet.
   * If an error domain id is passed that is not supported, an \c ComErrc::network_binding_failure error code
   * is created.
   *
   * \param error_domain_id The unique error domain identifier.
   * \param error_code_value  The value of the error code.
   * \param support_data The support data.
   * \param user_message  The user message.
   *
   * \trace SWS_CM_10440 If the error domain id or the error code value are invalid an \c ErrorCode(ComErrc::network_binding_failure) is returned.
   *
   * \return The error code.
   */
  ara::core::ErrorCode CreateErrorCode(ara::core::ErrorDomain::CodeType const error_code_value,
                                       ara::core::ErrorDomain::IdType const error_domain_id,
                                       ara::core::ErrorDomain::SupportDataType const support_data,
                                       ara::core::ErrorDomain::StringType const user_message) const {
    logger_.LogDebug(
        [&error_code_value, &error_domain_id, &support_data, &user_message](ara::log::LogStream& s) {
          s << "Create ErrorCode with error code value ='" << error_code_value << "', domain id '" << error_domain_id
            << "', support data '" << support_data << "', user message '" << user_message << "'";
        },
        __func__, __LINE__);

    switch (error_domain_id) {
      default: {
        // invalid error domain id
        std::stringstream error_message;
        error_message << "Unknown error domain id ' " << error_domain_id << "'" << error_domain_id << "'";
        logger_.LogError([&error_message](ara::log::LogStream& s) { s << error_message.str(); }, __func__, __LINE__);
        return {::ara::com::ComErrc::network_binding_failure, error_message.str().c_str()};
      }
    }

  }

 private:


  /*!
   * \brief Reference to the logger of the builder.
   */
  amsr::com_common::internal::logging::AraComLogger& logger_;
};


/*!
 * \brief Struct combining all required types/values for creating the method manager.
 *
 * \remark generated
 */
struct ProxyConfiguration {

/*!
 * \brief Proxy SomeIp Binding
 */
using ProxySomeIpBinding = ServiceInterfaceProxySomeIpBinding;

/*!
 * \brief Request serializer
 */
using RequestSerializer = addResultGetRequestSerializer;

/*!
 * \brief Method name string.
 */
static constexpr vac::container::CStringView kName{"addResultGet"_sv};

/*!
 * \brief Method Id
 */
static constexpr amsr::someip_protocol::internal::MethodId kMethodId{0x7D0U};

/*!
 * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
 */
using ErrorCodeBuilder = LocalErrorCodeBuilder;

/*!
 * \brief Method Input struct.
 */
using Input = tongjidemo::internal::fields::addResultGet::Input;

/*!
 * \brief Method Output struct.
 */
using Output = tongjidemo::internal::fields::addResult::Output;

/*!
 * \brief OK Response deserializer
 */
using ResponseOkDeserializer = addResultGetResponseOkDeserializer<tongjidemo::internal::fields::addResult::Output, amsr::someip_protocol::internal::serialization::DefaultRootDeserializer>;

};


/*!
 * \brief Method manager configuration class.
 *
 * \remark generated
 */
using ProxyaddResultGetConfiguration = amsr::someip_binding::internal::methods::ProxyMethodManagerConfiguration<ProxyConfiguration::kMethodId, ProxyConfiguration::kName, ProxyConfiguration::ErrorCodeBuilder, ProxyConfiguration::ProxySomeIpBinding, ProxyConfiguration::Input, ProxyConfiguration::RequestSerializer, ProxyConfiguration::Output, ProxyConfiguration::ResponseOkDeserializer>;

}  // namespace addresultget

/*!
 * \brief SOME/IP Proxy method class for 'addResultGet'.
 * \details Handles SOME/IP de-/serialization.
 *
 * \remark generated
 */
using ProxyaddResultGet = amsr::someip_binding::internal::methods::ProxyMethodManager<addresultget::ProxyaddResultGetConfiguration>;

}  // namespace fields

namespace fields {

namespace addresultset {

/*!
 * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
 */
class LocalErrorCodeBuilder {
 public:
  /*!
   * \brief Constructor.
   * \param logger Passed in by the method to log errors and debug messages.
   */
  explicit LocalErrorCodeBuilder(amsr::com_common::internal::logging::AraComLogger& logger) : logger_{logger} {}

  /*!
   * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
   *
   * \details The builder supports all error domains that are referenced by errors in \c
   * ClientServerOperation.possibleApError and \c ClientServerOperation.possibleApErrorSet.
   * If an error domain id is passed that is not supported, an \c ComErrc::network_binding_failure error code
   * is created.
   *
   * \param error_domain_id The unique error domain identifier.
   * \param error_code_value  The value of the error code.
   * \param support_data The support data.
   * \param user_message  The user message.
   *
   * \trace SWS_CM_10440 If the error domain id or the error code value are invalid an \c ErrorCode(ComErrc::network_binding_failure) is returned.
   *
   * \return The error code.
   */
  ara::core::ErrorCode CreateErrorCode(ara::core::ErrorDomain::CodeType const error_code_value,
                                       ara::core::ErrorDomain::IdType const error_domain_id,
                                       ara::core::ErrorDomain::SupportDataType const support_data,
                                       ara::core::ErrorDomain::StringType const user_message) const {
    logger_.LogDebug(
        [&error_code_value, &error_domain_id, &support_data, &user_message](ara::log::LogStream& s) {
          s << "Create ErrorCode with error code value ='" << error_code_value << "', domain id '" << error_domain_id
            << "', support data '" << support_data << "', user message '" << user_message << "'";
        },
        __func__, __LINE__);

    switch (error_domain_id) {
      default: {
        // invalid error domain id
        std::stringstream error_message;
        error_message << "Unknown error domain id ' " << error_domain_id << "'" << error_domain_id << "'";
        logger_.LogError([&error_message](ara::log::LogStream& s) { s << error_message.str(); }, __func__, __LINE__);
        return {::ara::com::ComErrc::network_binding_failure, error_message.str().c_str()};
      }
    }

  }

 private:


  /*!
   * \brief Reference to the logger of the builder.
   */
  amsr::com_common::internal::logging::AraComLogger& logger_;
};


/*!
 * \brief Struct combining all required types/values for creating the method manager.
 *
 * \remark generated
 */
struct ProxyConfiguration {

/*!
 * \brief Proxy SomeIp Binding
 */
using ProxySomeIpBinding = ServiceInterfaceProxySomeIpBinding;

/*!
 * \brief Request serializer
 */
using RequestSerializer = addResultSetRequestSerializer;

/*!
 * \brief Method name string.
 */
static constexpr vac::container::CStringView kName{"addResultSet"_sv};

/*!
 * \brief Method Id
 */
static constexpr amsr::someip_protocol::internal::MethodId kMethodId{0x7D1U};

/*!
 * \brief Builder to create an \c ara::core::ErrorCode from a specific error domain.
 */
using ErrorCodeBuilder = LocalErrorCodeBuilder;

/*!
 * \brief Method Input struct.
 */
using Input = tongjidemo::internal::fields::addResultSet::Input;

/*!
 * \brief Method Output struct.
 */
using Output = tongjidemo::internal::fields::addResult::Output;

/*!
 * \brief OK Response deserializer
 */
using ResponseOkDeserializer = addResultSetResponseOkDeserializer<tongjidemo::internal::fields::addResult::Output, amsr::someip_protocol::internal::serialization::DefaultRootDeserializer>;

};


/*!
 * \brief Method manager configuration class.
 *
 * \remark generated
 */
using ProxyaddResultSetConfiguration = amsr::someip_binding::internal::methods::ProxyMethodManagerConfiguration<ProxyConfiguration::kMethodId, ProxyConfiguration::kName, ProxyConfiguration::ErrorCodeBuilder, ProxyConfiguration::ProxySomeIpBinding, ProxyConfiguration::Input, ProxyConfiguration::RequestSerializer, ProxyConfiguration::Output, ProxyConfiguration::ResponseOkDeserializer>;

}  // namespace addresultset

/*!
 * \brief SOME/IP Proxy method class for 'addResultSet'.
 * \details Handles SOME/IP de-/serialization.
 *
 * \remark generated
 */
using ProxyaddResultSet = amsr::someip_binding::internal::methods::ProxyMethodManager<addresultset::ProxyaddResultSetConfiguration>;

}  // namespace fields

}  // namespace internal
}  // namespace someip_binding
}  // namespace tongjidemo

#endif  // CLIENT_SOMEIP_POSIX__TONGJIDEMO_SERVICEINTERFACE_PROXY_SOMEIP_METHODS_H_

