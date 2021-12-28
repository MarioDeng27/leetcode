#######################################################################################################################
#  COPYRIGHT
#  -------------------------------------------------------------------------------------------------------------------
#  \verbatim
#  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
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

set(TARGET_NAME Client)


# Get direct dependencies

message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing ARA-IpcBinding-posix")
find_package(ARA-IpcBinding-posix REQUIRED)
message(STATUS "Package ARA-IpcBinding-posix found: ${ARA-IpcBinding-posix_FOUND}")



# Collect Sources
file(GLOB_RECURSE CALCULATORCLIENT_SRCS
    ${PROJECT_SOURCE_DIR}/src/client/*.cc
    ${PROJECT_SOURCE_DIR}/src/client/*.cpp
    ${PROJECT_SOURCE_DIR}/src/common/*.cc
)
message(STATUS "CALCULATORCLIENT_SRCS: ${CALCULATORCLIENT_SRCS}")

# Collect Generated Sources
file(GLOB_RECURSE CALCULATORCLIENT_GEN_SRCS_ALL
    ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/*.cc
    ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/*.cpp
)
set(CALCULATORCLIENT_GEN_SRCS
    ${CALCULATORCLIENT_GEN_SRCS}
    ${CALCULATORCLIENT_GEN_SRCS_ALL}
)
message(STATUS "CALCULATORCLIENT_GEN_SRCS: ${CALCULATORCLIENT_GEN_SRCS}")


# Add Target
add_executable(${TARGET_NAME}
    ${CALCULATORCLIENT_SRCS}
    ${CALCULATORCLIENT_GEN_SRCS}
    ${LIB_ARA_DIAG_SOURCES}
    ${PERSISTENCY_SOURCES}
)


target_link_libraries(${TARGET_NAME} PRIVATE
    ${ARA_IPC_BINDING_POSIX_LIBRARIES}
    ${ARA_SOMEIP_POSIX_LIBRARIES}
    ${ARA_LOGGING_LIBRARIES}
    ${VAC_LIBRARIES}
)





if(ENABLE_EXEC_MANAGER)
    target_link_libraries(${TARGET_NAME} PRIVATE
        ${ARA_EXEC_LIBRARIES}
    )
    target_include_directories(${TARGET_NAME} PRIVATE
        ${EXEC_MANAGER_INCLUDE_DIRS}
    )
endif()


# Collect Includes
target_include_directories(${TARGET_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/addon/${TARGET_NAME}/
    ${PROJECT_SOURCE_DIR}/src/common
    ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/includes
    ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/someip-posix
    ${ADAPTIVE_MICROSAR_SRC_GEN_DIR}/${TARGET_NAME}/ipc-posix
    ${VAC_INCLUDE_DIRS}
    ${ARA_LOGGING_INCLUDE_DIRS}
    ${ARA_IPC_BINDING_POSIX_INCLUDE_DIRS}
    ${ARA_SOMEIP_POSIX_INCLUDE_DIRS}
)


# Create link to config files
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMENT "Creating symlink to logging_config file"
    COMMAND mkdir -p ${CMAKE_BINARY_DIR}/src/client/etc/
    COMMAND mkdir -p ${CMAKE_BINARY_DIR}/src/client/var/
    COMMAND ln -sf ${PROJECT_SOURCE_DIR}/etc/client/logging_config.json ${CMAKE_BINARY_DIR}/src/client/etc/logging_config.json)

# Deploy
install(TARGETS ${TARGET_NAME} RUNTIME
    DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/bin)
install(FILES ${MANIFEST_FILE_CLIENT}
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
    DESTINATION ${APPLICATION_PREFIX}/${TARGET_NAME}/etc RENAME ${MANIFEST_TARGET_FILENAME})
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
