/*
 * @Author: your name
 * @Date: 2021-12-27 21:59:35
 * @LastEditTime: 2021-12-28 17:39:10
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \tongji-demo\src\server\tongjidemo_server.cc
 */
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  calculator_server.cc
 *        \brief  Class contains the calculator server service implementation
 *
 *      \details  -
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "tongjidemo_server.h"
#include <functional>
#include <iostream>
#include <utility>
#include "ara/core/instance_specifier.h"

namespace someip
{
  tongjiDemoServer::tongjiDemoServer(ara::core::InstanceSpecifier someip_server_port)
      : tongjidemo::skeleton::ServiceInterfaceSkeleton(someip_server_port),
        logger_ctx_{ara::log::CreateLogger("CSRV", "Context for tongjidemo_server method implementation")}
  {
    logger_ctx_.LogInfo() << "Offer tongjidemo server service";

    addResult.RegisterSetHandler([this](std::uint32_t const &value)
                                 {
                                   ara::core::Promise<std::uint32_t> promise;
                                   addResult_value = value;
                                   promise.set_value(addResult_value);
                                   return promise.get_future();
                                 });

    addResult.RegisterGetHandler([this]()
                                 {
                                   ara::core::Promise<std::uint32_t> promise;
                                   promise.set_value(addResult_value);
                                   return promise.get_future();
                                 });

    // Initialize field value before offering service
    addResult.Send(0);
    logger_ctx_.LogInfo() << "ok";
  }

  ara::core::Future<tongjidemo::skeleton::methods::add::Output> tongjiDemoServer::add(
      std::uint32_t const &num1, std::uint32_t const &num2)
  {
    logger_ctx_.LogInfo() << "add method get's called with num1: " << num1 << " and num2: " << num2;
    tongjidemo::skeleton::methods::add::Output ret;
    ret.result = num1 + num2;
    addResult.Send(ret.result);
   
    ara::core::Promise<tongjidemo::skeleton::methods::add::Output> promise;
    promise.set_value(std::move(ret));
    return promise.get_future();
  }
} // namespace calculator
