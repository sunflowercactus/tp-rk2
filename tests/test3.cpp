TEST(ContextTest, Request)
{
  Context context;
  ConcreteStateA stateA;
  context.setState(&stateA);
  testing::internal::CaptureStdout();
  context.request();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "State A handled.\n");
}
