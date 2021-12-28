/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  client/tongjidemo_client.h
 *        \brief  Main entry point of the tongjidemo_client, used for testing the service.
 *
 *      \details  -
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#ifndef SRC_CLIENT_TONGJI_DEMO_CLIENT_H_
#define SRC_CLIENT_TONGJI_DEMO_CLIENT_H_

#include <atomic>
#include <chrono>
#include <memory>
#include <string>
#include <thread>

#include "ara/com/runtime.h"
#include "ara/com/types.h"
#include "ara/core/future.h"
#include "ara/log/logging.h"
#include "tongjidemo/ServiceInterface.h"
#include "tongjidemo/serviceinterface_proxy.h"
namespace someip
{

  /*!
 * \brief tongjidemo_client.
 */
  class tongjiDemoClient
  {
  public:
    /*!
   * \brief Delete default constructor.
   */
    tongjiDemoClient() = delete;
    /*!
   * \brief Delete destructor.
   */
    virtual ~tongjiDemoClient() = delete;

    /*!
   * \brief Function is searching for one calculator service provider
   */
    static void FindService();

    /*!
   * \brief Function is calling the method add with the given parameters
   * \param num1 Is the addend1
   * \param num2 Is the addend2
   */
    static ara::core::Future<tongjidemo::proxy::methods::add::Output> CallAdd(std::uint32_t num1,
                                                                              std::uint32_t num2);

    /*!
   * \brief  Function gets called when a calculatorService instance is found
   * \param  calculator_services Contains all found calculatorService instances
   */
    static void FindServiceHandler(
        ara::com::ServiceHandleContainer<tongjidemo::proxy::ServiceInterfaceProxy::HandleType>
            SOMEIPDemo_services);

    /*!
   * \brief Function is subscribing the division results and the devision by zero.
   */
    static void SubscribeToEvents();

    /*!
   * \brief Function is unsubscribing the division results and the devision by zero.
   */
    static void UnsubscribeToEvents();

    /*!
   * \brief  Function gets called when a divisionByZero event occurs
   */
    static void addInfoHandler(void);

    static void addResultHandler(void);

    /*!
   * \brief Function initializes the ara::com::Runtime
   */
    static void Initialize(std::string cfg_path_);

    /*!
   * \brief Flag to indicate if an service provider was found
   */
    static std::atomic<bool> server_found;

    /*!
   * \brief Shared pointer holding the calculator_service_proxy
   */
    static std::shared_ptr<tongjidemo::proxy::ServiceInterfaceProxy> tongjidemo_service_proxy;

    /*!
   * \brief Flag to indicate whether a divider event was received
   */
    static std::atomic<bool> add_event_received;

  private:
    /**
   * \brief Holds the logging context
   */
    static ara::log::Logger &GetLogger();
  };

} // namespace someip

#endif // SRC_CLIENT_TONGJI_DEMO_CLIENT_H_
