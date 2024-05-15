cmake_minimum_required(VERSION 3.10)

project(State)

add_executable(State State.cpp)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB ${StateProject}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${StateProject}_TEST_SOURCES})
  target_link_libraries(check ${StateProject} gtest_main)
  add_test(NAME check COMMAND check)
endif()
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_PROXY_APP "Build MyProxyApp" OFF)
option(BUILD_TESTS "Build tests" OFF)

add_library(Proxy STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Proxy.cpp)

if(BUILD_PROXY_APP)
    add_executable(MyProxyApp main.cpp)
    target_link_libraries(MyProxyApp Proxy)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    add_executable(check ./tests/test.cpp)
    target_link_libraries(check Proxy gtest_main)
    add_test(NAME check COMMAND check)
endif()

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)
target_link_libraries(demo state)
install(TARGETS demo RUNTIME DESTINATION bin)

include(CPackConfig.cmake)
