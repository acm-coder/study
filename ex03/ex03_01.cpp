#include <iostream>

//定义一个foreach函数模板，对数组的每一个元素进行某种操作
//具体操作由模板的函数指针参数指定
template<typename T, void (*f)(T &v)>
void foreach(T array[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i) f(array[i]);
}

//三个函数模板用来定义对数组元素的操作
template<typename T>
void inc(T &v) {++v;}

template<typename T>
void dec(T &v) {--v;}

template<typename T>
void print(T &v) {std::cout << ' ' << v;}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

    using namespace std;
    foreach<int, print<int> >(array, 8);
    cout << endl;

    foreach<int, inc<int> >(array, 8);
    foreach<int, print<int> >(array, 8);
    cout << endl;

    foreach<int, dec<int> >(array, 8);
    foreach<int, print<int> >(array, 8);
    cout << endl;

    return 0;
}
