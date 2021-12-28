#######################################################################################################################
#  COPYRIGHT
#  -------------------------------------------------------------------------------------------------------------------
#  \verbatim
#  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
#
#                This software is copyright protected and proprietary to Vector Informatik GmbH.
#                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
#                All other rights remain with Vector Informatik GmbH.
#  \endverbatim
#  -------------------------------------------------------------------------------------------------------------------
#  FILE DESCRIPTION
#  -----------------------------------------------------------------------------------------------------------------*/
#
#         \file
#        \brief  This is the top-level CMake build-configuration.
#
#      \details  This is the top-level CMake build-configuration.
#
#######################################################################################################################

#######################################################################################################################
#  REVISION HISTORY
#  -------------------------------------------------------------------------------------------------------------------
#  Refer to the module's ChangeHistory.txt
#
#
#  FILE VERSION
#  -------------------------------------------------------------------------------------------------------------------
#  The file version is identical to the component version. To determine the actual version of the component,
#  see the technical reference.
#
#######################################################################################################################

cmake_minimum_required(VERSION 3.4)

project(saic-someip-demo
  LANGUAGES C CXX
  VERSION "1.0.0"
)

set(CMAKE_CXX_STANDARD 14) # C++14...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++14


message(STATUS "SIP Dir is: ${SIP_Dir}")
message(STATUS "install Dir is: ${install_Dir}")

set(ComCommon_DIR ${SIP_Dir}/build/amsr-vector-fs-comcommon/.)
set(ARA_DIR ${SIP_Dir}/build/amsr-vector-fs-communicationmiddleware/.)
set(ara-logging_DIR ${SIP_Dir}/build/amsr-vector-fs-log-api/lib/libara-logging)
set(vac_DIR ${SIP_Dir}/build/amsr-vector-fs-libvac/lib/vac)
set(vajson_DIR ${SIP_Dir}/build/amsr-vector-fs-vajson/lib/vajson)
set(osabstraction_DIR ${SIP_Dir}/build/amsr-vector-fs-libosabstraction/lib)
set(amsr-vector-fs-log-api-common_DIR ${SIP_Dir}/build/amsr-vector-fs-log-api/lib/common)
set(amsr-vector-fs-log-api-ipc-common_DIR ${SIP_Dir}/build/amsr-vector-fs-log-api/lib/ipc-common)
set(vathread_DIR ${SIP_Dir}/build/amsr-vector-fs-thread/lib/vathread)
set(amsr-vector-fs-log-api-ipc_DIR ${SIP_Dir}/build/amsr-vector-fs-log-api/lib/ipc)
set(SomeIpProtocol_DIR ${SIP_Dir}/build/amsr-vector-fs-someipprotocol/.)
set(SomeIpDaemonClient_DIR ${SIP_Dir}/build/amsr-vector-fs-someipdaemonclient/.)
set(Socal_DIR ${SIP_Dir}/build/amsr-vector-fs-communicationmiddleware/.)
set(ARA-SomeIP-posix_DIR ${SIP_Dir}/build/amsr-vector-fs-communicationmiddleware/.)
set(SomeIpBinding_DIR ${SIP_Dir}/build/amsr-vector-fs-communicationmiddleware/.)
set(ARA-IpcBinding-posix_DIR ${SIP_Dir}/build/amsr-vector-fs-communicationmiddleware/.)
set(IpcBinding_DIR ${SIP_Dir}/build/amsr-vector-fs-communicationmiddleware/.)
set(vathread_DIR ${SIP_Dir}/build/amsr-vector-fs-thread/lib/vathread)
set(vathread_DIR ${SIP_Dir}/build/amsr-vector-fs-thread/lib/vathread)

# Import ARA
message(STATUS "Importing ARA")
find_package(ARA REQUIRED)
message(STATUS "    Package ARA found: ${ARA_FOUND}")

# Import ARA-SomeIP-posix
message(STATUS "Importing ARA-SomeIP-posix")
find_package(ARA-SomeIP-posix REQUIRED)
message(STATUS "    Package ARA-SomeIP-posix found: ${ARA-SomeIP-posix_FOUND}")

# Import Threads
message(STATUS "Importing Threads")
find_package(Threads REQUIRED)
message(STATUS "    Package Threads found: ${Threads_FOUND}")

# Import Logging API
message(STATUS "Importing ara-logging")
find_package(ara-logging REQUIRED)
message(STATUS "    Package ara-logging found: ${ara-logging_FOUND}")

# Import ApplicationClient
message(STATUS "Importing EM ApplicationClient")

option (ENABLE_EXEC_MANAGER "Enable Vector Execution Manager support" OFF)
if(ENABLE_EXEC_MANAGER)
  add_definitions(-DENABLE_EXEC_MANAGER)
endif()
message(STATUS "option -DENABLE_EXEC_MANAGER=" ${ENABLE_EXEC_MANAGER})

if(ENABLE_EXEC_MANAGER)
  set(VectorApplicationClient amsr-vector-fs-em-executionmanagement_application-client)
  find_package(${VectorApplicationClient} QUIET)
  set(ARA_EXEC_LIBRARIES ${${VectorApplicationClient}_LIBRARIES})
  message(STATUS "    Package ApplicationClient (Vector) found with libraries: ${ARA_EXEC_LIBRARIES}")
  set(ARA_EXEC_INCLUDE_DIRS ${${VectorApplicationClient}_INCLUDE_DIRS})
endif()

# Import vac
message(STATUS "Importing vac")
find_package(vac REQUIRED)
message(STATUS "    Package vac found: ${vac_FOUND}")

message(STATUS "-- User options ---------------------------------------------")
set(ADAPTIVE_MICROSAR_SRC_GEN_DIR "${PROJECT_SOURCE_DIR}/src-gen" CACHE PATH "Directory containing generated artifacts.")
message(STATUS "option -DADAPTIVE_MICROSAR_SRC_GEN_DIR=\"${ADAPTIVE_MICROSAR_SRC_GEN_DIR}\"")


if(NOT DEFINED APPLICATION_PREFIX)
  SET(APPLICATION_PREFIX /opt)
endif()

if(NOT DEFINED SOMEIPD_CONFIG_DIR)
  SET(SOMEIPD_CONFIG_DIR /opt/someipd_posix/etc)
endif()

option(ENABLE_CODE_GENERATION "Enable code generation." ON) 
message(STATUS "option -DENABLE_CODE_GENERATION=${ENABLE_CODE_GENERATION}")
if(ENABLE_CODE_GENERATION)
  # Directory containing all containers
  set(GENERATORS_COMMON_DIR "" CACHE PATH "Directory containing all generators")
  message(STATUS "Generators Root Directory: -DGENERATORS_COMMON_DIR=${GENERATORS_COMMON_DIR}")
endif()

message(STATUS "-------------------------------------------------------------")

add_subdirectory(src)




# Deploy
install(FILES ${PROJECT_SOURCE_DIR}/etc/someip-posix/someipd-posix.json
  PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
  DESTINATION ${SOMEIPD_CONFIG_DIR}
)
install(FILES ${PROJECT_SOURCE_DIR}/etc/someip-posix/someipd-posix-gen.json
  PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
  DESTINATION ${SOMEIPD_CONFIG_DIR}
)

