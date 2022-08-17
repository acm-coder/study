#include "concept_check.hpp"

template<typename T>
T& min(T &a, T &b)
{
    less_than_comparable<T>::check(); // 概念检查语句

    if (a < b) return a;
    return b;
}

class my_class {};              // 不可进行“小于”比较的类型

int main()
{
    my_class a, b;
    min(a, b);               // my_class并不满足min的要求
    return 0;
}
