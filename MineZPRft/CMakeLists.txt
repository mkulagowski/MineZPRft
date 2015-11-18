# @file
# @author LKostyra (costyrra.xl@gmail.com)
# @brief  CMake for MineZPRft

MESSAGE("Generating Makefile for MineZPRft")

FILE(GLOB COMMON_SOURCES       Common/*.cpp)
FILE(GLOB COMMON_HEADERS       Common/*.hpp)
FILE(GLOB COMMON_LINUX_SOURCES Common/Linux/*.cpp)
FILE(GLOB COMMON_LINUX_HEADERS Common/Linux/*.hpp)
FILE(GLOB GAME_SOURCES         Game/*.cpp)
FILE(GLOB GAME_HEADERS         Game/*.hpp)

# Search for dependencies
PKG_CHECK_MODULES(MINEZPRFT_DEPS REQUIRED
                  x11
                  gl)

# setup directories
INCLUDE_DIRECTORIES(${MINEZPRFT_DEPS_INCLUDE_DIRS})

ADD_EXECUTABLE(MineZPRft ${COMMON_SOURCES} ${COMMON_HEADERS}
                         ${COMMON_LINUX_SOURCES} ${COMMON_LINUX_HEADERS}
                         ${GAME_SOURCES} ${GAME_HEADERS})
TARGET_LINK_LIBRARIES(MineZPRft ${MINEZPRFT_DEPS_LIBRARIES})
ADD_CUSTOM_COMMAND(TARGET MineZPRft POST_BUILD COMMAND
                   ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MineZPRft> ${MZPR_OUTPUT_DIRECTORY}/${targetfile})
