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
/**        \file  Client\includes\tongjidemo/ServiceInterface.h
 *        \brief  Header for service 'ServiceInterface'.
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

#ifndef CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_H_
#define CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "ara/com/service_identifier.h"
#include "tongjidemo/serviceinterface_resource_manager.h"
#include "vac/container/c_string_view.h"
#include "vac/container/string_literals.h"

namespace tongjidemo {

/*!
 * \brief Literals namespace is needed for "_sv literal.
 */
using namespace vac::container::literals;  // NOLINT(build/namespaces)

/*!
 * \brief Representation of service 'ServiceInterface'
 * \details Used for service-specific aspects:
 *  - Resource management
 *  - Service Identifier
 *
 * \trace SPEC-4980256
 */
class ServiceInterface final {
 public:
  /*!
   * \brief Type-alias for easy access to CStringView.
   */
  using CStringView = vac::container::CStringView;

  /*!
   * \brief Type-alias for used resource manager for service 'ServiceInterface'.
   */
  using ResourceManager = resources::ServiceInterfaceResourceManager;

  /*!
   * \brief Service Identifier.
   *
   * \trace SPEC-4980252, SPEC-4980256
   */
  static constexpr ara::com::ServiceIdentifierType ServiceIdentifier{CStringView{"ServiceInterface"_sv}};

  /*!
   * \brief Service shortname path.
   */
  static constexpr CStringView kServiceShortNamePath{"/ServiceInterfaces/ServiceInterface"_sv};
};

}  // namespace tongjidemo

#endif  // CLIENT_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_H_
