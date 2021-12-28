/*
 * @Author: your name
 * @Date: 2021-12-27 21:59:35
 * @LastEditTime: 2021-12-27 22:19:03
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \tongji-demo\src\server\tongjidemo_server.h
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

#ifndef SRC_SERVER_TONGJI_DEMO_SERVER_H_
#define SRC_SERVER_TONGJI_DEMO_SERVER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <ara/log/logging.h>
#include <chrono>
#include <thread>

#include "ara/core/instance_specifier.h"
#include "tongjidemo/ServiceInterface.h"
#include "tongjidemo/ServiceInterface_someip_skeleton_factory.h"


namespace someip {

/*!
 * \brief  Server 
 */
class tongjiDemoServer : public tongjidemo::skeleton::ServiceInterfaceSkeleton {
 public:
  /*!
   * \brief  Constructor of the class tongjiDemoServer that provides the Service
   * \param  someip_server_port identifies PortPrototype
   */
  explicit tongjiDemoServer(ara::core::InstanceSpecifier someip_server_port);
  ~tongjiDemoServer() {}

 private:
  /*!
   * \brief  Method add the two given arguments. Notice: A division by zero will cause an divisionByZero event
   * \param num1 IN parameter of type std::uint32_t
   * \param num2 IN parameter of type std::uint32_t
   * \return  Returns a future for async function call handling
   */
  ara::core::Future<tongjidemo::skeleton::methods::add::Output> add(
      std::uint32_t const& num1, std::uint32_t const& num2) override;

  /* ---- Field values ---- */
  tongjidemo::skeleton::fields::addResult::FieldType addResult_value;

  /*!
   * \brief  Holds the logging context
   */
  ara::log::Logger& logger_ctx_;
};

}  // namespace someip


#endif  // SRC_SERVER_TONGJI_DEMO_SERVER_H_
