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
/**        \file  Server\src/tongjidemo/serviceinterface_skeleton.cpp
 *        \brief  Skeleton for service 'ServiceInterface'.
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "tongjidemo/serviceinterface_skeleton.h"
#include "ara/com/internal_com_exception.h"
#include "ara/com/runtime.h"
#include "socal/internal/instance_specifier_lookup_table.h"

/*!
 * \trace SPEC-4980240
 * \trace SPEC-4980241
 */
namespace tongjidemo {
namespace skeleton {
constexpr ::amsr::socal::internal::configuration::SkeletonConfiguration ServiceInterfaceSkeleton::kConfiguration;

ServiceInterfaceSkeleton::ServiceInterfaceSkeleton(ara::com::InstanceIdentifier instance,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance, mode, kConfiguration}
      , addInfo(this)
      , addResult(this)
       {}

ServiceInterfaceSkeleton::ServiceInterfaceSkeleton(ara::core::InstanceSpecifier instance,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance, mode, kConfiguration}
      , addInfo(this)
      , addResult(this)
       {}

ServiceInterfaceSkeleton::ServiceInterfaceSkeleton(ara::com::InstanceIdentifierContainer instance_identifiers,
                                               ara::com::MethodCallProcessingMode mode)
     : Base{instance_identifiers, mode, kConfiguration}
      , addInfo(this)
      , addResult(this)
       {}

ServiceInterfaceSkeleton::~ServiceInterfaceSkeleton() {
  // Stop all scheduled tasks related to this skeleton.
  GetThreadPool().RemoveTasks(this);
}

void ServiceInterfaceSkeleton::DoFieldInitializationChecks() {
  /* Check if all fields are initialized correctly
    * - if a field has Setter, SetHandler must be registered.
    * - if a field has Notification, Update must have been called.
    * - if a field has Getter and no GetHandler is registered, Update() must have been called.
    */

    if (!addResult.IsSetHandlerRegistered()) {
      logger_.LogError([this](ara::log::LogStream& s) {
                        s << "Failed to offer service 'ServiceInterface' with instance id(s) '";
                        for (::amsr::socal::internal::InstanceSpecifierLookupTableEntry const& entry : offered_instances_) {
                          s << " " << entry.GetInstanceIdentifier().ToString();
                        }
                        s << "' - No SetHandler has been registered for field 'addResult'."; },
                        __func__, __LINE__);
      throw ara::com::InternalComException(ara::com::InternalComErrc::set_handler_not_available);
    }
    if (!addResult.IsUpdated()) {
        logger_.LogError([this](ara::log::LogStream& s) {
                          s << "Failed to offer service 'ServiceInterface' with instance id(s) '";
                          for (::amsr::socal::internal::InstanceSpecifierLookupTableEntry const& entry : offered_instances_) {
                            s << " " << entry.GetInstanceIdentifier().ToString();
                          }
                          s << "' - No initial value has been set for field 'addResult' (addResult::Update(...) has never been called)."; },
                          __func__, __LINE__);
        throw ara::com::InternalComException(ara::com::InternalComErrc::field_not_initialized);
    }
}

void ServiceInterfaceSkeleton::SendInitialFieldNotifications() {
  // Send initial field events for all fields with "hasNotifier = true"
  addResult.SendInitialValue();
}

}  // namespace skeleton
}  // namespace tongjidemo

