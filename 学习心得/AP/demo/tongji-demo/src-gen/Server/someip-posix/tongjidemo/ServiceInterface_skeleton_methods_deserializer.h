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
/**        \file  Server\someip-posix/tongjidemo/ServiceInterface_skeleton_methods_deserializer.h
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

#ifndef SERVER_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_SKELETON_METHODS_DESERIALIZER_H_
#define SERVER_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_SKELETON_METHODS_DESERIALIZER_H_

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
 * \brief Deserializer for argument 'num1' (AsrPath: /AUTOSAR/StdTypes/uint32_t)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class addRequestnum1Deserializer {
 public:
  /*!
   * \brief Constructor for addRequestnum1Deserializer
   * \param deserializer Used root deserializer
   */
  explicit addRequestnum1Deserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "addRequestnum1Deserializer") {}

/*!
 * \brief Deserialize argument 'num1'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<std::uint32_t, bool> Deserialize() {
  return Deserializenum1<RootDeserializer>(deserializer_);
}

private:
/*!
 * \brief CppImplDataTypeValue deserialization for element 'num1' (/AUTOSAR/StdTypes/uint32_t)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<std::uint32_t, bool> Deserializenum1(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialization result of element 'num1'
  bool deserialization_ok{true};

std::uint32_t num1{};
  ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__num1{parent};
deserialization_ok &= deserializer__num1.PopFront(num1) > 0U;
  return std::make_pair(num1, deserialization_ok);
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
 * \brief Deserializer for argument 'num2' (AsrPath: /AUTOSAR/StdTypes/uint32_t)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class addRequestnum2Deserializer {
 public:
  /*!
   * \brief Constructor for addRequestnum2Deserializer
   * \param deserializer Used root deserializer
   */
  explicit addRequestnum2Deserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "addRequestnum2Deserializer") {}

/*!
 * \brief Deserialize argument 'num2'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<std::uint32_t, bool> Deserialize() {
  return Deserializenum2<RootDeserializer>(deserializer_);
}

private:
/*!
 * \brief CppImplDataTypeValue deserialization for element 'num2' (/AUTOSAR/StdTypes/uint32_t)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<std::uint32_t, bool> Deserializenum2(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialization result of element 'num2'
  bool deserialization_ok{true};

std::uint32_t num2{};
  ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__num2{parent};
deserialization_ok &= deserializer__num2.PopFront(num2) > 0U;
  return std::make_pair(num2, deserialization_ok);
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
class addRequestDeserializer final {
 public:
  /*!
   * \brief Constructor
   * \param deserializer Rvalue reference to the used deserializer. The deserializer will be moved into this class.
   */
  explicit addRequestDeserializer(RootDeserializer&& deserializer)
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

    // Instantiate variable for storage of deserialized value of 'num1'
    std::uint32_t arg_num1{};
    // Instantiate variable for storage of deserialized value of 'num2'
    std::uint32_t arg_num2{};


    if (deserialization_ok) {
      // Deserialize the argument 'num1'
      addRequestnum1Deserializer<typename std::decay<RootDeserializer>::type>
        arg_num1_deserializer{&deserializer_};
      const std::pair<std::uint32_t, bool> ret_num1{arg_num1_deserializer.Deserialize()};

      // Get deserialized value and update overall deserialization result
      arg_num1 = ret_num1.first;
      deserialization_ok &= ret_num1.second;
    }

    if (deserialization_ok) {
      // Deserialize the argument 'num2'
      addRequestnum2Deserializer<typename std::decay<RootDeserializer>::type>
        arg_num2_deserializer{&deserializer_};
      const std::pair<std::uint32_t, bool> ret_num2{arg_num2_deserializer.Deserialize()};

      // Get deserialized value and update overall deserialization result
      arg_num2 = ret_num2.first;
      deserialization_ok &= ret_num2.second;
    }

    // Build output struct/tuple with deserialized values
    const Output deserialized_output{arg_num1, arg_num2};
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

#endif  // SERVER_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_SKELETON_METHODS_DESERIALIZER_H_

