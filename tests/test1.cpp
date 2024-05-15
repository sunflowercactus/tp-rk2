#include <State.cpp>
#include <gtest/gtest.h>
TEST(StateTest, HandleStateB)
{
  ConcreteStateB stateB;
  std::stringstream ss;
  std::streambuf* prev_cout = std::cout.rdbuf(ss.rdbuf()); // Перенаправляем вывод в поток
  stateB.handle();
  std::string output = ss.str();
  EXPECT_EQ(output, "State B handled.\n");
  std::cout.rdbuf(prev_cout); // Восстанавливаем предыдущий поток
}
