#include <gtest/gtest.h>
#include "StatePattern.h"

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
