#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../State.cpp"


// Test case to check if the context object handles state A correctly
TEST(StatePatternTest, StateAHandling) {
  Context context;
  State* stateA = new ConcreteStateA();
  context.setState(stateA);

  testing::internal::CaptureStdout();
  context.request();
  std::string output = testing::internal::GetCapturedStdout();

  ASSERT_EQ(output, "State A handled.\n");
  delete stateA;
}

// Test case to check if the context object handles state B correctly
TEST(StatePatternTest, StateBHandling) {
  Context context;
  State* stateB = new ConcreteStateB();
  context.setState(stateB);

  testing::internal::CaptureStdout();
  context.request();
  std::string output = testing::internal::GetCapturedStdout();

  ASSERT_EQ(output, "State B handled.\n");
  delete stateB;
}

// Test case to check if the context object changes states correctly
TEST(StatePatternTest, StateChange) {
  Context context;
  State* stateA = new ConcreteStateA();
  context.setState(stateA);

  testing::internal::CaptureStdout();
  context.request();
  std::string outputA = testing::internal::GetCapturedStdout();

  State* stateB = new ConcreteStateB();
  context.setState(stateB);

  testing::internal::CaptureStdout();
  context.request();
  std::string outputB = testing::internal::GetCapturedStdout();

  ASSERT_EQ(outputA, "State A handled.\n");
  ASSERT_EQ(outputB, "State B handled.\n");
  delete stateA;
  delete stateB;
}