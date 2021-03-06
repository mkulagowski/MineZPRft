# @file
# @author LKostyra (costyrra.xl@gmail.com)
# @brief  Main CMake file for MineZPRft

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(MineZPRft)

MESSAGE("Generating Makefiles for MineZPRft project")

INCLUDE(FindPkgConfig)

# Pre-define Release build
IF(NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    SET(CMAKE_BUILD_TYPE Release)
ENDIF(NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")

# If we build in Debug, add a macro which will inform the entire project about it
# Might be needed for example in Logger or some Debug-only macros
IF(CMAKE_BUILD_TYPE STREQUAL Debug)
    ADD_DEFINITIONS(-D_DEBUG)
ENDIF(CMAKE_BUILD_TYPE STREQUAL Debug)

# Pre-define 64-bit build platform
IF(NOT DEFINED BUILD_PLATFORM)
    EXECUTE_PROCESS(COMMAND uname -m
                    OUTPUT_VARIABLE BUILD_PLATFORM OUTPUT_STRIP_TRAILING_WHITESPACE)
ENDIF(NOT DEFINED BUILD_PLATFORM)

# Set required variables
SET(CMAKE_CXX_FLAGS       "${CMAKE_CXX_FLAGS} -O2 -std=c++0x")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG -O0 -g -std=c++0x")

# If any macros specific to project are needed, prefix them with MZPR_
SET(MZPR_ROOT_DIRECTORY ${CMAKE_SOURCE_DIR})
SET(MZPR_OUTPUT_DIRECTORY ${MZPR_ROOT_DIRECTORY}/Bin/${BUILD_PLATFORM}/${CMAKE_BUILD_TYPE})

# Enable all warnings and make them errors
ADD_DEFINITIONS("-Wall -Wpedantic -Wextra -Wno-sign-compare -Werror")

# Building outputs
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MZPR_OUTPUT_DIRECTORY})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MZPR_OUTPUT_DIRECTORY})

MESSAGE("Build type is ${CMAKE_BUILD_TYPE}")
MESSAGE("Output path is ${MZPR_OUTPUT_DIRECTORY}")
MESSAGE("Platform is ${BUILD_PLATFORM}")

# Add all projects
ADD_SUBDIRECTORY("gtest")
ADD_SUBDIRECTORY("MineZPRft")
ADD_SUBDIRECTORY("MineZPRftTest")

FILE(MAKE_DIRECTORY ${MZPR_OUTPUT_DIRECTORY})
