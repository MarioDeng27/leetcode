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
/**        \file  logging_cfg.h
 *        \brief  TODO
 *
 *      \details  TODO
 *
 *********************************************************************************************************************/

#ifndef SRC_CLIENT_CONFIG_LOGGING_CFG_H_
#define SRC_CLIENT_CONFIG_LOGGING_CFG_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
namespace calc {
namespace config {

/// Definition of logging file path as char[] to allow usage of sizeof()
static constexpr const char kLoggingConfigFile[] = "./etc/logging_config.json";

/// Context IDs
static constexpr const char kContextIdCalcClientMethodInvocator[] = "CXC1";

/*!
 * \brief Logger application id for SOME/IP Daemon POSIX
 */
static constexpr const char* kSomeIpDLoggerApplicationId{"VSom"};

/*!
 * \brief Logger application description for SOME/IP Daemon POSIX
 */
static constexpr const char* kSomeIpDLoggerApplicationDescription{"SOME/IP Communication Daemon for Posix"};

}  // namespace config
}  // namespace calc

#endif  // SRC_CLIENT_CONFIG_LOGGING_CFG_H_
