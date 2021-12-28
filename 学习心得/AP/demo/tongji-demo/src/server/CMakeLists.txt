#######################################################################################################################
#  COPYRIGHT
#  -------------------------------------------------------------------------------------------------------------------
#  \verbatim
#  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
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
#        \brief  This file is part of the CMake build-configuration.
#
#      \details  This file is part of the CMake build-configuration.
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

set(TARGET_NAME Server)

# Collect Static Sources
file(GLOB_RECURSE CALCULATORSERVER_SRCS ${PROJECT_SOURCE_DIR}/src/server/*.cc ${PROJECT_SOURCE_DIR}/src/config/*.cc ${PROJECT_SOURCE_DIR}/src/common/*.cc)
message(STATUS "CALCULATORSERVER_SRCS: ${CALCULATORSERVER_SRCS}")

file(GLOB_RECURSE CALCULATORSERVER_GEN_SRCS_SOMEIP ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix/*.cc ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix/*.cpp)
file(GLOB_RECURSE CALCULATORSERVER_GEN_SRCS ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/src/*.cc ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/src/*.cpp)
set(CALCULATORSERVER_GEN_SRCS ${CALCULATORSERVER_GEN_SRCS} ${CALCULATORSERVER_GEN_SRCS_SOMEIP})
message(STATUS "CALCULATORSERVER_GEN_SRCS: ${CALCULATORSERVER_GEN_SRCS}")

# Build
add_executable(${TARGET_NAME} ${CALCULATORSERVER_SRCS} ${CALCULATORSERVER_GEN_SRCS})

# Collect Includes
target_include_directories(${TARGET_NAME} PRIVATE
    ${VAC_INCLUDE_DIRS}
    ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/includes
    ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix
    ${ARA_LOGGING_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/src/common
)

target_link_libraries(${TARGET_NAME}
    ${ARA_SOMEIP_POSIX_LIBRARIES}
    ${ADAPTIVEPLATFORM_LIBRARIES}
    ${ARA_LIBRARIES}
    ${ARA_LOGGING_LIBRARIES}
    ${VAC_LIBRARIES}
)

target_link_libraries(${TARGET_NAME} ${ARA_EXEC_LIBRARIES})

# Create link to config files
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMENT "Creating symlink to logging_config file"
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/src/server/etc/
        COMMAND ln -sf ${PROJECT_SOURCE_DIR}/etc/server/logging_config.json ${CMAKE_BINARY_DIR}/src/server/etc/logging_config.json)

# Deploy
install(TARGETS ${TARGET_NAME} RUNTIME
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/bin)
install(FILES ${MANIFEST_FILE_SERVER}
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc
        RENAME ${MANIFEST_TARGET_FILENAME})
install(FILES ${PROJECT_SOURCE_DIR}/etc/${TARGET_NAME}/logging_config.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
install(FILES ${PROJECT_SOURCE_DIR}/etc/${TARGET_NAME}/application.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/configuration/someip_config.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc/)
if(ENABLE_EXEC_MANAGER)
  install(FILES ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/configuration/exec_config.json
          PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
          DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc RENAME exec_config.json)
endif()
