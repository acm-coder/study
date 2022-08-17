//--------------------------------
//文件名：call.cpp
#include <iostream>
#include "the_class.hpp"

void call()
{
    the_class<int> c;
    std::cout << c.id << std::endl;
}
