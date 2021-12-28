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
/**        \file  Server\includes\tongjidemo/serviceinterface_skeleton.h
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

#ifndef SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_H_
#define SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_H_

/*!
 * \trace SPEC-4980239
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <atomic>
#include <memory>
#include <vector>
#include "ara/core/future.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/optional.h"
#include "com-common/internal/logging/ara_com_logging.h"
#include "socal/internal/fields/skeleton_field.h"
#include "socal/internal/skeleton.h"
#include "socal/internal/skeleton_event.h"
#include "socal/internal/skeleton_interface.h"
#include "socal/internal/skeleton_request_handling.h"
#include "tongjidemo/ServiceInterface_skeleton_impl_interface.h"
#include "tongjidemo/ServiceInterface_types.h"
#include "tongjidemo/serviceinterface_common.h"

/*!
 * \trace SPEC-4980240
 */
namespace tongjidemo
{
  /*!
 * \trace SPEC-4980241
 */
  namespace skeleton
  {
    /*!
 * \brief Forward declaration for inserting as a type into the template class SkeletonEvent
 */
    class ServiceInterfaceSkeleton;

    /*!
 * \trace SPEC-4980244
 */
    namespace methods
    {

      /*!
 * \brief Data class for service method 'add'.
 */
      using add = tongjidemo::internal::methods::add;

    } // namespace methods

    /*!
 * \trace SPEC-4980243
 */
    namespace events
    {

      /*!
 * \brief Type alias for service event 'addInfo', that is part of the skeleton.
 *
 * \trace SPEC-4980342 (Service skeleton event class)
 */
      using addInfo =
          ::amsr::socal::internal::SkeletonEvent<tongjidemo::skeleton::ServiceInterfaceSkeleton, std::uint32_t,
                                                 tongjidemo::internal::ServiceInterfaceSkeletonImplInterface,
                                                 &tongjidemo::internal::ServiceInterfaceSkeletonImplInterface::SendEventaddInfo>;

    } // namespace events

    /*!
 * \trace SPEC-4980245
 */
    namespace fields
    {
      /*!
 * \brief Type alias for the notification of field 'addResult'.
 */
      using FieldNotifieraddResult = ::amsr::socal::internal::SkeletonEvent<
          tongjidemo::skeleton::ServiceInterfaceSkeleton,
          std::uint32_t,
          tongjidemo::internal::ServiceInterfaceSkeletonImplInterface,
          &tongjidemo::internal::ServiceInterfaceSkeletonImplInterface::UpdateFieldaddResult>;

      /*!
 * \brief Type alias for the notifier configuration of field 'addResult'.
 */
      using FieldNotifierConfigaddResult = ::amsr::socal::internal::fields::SkeletonFieldParams::HasNotifier<true, FieldNotifieraddResult>;

      /*!
 * \brief Type alias for the getter configuration of field 'addResult'.
 */
      using FieldGetterConfigaddResult = ::amsr::socal::internal::fields::SkeletonFieldParams::HasGetter<true>;

      /*!
 * \brief Type alias for the setter configuration of field 'addResult'.
 */
      using FieldSetterConfigaddResult = ::amsr::socal::internal::fields::SkeletonFieldParams::HasSetter<true>;

      /*!
 * \brief Field name.
 */
      struct addResultName
      {
        /*!
   * \brief Field name string.
   */
        static constexpr vac::container::CStringView Name = "addResult"_sv;
      };

      /*!
 * \brief Type alias for the parameterization of field 'addResult'.
 */
      using FieldConfigaddResult = ::amsr::socal::internal::fields::SkeletonFieldConfig<tongjidemo::skeleton::ServiceInterfaceSkeleton, FieldNotifierConfigaddResult, FieldGetterConfigaddResult, FieldSetterConfigaddResult, addResultName>;

      /*!
 * \brief Type alias for service field 'addResult', that is part of the skeleton.
 *
 * \trace SPEC-4980343 (Service skeleton Field class)
 */
      using addResult = ::amsr::socal::internal::fields::SkeletonField<std::uint32_t, FieldConfigaddResult>;

    } // namespace fields

    /*!
 * \brief Skeleton interface class for the service 'ServiceInterface'.
 * \vpublic
 * \trace SPEC-4980341 (Service skeleton class)
 */
    class ServiceInterfaceSkeleton
        : public ::amsr::socal::internal::Skeleton<tongjidemo::ServiceInterface,
                                                   tongjidemo::internal::ServiceInterfaceSkeletonImplInterface>
    {
    public:
      /*!
   * \brief Delete default constructor.
   */
      ServiceInterfaceSkeleton() = delete;
      /*!
   * \brief Delete copy constructor.
   */
      ServiceInterfaceSkeleton(ServiceInterfaceSkeleton const &) = delete;
      /*!
   * \brief Delete move constructor.
   */
      ServiceInterfaceSkeleton(ServiceInterfaceSkeleton &&) = delete;
      /*!
   * \brief Delete copy assignment.
   */
      ServiceInterfaceSkeleton &operator=(ServiceInterfaceSkeleton const &) & = delete;
      /*!
   * \brief Delete move assignment.
   */
      ServiceInterfaceSkeleton &operator=(ServiceInterfaceSkeleton &&) & = delete;

      /*!
   * \brief Constructor of ServiceInterfaceSkeleton.
   *
   * \remark Because of internal resource management strategy, all created skeletons shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   * \vpublic
   *
   * \trace SPEC-4980351 (Creation of service skeleton)
   * \trace SPEC-4980356 (Set service method processing mode)
   *
   * \param instance The identifier of a specific instance of a service, needed to distinguish different instances of
   *        exactly the same service in the system.
   * \param mode The mode of the service implpementation for processing service method invocations.
   *        Default: Event-driven processing
   * \throws std::runtime_error if same instance identifier is used for the creation of more than one skeleton instance (The identifier shall be unique).
   */
      explicit ServiceInterfaceSkeleton(
          ara::com::InstanceIdentifier instance,
          ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);

      /*!
   * \brief Constructor of ServiceInterfaceSkeleton.
   *
   * \remark Because of internal resource management strategy, all created skeletons shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   *
   * \trace SPEC-8053552 (Creation of service skeleton using Instance Spec)
   * \trace SPEC-4980356 (Set service method processing mode)
   *
   * \param instance The InstanceSpecifier of a specific service instance, needed to distinguish different instances of
   *        exactly the same service in the system.
   * \param mode The mode of the service implementation for processing service method invocations.
   *        Default: Event-driven processing
   * \throws std::runtime_error if same underlying instance identifier is used for the creation of more than one skeleton instance (The identifier shall be unique).
   */
      explicit ServiceInterfaceSkeleton(
          ara::core::InstanceSpecifier instance,
          ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);

      /*!
   * \brief Constructor of ServiceInterfaceSkeleton.
   *
   * \remark Because of internal resource management strategy, all created skeletons shall be released before the Runtime
   * is destroyed; i.e. they cannot not be stored in variables with longer life period than the application's main().
   * If not followed, it's not guaranteed that the communication middleware is shut down properly and may lead to
   * segmentation fault.
   *
   * \trace SPEC-8053554 (Creation of service skeleton using Instance ID Container)
   * \trace SPEC-4980356 (Set service method processing mode)
   *
   * \param instance_identifiers The container of instances of a service, each instance element needed to distinguish different instances of exactly the same service in the system.
   * \param mode The mode of the service implementation for processing service method invocations.
   *        Default: Event-driven processing
   * \throws std::runtime_error if same instance identifier is used for the creation of more than one skeleton instance (The identifier shall be unique).
   */
      explicit ServiceInterfaceSkeleton(
          ara::com::InstanceIdentifierContainer instance_identifiers,
          ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent);

      /*!
   * \brief Destructor
   * \details This call will be blocked until all current method requests are finished/canceled.
   * \vpublic
   * \trace SPEC-4980351
   */
      virtual ~ServiceInterfaceSkeleton();

      /* ---- Methods -------------------------------------------------------------------------------------------------- */

      /*!
   * \brief Provided implementation for service interface method 'add'.
   * \vpublic
   *
   * \param num1 IN parameter of type std::uint32_t
   * \param num2 IN parameter of type std::uint32_t
   * \return ara::core::Future which gets resolved with the method output arguments or an ApApplicationError error code
   *         after processing has finished.
   *         Output arguments:
   *         - result OUT parameter of type std::uint32_t
   *
   * \trace SPEC-4980355
   */
      virtual ara::core::Future<methods::add::Output> add(const std::uint32_t &num1, const std::uint32_t &num2) = 0;

      /* ---- Events --------------------------------------------------------------------------------------------------- */

      /*!
   * \brief The skeleton event 'addInfo' which can be used by application developer.
   * \details 
   * Data of type std::uint32_t
   * \vpublic
   */
      events::addInfo addInfo;

      /* ---- Fields --------------------------------------------------------------------------------------------------- */

      /*!
   * \brief The skeleton field 'addResult' which can be used by application developer.
   * \details 
   * Data of type std::uint32_t
   * \vpublic
   */
      fields::addResult addResult;

    private:
      /*!
   * \brief Type alias for the base class.
   */
      using Base = ::amsr::socal::internal::Skeleton<tongjidemo::ServiceInterface, tongjidemo::internal::ServiceInterfaceSkeletonImplInterface>;

      /*!
   * \brief Checks if all fields are correctly initialized and throws the corresponding exception in case of failure.
   *
   * \trace SPEC-4980364 (Ensuring the existence of valid Field values)
   * \trace SPEC-4980365 (Ensuring existence of SetHandler)
   *
   * \throws ara::com::SetHandlerNotAvailableException if any of the fields of the skeleton has Setter but no SetHandler
   *         is registered.
   * \throws ara::com::BackendNotAvailableException If SOME/IP is configured as the communication binding and the
   *         application is not connected to the Daemon.
   * \throws ara::com::FieldNotInitializedException if any of the fields of the skeleton is not initialized and either
   *         1) it has a notifier or 2) it has a getter and no GetHandler is registered.
   */
      void DoFieldInitializationChecks() override;

      /*!
   * \brief Sends all initial events for the fields that have notifiers.
   */
      void SendInitialFieldNotifications() override;

      /*!
   * \brief Skeleton resource configuration parametrized via ARXML.
   */
      static constexpr ::amsr::socal::internal::configuration::SkeletonConfiguration kConfiguration{::amsr::socal::internal::configuration::SkeletonConfiguration::MethodRequestBufferLimit{0U}, ::amsr::socal::internal::configuration::MemoryMode::kFlexible};
    }; // class ServiceInterfaceSkeleton

  } // namespace skeleton
} // namespace tongjidemo

#endif // SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_SKELETON_H_
