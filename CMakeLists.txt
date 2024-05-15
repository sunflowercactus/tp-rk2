cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_STATE_APP "Build State1" OFF)
option(BUILD_TESTS "Build tests" OFF)

add_library(State STATIC ${CMAKE_CURRENT_SOURCE_DIR}/State.cpp)

if(BUILD_STATE_APP)
    add_executable(State1 main.cpp)
    target_link_libraries(State1 State)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    add_executable(check ./tests/test.cpp)
    target_link_libraries(check State gtest_main)
    add_test(NAME check COMMAND check)
endif()

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)
target_link_libraries(demo State)
install(TARGETS demo RUNTIME DESTINATION bin)

include(CPackConfig.cmake)
