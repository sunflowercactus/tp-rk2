#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../State.cpp"

TEST(StateTest, StateAHandle)
{
  ConcreteStateA stateA;
  
  testing::internal::CaptureStdout();
  stateA.handle();
  std::string output = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ("State A handled.\n", output);
}

TEST(StateTest, StateBHandle)
{
  ConcreteStateB stateB;
  
  testing::internal::CaptureStdout();
  stateB.handle();
  std::string output = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ("State B handled.\n", output);
}

TEST(ContextTest, ContextSetState)
{
  Context context;
  ConcreteStateA stateA;
  
  context.setState(&stateA);
  
  testing::internal::CaptureStdout();
  context.request();
  std::string output = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ("State A handled.\n", output);
}
