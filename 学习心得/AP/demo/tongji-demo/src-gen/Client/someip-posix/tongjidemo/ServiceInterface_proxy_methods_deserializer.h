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
/**        \file  Client\someip-posix/tongjidemo/ServiceInterface_proxy_methods_deserializer.h
 *        \brief  SOME/IP packet deserializer of service 'ServiceInterface'.
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

#ifndef CLIENT_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_PROXY_METHODS_DESERIALIZER_H_
#define CLIENT_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_PROXY_METHODS_DESERIALIZER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <utility>
#include "someip-protocol/internal/marshalling.h"
#include "tongjidemo/serviceinterface_common.h"

namespace tongjidemo {

namespace someip_binding {
namespace internal {
namespace methods {

/* ---- Method 'add' ---- */

  /*!
 * \brief Deserializer for argument 'result' (AsrPath: /AUTOSAR/StdTypes/uint32_t)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class addResponseOkresultDeserializer {
 public:
  /*!
   * \brief Constructor for addResponseOkresultDeserializer
   * \param deserializer Used root deserializer
   */
  explicit addResponseOkresultDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "addResponseOkresultDeserializer") {}

/*!
 * \brief Deserialize argument 'result'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<std::uint32_t, bool> Deserialize() {
  return Deserializeresult<RootDeserializer>(deserializer_);
}

private:
/*!
 * \brief CppImplDataTypeValue deserialization for element 'result' (/AUTOSAR/StdTypes/uint32_t)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<std::uint32_t, bool> Deserializeresult(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialization result of element 'result'
  bool deserialization_ok{true};

std::uint32_t result{};
  ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__result{parent};
deserialization_ok &= deserializer__result.PopFront(result) > 0U;
  return std::make_pair(result, deserialization_ok);
}

  /*!
   * \brief Root deserializer
   */
  RootDeserializer* deserializer_;
  /*!
   * \brief Logger for tracing and debugging
   */
  amsr::com_common::internal::logging::AraComLogger logger_;
};



/*!
 * \brief Deserializer for a SOME/IP packet of method 'add'.
 *
 * \tparam Output Type of data structure storing all deserialized in-/output arguments.
 *         Type must support member initializer lists. Typically a struct or a std::tuple is used.
 * \tparam RootDeserializer Used root deserializer.
 */
template <typename Output, typename RootDeserializer>
class addResponseOkDeserializer final {
 public:
  /*!
   * \brief Constructor
   * \param deserializer Rvalue reference to the used deserializer. The deserializer will be moved into this class.
   */
  explicit addResponseOkDeserializer(RootDeserializer&& deserializer)
      : deserializer_{std::move(deserializer)} {}

  /*!
   * \brief Deserialize the SOME/IP packet.
   *
   * \internal
   * - Deserialize SOME/IP packet.
   * - Update the overall deserialization result.
   * - Return a pair with deserialized result and a boolean indicating the success/failure of deserialization.
   * \endinternal
   *
   * \return A pair with the deserialized output and a flag indicating if deserialization was successful or not.
   */
  std::pair<Output, bool> Deserialize() {
    bool deserialization_ok{true};

    // Instantiate variable for storage of deserialized value of 'result'
    std::uint32_t arg_result{};


    if (deserialization_ok) {
      // Deserialize the argument 'result'
      addResponseOkresultDeserializer<typename std::decay<RootDeserializer>::type>
        arg_result_deserializer{&deserializer_};
      const std::pair<std::uint32_t, bool> ret_result{arg_result_deserializer.Deserialize()};

      // Get deserialized value and update overall deserialization result
      arg_result = ret_result.first;
      deserialization_ok &= ret_result.second;
    }

    // Build output struct/tuple with deserialized values
    const Output deserialized_output{arg_result};
    return std::make_pair(deserialized_output, deserialization_ok);
  }

 private:
  /*!
   * \brief Used root deserializer.
   */
  RootDeserializer deserializer_;

};


}  // namespace methods
}  // namespace internal
}  // namespace someip_binding

}  // namespace tongjidemo

#endif  // CLIENT_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_PROXY_METHODS_DESERIALIZER_H_

