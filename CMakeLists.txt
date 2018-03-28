cmake_minimum_required(VERSION 3.0)
project(litestorecpp VERSION 0.1.0)
include(GNUInstallDirs)
#include(gtest.cmake)

set(LIB_DIR ${PROJECT_SOURCE_DIR}/libs)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/tests)

# subdirs
add_subdirectory(${LIB_DIR}/liblitestore)
add_subdirectory(${TEST_DIR})

# main target
add_library(litestorecpp SHARED
    ${SRC_DIR}/litestorecpp.cpp)
target_compile_options(litestorecpp
    PUBLIC -fPIC
    # -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef
    PRIVATE -std=c++14 -O3 -Wall -Wextra -Werror -pedantic)
target_include_directories(litestorecpp
    INTERFACE ${INCLUDE_DIR}
    PRIVATE ${INCLUDE_DIR}
)
target_link_libraries(litestorecpp
    PUBLIC litestore) # export litestore

#CONFIGURE_FILE(
#  "${CMAKE_CURRENT_SOURCE_DIR}/pkg-config.pc.cmake"
#  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
#)

# install directives
install(TARGETS litestorecpp LIBRARY
    DESTINATION lib)
install(FILES
    ${INCLUDE_DIR}/litestore/litestorecpp.hpp
    DESTINATION include/litestorecpp)
install(FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc"
    DESTINATION lib/pkgconfig)

