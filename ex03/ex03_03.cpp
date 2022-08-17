#include <iostream>

//Func是一个模板型模板函数，包装foreach要对每个元素进行的操作
template<template<typename TT>  struct Func, typename T>
void foreach(T array[], unsigned size)
{
    Func<T> func;
    for (unsigned i = 0; i < size; ++i) func(array[i]);
}

//三种操作都包装成函数类模板，可以通过括号操作符调用
template<typename T>
struct inc
{
    void operator()(T &v) const {++v;}
};

template<typename T>
struct dec
{
    void operator()(T &v) const {--v;}
};

template<typename T>
struct print
{
    void operator()(T &v) const {std::cout << ' ' << v;}
};

int main()
{
    using namespace std;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    foreach<print>(array, 7); //不再需要多写一遍int，在foreach自动完成
    cout << endl;

    foreach<inc>(array, 7);
    foreach<print>(array, 7);
    cout << endl;

    foreach<dec>(array, 7);
    foreach<print>(array, 7);
    cout << endl;

    return 0;
}
