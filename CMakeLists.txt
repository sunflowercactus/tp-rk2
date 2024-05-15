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
