TEST(StateTest, HandleStateA)
{
  ConcreteStateA stateA;
  testing::internal::CaptureStdout();
  stateA.handle();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "State A handled.\n");
}

