TEST(StateTest, HandleStateB)
{
  ConcreteStateB stateB;
  testing::internal::CaptureStdout();
  stateB.handle();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "State B handled.\n");
}

