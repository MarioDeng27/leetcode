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
/**        \file  Server\someip-posix/tongjidemo/ServiceInterface_skeleton_fields_deserializer.h
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

#ifndef SERVER_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_SKELETON_FIELDS_DESERIALIZER_H_
#define SERVER_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_SKELETON_FIELDS_DESERIALIZER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <utility>
#include "someip-protocol/internal/marshalling.h"
#include "tongjidemo/serviceinterface_common.h"

namespace tongjidemo {

namespace someip_binding {
namespace internal {
namespace fields {

/* ---- Field method 'addResultGet' ---- */


/*!
 * \brief Deserializer for a SOME/IP packet of method 'addResultGet'.
 *
 * \tparam Output Type of data structure storing all deserialized in-/output arguments.
 *         Type must support member initializer lists. Typically a struct or a std::tuple is used.
 * \tparam RootDeserializer Used root deserializer.
 */
template <typename Output, typename RootDeserializer>
class addResultGetRequestDeserializer final {
 public:
  /*!
   * \brief Constructor
   * \param deserializer Rvalue reference to the used deserializer. The deserializer will be moved into this class.
   */
  explicit addResultGetRequestDeserializer(RootDeserializer&& deserializer)
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


    // No arguments to deserialize

    // Build output struct/tuple with deserialized values
    const Output deserialized_output{};
    return std::make_pair(deserialized_output, deserialization_ok);
  }

 private:
  /*!
   * \brief Used root deserializer.
   */
  RootDeserializer deserializer_;

};

/* ---- Field method 'addResultSet' ---- */

  /*!
 * \brief Deserializer for argument 'in_val' (AsrPath: /AUTOSAR/StdTypes/uint32_t)
 *
 * \tparam RootDeserializer Root deserializer type
 *
 * \trace SPEC-4980080, SPEC-4980115
 */
template <typename RootDeserializer>
class addResultSetRequestin_valDeserializer {
 public:
  /*!
   * \brief Constructor for addResultSetRequestin_valDeserializer
   * \param deserializer Used root deserializer
   */
  explicit addResultSetRequestin_valDeserializer(RootDeserializer* deserializer)
    : deserializer_{deserializer}, 
      logger_(amsr::com_common::internal::logging::kSomeIpLoggerContextId, amsr::com_common::internal::logging::kSomeIpLoggerContextDescription,
              "addResultSetRequestin_valDeserializer") {}

/*!
 * \brief Deserialize argument 'in_val'
 * \return Pair containing deserialized data and deserialization result
 */
std::pair<std::uint32_t, bool> Deserialize() {
  return Deserializein_val<RootDeserializer>(deserializer_);
}

private:
/*!
 * \brief CppImplDataTypeValue deserialization for element 'in_val' (/AUTOSAR/StdTypes/uint32_t)
 * \tparam ParentDeserializer Type of parent deserializer
 * \param parent Used parent deserializer
 */
template <typename ParentDeserializer>
std::pair<std::uint32_t, bool> Deserializein_val(ParentDeserializer* parent) {
  namespace common_marshalling = ::amsr::com_common::internal::serialization;
  namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

  // Deserialization result of element 'in_val'
  bool deserialization_ok{true};

std::uint32_t in_val{};
  ::amsr::com_common::internal::serialization::Deserializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, ParentDeserializer> deserializer__in_val{parent};
deserialization_ok &= deserializer__in_val.PopFront(in_val) > 0U;
  return std::make_pair(in_val, deserialization_ok);
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
 * \brief Deserializer for a SOME/IP packet of method 'addResultSet'.
 *
 * \tparam Output Type of data structure storing all deserialized in-/output arguments.
 *         Type must support member initializer lists. Typically a struct or a std::tuple is used.
 * \tparam RootDeserializer Used root deserializer.
 */
template <typename Output, typename RootDeserializer>
class addResultSetRequestDeserializer final {
 public:
  /*!
   * \brief Constructor
   * \param deserializer Rvalue reference to the used deserializer. The deserializer will be moved into this class.
   */
  explicit addResultSetRequestDeserializer(RootDeserializer&& deserializer)
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

    // Instantiate variable for storage of deserialized value of 'in_val'
    std::uint32_t arg_in_val{};


    if (deserialization_ok) {
      // Deserialize the argument 'in_val'
      addResultSetRequestin_valDeserializer<typename std::decay<RootDeserializer>::type>
        arg_in_val_deserializer{&deserializer_};
      const std::pair<std::uint32_t, bool> ret_in_val{arg_in_val_deserializer.Deserialize()};

      // Get deserialized value and update overall deserialization result
      arg_in_val = ret_in_val.first;
      deserialization_ok &= ret_in_val.second;
    }

    // Build output struct/tuple with deserialized values
    const Output deserialized_output{arg_in_val};
    return std::make_pair(deserialized_output, deserialization_ok);
  }

 private:
  /*!
   * \brief Used root deserializer.
   */
  RootDeserializer deserializer_;

};


}  // namespace fields
}  // namespace internal
}  // namespace someip_binding

}  // namespace tongjidemo

#endif  // SERVER_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_SKELETON_FIELDS_DESERIALIZER_H_

