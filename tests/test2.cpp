TEST(StateTest, HandleStateA)
{
  ConcreteStateA stateA;
  std::stringstream ss;
  std::streambuf* prev_cout = std::cout.rdbuf(ss.rdbuf()); // Перенаправляем вывод в поток
  stateA.handle();
  std::string output = ss.str();
  EXPECT_EQ(output, "State A handled.\n");
  std::cout.rdbuf(prev_cout); // Восстанавливаем предыдущий поток
}

