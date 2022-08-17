#include <iostream>

//#1
template<typename T>
void func(T v) {std::cout << "#1: " << v << std::endl;}

//#2
template<>
void func(float v) {std::cout << "#2: " << v << std::endl;}

//#3
void func(float v) {std::cout << "#3: " << v << std::endl;}

//#4
void func2(float v) {std::cout << "#4: " << v << std::endl;}

int main()
{
    func2(1); //输出“#4: 1”
    func(1); //输出“#1: 1”
    func(1.); //输出“#1: 1”
    func(1.f); //输出“#3: 1”
    func<>(1.f); //输出“#2: 1”
}
