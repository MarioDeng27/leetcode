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
/**       \file  server/main.cc
 *        \brief  Main entry point of the calculator server example application
 *
 *        \details  -
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <signal.h>
#include <unistd.h>

#ifdef ENABLE_EXEC_MANAGER
#include <ara/exec/application_client.h>
#endif

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

#include "ara/com/runtime.h"
#include "ara/com/types.h"
#include "ara/core/instance_specifier.h"
#include "ara/log/logging.h"
#include "commandlineparser/command_line_parser.h"
#include "config/logging_cfg.h"
#include "vac/container/string_literals.h"
#include "vac/memory/optional.h"
#include "vac/memory/three_phase_allocator.h"

#include "tongjidemo_server.h"

#ifdef ENABLE_EXEC_MANAGER
using ApplicationClient = ara::exec::ApplicationClient;
using ApplicationState = ara::exec::ApplicationState;
#endif

/* Forward declarations */
void Initialize_Signalhandler(void);
void SignalHandler(void);

/**
 * \brief Flag to identify whether the application was requested to terminate, i.e., has received a SIGTERM
 */
std::atomic_bool exit_requested(false);

/**
 * \brief Vector to store all threads spawned by this application.
 */
std::vector<std::thread> threads;

int main(int argc, char *argv[])
{
  using vac::container::literals::operator""_sv;

  // Initialize signal handler to ensure all signals are blocked for all child processes
  Initialize_Signalhandler();

  ara::log::InitLogging("sdse", "Adaptive tongjidemo Server", ara::log::LogLevel::kInfo,
                        ara::log::LogMode::kConsole | ara::log::LogMode::kRemote, "tmp");

  // Create logger in the allocation phase
  ara::log::Logger &logger_ctx{ara::log::CreateLogger(calc::config::kContextIdCalcServerMethodInvocator,
                                                      "Context for tongjidemo Server method implementation")};

  logger_ctx.LogInfo() << "Starting tongjidemo Server";

#ifdef ENABLE_EXEC_MANAGER
  vac::memory::optional<ApplicationClient> app_client;

  if (args.enable_em_)
  {
    // Instantiate the ApplicationClient
    app_client.emplace();
  }
#endif

  logger_ctx.LogInfo() << "Initializing...";
  // Loading config file and initialize runtime
  logger_ctx.LogInfo() << "Initializing runtime...";
  //ara::com::Runtime::getInstance().Initialize(args.cfg_path_);
  ara::com::Runtime::getInstance().Initialize();
  // Set allocation phase to 'steady' after all memory resources are initialized and allocated
  logger_ctx.LogDebug() << __FUNCTION__ << "Setting AllocationPhaseManager::AllocationPhase to 'steady'.";
  vac::memory::AllocationPhaseManager::GetInstance().SetPhase(
      vac::memory::AllocationPhaseManager::AllocationPhase::steady);

  logger_ctx.LogInfo() << "Instantiating...";
  // Create service with corresponding InstanceSpecifier
  ara::core::InstanceSpecifier const someip_server_port{
      "Server/RootSwComponentPrototype/PPort_ServiceInterface"_sv};
  someip::tongjiDemoServer myService(someip_server_port);

  myService.addResult.Update(0);

  myService.OfferService();

#ifdef ENABLE_EXEC_MANAGER
  if (args.enable_em_ && app_client.has_value())
  {
    // Report application state to execution management
    logger_ctx.LogInfo() << "Reporting application state kRunning.";
    app_client->ReportApplicationState(ApplicationState::kRunning);
  }
#endif

  logger_ctx.LogInfo() << "Finished initialization sequence.";
  // Loop until the Execution Manager requests the application to exit
  while (!exit_requested)
  {
    std::this_thread::sleep_for(std::chrono::seconds(100));
  }

#ifdef ENABLE_EXEC_MANAGER
  if (args.enable_em_ && app_client.has_value())
  {
    // Report application state to execution management
    logger_ctx.LogInfo() << "Reporting application state kTerminating.";
    app_client->ReportApplicationState(ApplicationState::kTerminating);
  }
#endif

  // Set allocation phase to 'deallocation' before destroying and deallocating all memory resources
  logger_ctx.LogDebug() << __FUNCTION__ << " Setting AllocationPhaseManager::AllocationPhase to 'deallocation'";
  vac::memory::AllocationPhaseManager::GetInstance().SetPhase(
      vac::memory::AllocationPhaseManager::AllocationPhase::deallocation);

  myService.StopOfferService();

  return 0;
}

/**
 * \brief  Function to initialize the calculator server
 */
void Initialize_Signalhandler(void)
{
  /* Block all signals for this thread. Signal mask will be inherited by subsequent threads. */
  sigset_t signals;
  sigfillset(&signals);
  pthread_sigmask(SIG_SETMASK, &signals, NULL);
  /* spawn a new signal handler thread*/
  threads.emplace_back(SignalHandler);
}

/**
 * \brief Signal handler function for SIGTERM
 */
void SignalHandler(void)
{
  sigset_t signal_set;
  int sig = -1;
  sigemptyset(&signal_set);        /* Empty the set of signals */
  sigaddset(&signal_set, SIGTERM); /* Add only SIGTERM to set */
  sigaddset(&signal_set, SIGINT); /* Add SIGINT to set */
  while (sig != SIGTERM && sig !=SIGINT)
  {
    sigwait(&signal_set, &sig);
    ara::log::Logger &logger_ctx = ara::log::CreateLogger(calc::config::kContextIdCalcServerMethodInvocator,
                                                          "Context for SOMEIPDemoServer method implementation");
    logger_ctx.LogInfo() << "Received signal number:" << sig;
  }
  ara::log::Logger &logger_ctx = ara::log::CreateLogger(calc::config::kContextIdCalcServerMethodInvocator,
                                                        "Context for SOMEIPDemoServer method implementation");
  logger_ctx.LogInfo() << "Received signal SIGTERM";
  exit_requested = true;
}
