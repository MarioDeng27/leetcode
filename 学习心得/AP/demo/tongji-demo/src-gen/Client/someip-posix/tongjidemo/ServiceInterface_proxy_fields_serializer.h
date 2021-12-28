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
/**        \file  Client\someip-posix/tongjidemo/ServiceInterface_proxy_fields_serializer.h
 *        \brief  SOME/IP packet serializer for field methods of service 'ServiceInterface'.
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

#ifndef CLIENT_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_PROXY_FIELDS_SERIALIZER_H_
#define CLIENT_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_PROXY_FIELDS_SERIALIZER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <utility>
#include "someip-protocol/internal/marshalling.h"
#include "someip-protocol/internal/serializer_base.h"
#include "tongjidemo/serviceinterface_common.h"

namespace tongjidemo {

namespace someip_binding {
namespace internal {
namespace fields {

/* ---- Field method 'addResultGet' ---- */

/*!
 * \brief Serializer for a SomeIp packet of method 'addResultGet'.
 *
 * \trace SPEC-4980140
 */
class addResultGetRequestSerializer final : public amsr::someip_protocol::internal::serialization::SomeIpSerializerBase {
 public:
   /*!
   * \brief Type alias for the concrete serializer configuration: Use configuration for SOME/IP protocol used by SOME/IP binding.
   */
  using Base = amsr::someip_protocol::internal::serialization::SomeIpSerializerBase;

  /*!
   * \brief Constructor
   *
   * \tparam Header Type of protocol SomeIp protocol header struct.
   *
   * \param logger Reference to the logger used for logging during serialization.
   * \param packet Memory buffer in which the packet gets serialized. The memory buffer will be moved into the class instance.
   * \param header Reference to a packet header struct.
   */
  template <typename Header>
  explicit addResultGetRequestSerializer(amsr::com_common::internal::logging::AraComLogger& logger, Base::BufferPtrType packet, const Header& header)
      : Base{logger, std::move(packet), header} {}

  /*!
   * \brief Serialize all input arguments into a SomeIp packet including the SomeIp header.
   * \post Serialization is only possible a single time. This serializer object must not be used anymore after call of this API.
   *
   * \tparam InputStruct Type of data structure storing all in-/output arguments to be serialized.
   *
   * \return Pair containing the serialized SomeIp packet and the serializer result indicating if the serialization was successful or not.
   */
  template <typename InputStruct>
  std::pair<Base::BufferPtrType, ::amsr::com_common::internal::serialization::SerializerStatus> Serialize(const InputStruct&) {
    // No argument(s) to serialize

    return CloseRootSerializer();
  }
};


/* ---- Field method 'addResultSet' ---- */

/*!
 * \brief Serializer for a SomeIp packet of method 'addResultSet'.
 *
 * \trace SPEC-4980140
 */
class addResultSetRequestSerializer final : public amsr::someip_protocol::internal::serialization::SomeIpSerializerBase {
 public:
   /*!
   * \brief Type alias for the concrete serializer configuration: Use configuration for SOME/IP protocol used by SOME/IP binding.
   */
  using Base = amsr::someip_protocol::internal::serialization::SomeIpSerializerBase;

  /*!
   * \brief Constructor
   *
   * \tparam Header Type of protocol SomeIp protocol header struct.
   *
   * \param logger Reference to the logger used for logging during serialization.
   * \param packet Memory buffer in which the packet gets serialized. The memory buffer will be moved into the class instance.
   * \param header Reference to a packet header struct.
   */
  template <typename Header>
  explicit addResultSetRequestSerializer(amsr::com_common::internal::logging::AraComLogger& logger, Base::BufferPtrType packet, const Header& header)
      : Base{logger, std::move(packet), header} {}

  /*!
   * \brief Serialize all input arguments into a SomeIp packet including the SomeIp header.
   * \post Serialization is only possible a single time. This serializer object must not be used anymore after call of this API.
   *
   * \internal
   * - Get a reference to the root serializer.
   * - Serialize all the input arguments from InputStruct using specific sub-serializers.
   * - Close the sub-serializer and root serializer.
   * - Return a pair with serialized payload and a status indicating the success/failure of serialization.
   * \endinternal
   *
   * \param input Reference to the input struct containing all arguments to be serialized into the SOME/IP packet.
   *
   * \tparam InputStruct Type of data structure storing all in-/output arguments to be serialized.
   *
   * \return Pair containing the serialized SomeIp packet and the serializer result indicating if the serialization was successful or not.
   */
  template <typename InputStruct>
  std::pair<Base::BufferPtrType, ::amsr::com_common::internal::serialization::SerializerStatus> Serialize(const InputStruct& input) {
    namespace someip_marshalling = ::amsr::someip_protocol::internal::serialization;

    // Status of instantiated sub-serializers
    ::amsr::com_common::internal::serialization::SerializerStatus serialization_status{::amsr::com_common::internal::serialization::SerializerStatus::kOk};

    // Get root serializer from base class
    Base::RootSerializerType& serializer{GetRootSerializer()};

    // Instantiate sub-serializer and serialize the payload
    // Serialize argument 'in_val'
    // CppImplDataTypeValue serialization for element 'in_val' (/AUTOSAR/StdTypes/uint32_t)
{
  ::amsr::com_common::internal::serialization::Serializer<someip_marshalling::BEPayloadNoLengthFieldPolicy, Base::RootSerializerType> serializer_in_val{&serializer};
  serializer_in_val.PushBack(input.in_val);
  serializer_in_val.Close();
}


    return CloseRootSerializer(serialization_status);
  }
};



}  // namespace fields
}  // namespace internal
}  // namespace someip_binding

}  // namespace tongjidemo

#endif  // CLIENT_SOMEIP_POSIX_TONGJIDEMO_SERVICEINTERFACE_PROXY_FIELDS_SERIALIZER_H_

