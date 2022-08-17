#include <iostream>

template<int i>
void print()
{
  print<i-1>();
  std::cout << i << std::endl;
}

//特例，终止递归。
template<>
void print<1>()
{
  std::cout << 1 << std::endl;
}

int main()
{
  print<100>();
}
