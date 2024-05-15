#include <gtest/gtest.h>
#include "StatePattern.h"
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
