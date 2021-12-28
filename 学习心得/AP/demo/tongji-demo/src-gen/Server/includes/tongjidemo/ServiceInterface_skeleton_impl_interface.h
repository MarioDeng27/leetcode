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
/**        \file  Server\includes\tongjidemo/ServiceInterface_skeleton_impl_interface.h
 *        \brief  Skeleton implementation interface of service 'ServiceInterface'.
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

#ifndef SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_IMPL_INTERFACE_H_
#define SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_IMPL_INTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>
#include "ara/com/instance_identifier.h"
#include "ara/core/future.h"
#include "socal/internal/skeleton_impl_interface.h"
#include "tongjidemo/serviceinterface_common.h"


namespace tongjidemo {
namespace internal {

/*!
 * \brief Skeleton implementation interface for the Service 'ServiceInterface'
 * \remark generated
 */
class ServiceInterfaceSkeletonImplInterface : public ::amsr::socal::internal::SkeletonImplInterface {
 public:
  /*!
   * \brief Define destructor
   */
  virtual ~ServiceInterfaceSkeletonImplInterface() = default;

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Pure virtual interface for sending samples of service event 'addInfo'.
   * \details This method shall be defined in a concrete binding-specific skeleton implementation.
   * \param data Event sample of type std::uint32_t
   */
  virtual void SendEventaddInfo(const std::uint32_t& data) = 0;

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /*!
   * \brief Pure virtual interface for updating service field 'addResult'.
   * \details This method shall be defined in a concrete binding-specific skeleton implementation.
   * \param data Field data oof type std::uint32_t
   */
  virtual void UpdateFieldaddResult(std::uint32_t const& data) = 0;
};

} // namespace internal
}  // namespace tongjidemo

#endif  // SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_IMPL_INTERFACE_H_
