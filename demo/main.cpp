#include "./../State.cpp"
int main()
{
  Context *context = new Context();
  
  context->setState( new ConcreteStateA() );
  context->request();
  
  context->setState( new ConcreteStateB() );
  context->request();
  
  delete context;
  return 0;
}
