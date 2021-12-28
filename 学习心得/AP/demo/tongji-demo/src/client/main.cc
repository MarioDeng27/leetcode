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
/**        \file  client/main.cc
 *        \brief  Main entry point of the calculatorClient, used for testing the calulator service.
 *
 *      \details  -
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <signal.h>
#include <stdint.h>
#include <unistd.h>
#include <atomic>
#include <chrono>
#include <csignal>
#include <thread>

#include "ara/core/future.h"
#include "ara/log/logging.h"

#ifdef ENABLE_EXEC_MANAGER
#include "ara/exec/application_client.h"
#endif

#include "commandlineparser/command_line_parser.h"
#include "config/logging_cfg.h"

#include "vac/memory/optional.h"
#include "vac/memory/three_phase_allocator.h"

#include "someip/tongjidemo_client.h"

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
  // Initialize signal handler to ensure all signals are blocked for all child processes
  Initialize_Signalhandler();

  // Initialize logging framework
  ara::log::InitLogging("tjcl", "Adaptive tongji Client", ara::log::LogLevel::kInfo,
                        ara::log::LogMode::kConsole | ara::log::LogMode::kRemote, "tmp");

  // Create logger in the allocation phase
  ara::log::Logger &logger_ctx{ara::log::CreateLogger(calc::config::kContextIdCalcClientMethodInvocator,
                                                      "Context for someipdemo method invocation")};
  logger_ctx.LogInfo() << "Starting tongjiDemoClient";

  //CommandLineArguments args = ParseArguments(argc, argv);

#ifdef ENABLE_EXEC_MANAGER
  vac::memory::optional<ApplicationClient> app_client;
  if (args.enable_em_)
  {
    // Instantiate the ApplicationClient
    app_client.emplace();
  }
#endif

  // Loading config file and initialize runtime
  logger_ctx.LogInfo() << "Initializing runtime...";
  //someip::tongjiDemoClient::Initialize(args.cfg_path_);
  ara::com::Runtime::getInstance().Initialize();

  // Set allocation phase to 'steady' after all memory resources are initialized and allocated
  logger_ctx.LogDebug() << __FUNCTION__ << " Setting AllocationPhaseManager::AllocationPhase to 'steady'.";
  vac::memory::AllocationPhaseManager::GetInstance().SetPhase(
      vac::memory::AllocationPhaseManager::AllocationPhase::steady);

  someip::tongjiDemoClient::FindService();
  someip::tongjiDemoClient::SubscribeToEvents();

#ifdef ENABLE_EXEC_MANAGER
  if (args.enable_em_ && app_client.has_value())
  {
    // Report application state to execution management
    logger_ctx.LogInfo() << "Reporting application state kRunning.";
    app_client->ReportApplicationState(ApplicationState::kRunning);
  }
#endif
  // Calling methods of the divide method
  uint32_t operand1 = 36;
  uint32_t operand2 = 12;

  auto add_future1 = someip::tongjiDemoClient::CallAdd(operand1, operand2);
  operand2 = 0;
  auto add_future2 = someip::tongjiDemoClient::CallAdd(operand1, operand2);

  // Print out results
  uint32_t result_add1 = add_future1.get().result;
  logger_ctx.LogInfo() << "Result add1: " << result_add1;
  uint32_t result_add2 = add_future2.get().result;
  logger_ctx.LogInfo() << "Result add2: " << result_add2;

  while (!someip::tongjiDemoClient::add_event_received)
  {
    // wait for division event
    logger_ctx.LogInfo() << "Waiting for add result";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  while (!exit_requested)
  {
    // Yield the CPU to another thread
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }

  logger_ctx.LogInfo() << "Finished client operation";
  std::this_thread::sleep_for(std::chrono::seconds(5));

#ifdef ENABLE_EXEC_MANAGER
  if (args.enable_em_ && app_client.has_value())
  {
    // Report application state to execution management
    logger_ctx.LogInfo() << "Reporting application state kTerminating.";
    app_client->ReportApplicationState(ApplicationState::kTerminating);
  }
#endif

  logger_ctx.LogInfo() << "Terminating";

  // Set allocation phase to 'deallocation' before destroying and deallocating all memory resources
  logger_ctx.LogDebug() << __FUNCTION__ << " Setting AllocationPhaseManager::AllocationPhase to 'deallocation'";
  vac::memory::AllocationPhaseManager::GetInstance().SetPhase(
      vac::memory::AllocationPhaseManager::AllocationPhase::deallocation);

  return 0;
}

/**
 * \brief  Function to initialize the calculator client
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
  sigaddset(&signal_set, SIGINT);  /* Add SIGINT to set */
  while (sig != SIGTERM && sig != SIGINT)
  {
    sigwait(&signal_set, &sig);
    // We hope that the program is terminated after initialization of logging has finished, so we can call this API.
    // Otherwise a segfault will be created
    ara::log::Logger &logger_ctx{ara::log::CreateLogger(calc::config::kContextIdCalcClientMethodInvocator,
                                                        "Context for someipdemo method invocation")};
    logger_ctx.LogInfo() << "Received signal number:" << sig;
  }
  ara::log::Logger &logger_ctx{ara::log::CreateLogger(calc::config::kContextIdCalcClientMethodInvocator,
                                                      "Context for someipdemo method invocation")};
  logger_ctx.LogInfo() << "Received signal SIGTERM";
  exit_requested = true;
}
