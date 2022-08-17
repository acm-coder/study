//--------------------------------
//文件名：call1.cpp
#include <iostream>
#include "the_class.hpp"

void call1()
{
    the_class<int> c;
    std::cout << c.id << std::endl;
}
