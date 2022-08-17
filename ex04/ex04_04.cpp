#include <iostream>

template<typename T0, typename T1, typename T2>
struct S
{
    std::string id() {return "General";}
};

//特例1，约束第三参数必须为char
template<typename T0, typename T1>
struct S<T0, T1, char>
{
    std::string id() {return "Specialization #1";}
};

//特例2，约束第二、第三参数必须均为char
template<typename T0>
struct S<T0, char, char>
{
    std::string id() {return "Specialization #2";}
};

//特例3，约束第一参数必须为int，且第二、第三参数相同
template<typename T>
struct S<int, T, T>
{
    std::string id() {return "Specialization #3";}
};

int main()
{
    using namespace std;
    cout << S<float, float, float>().id() << endl; //实例1
    cout << S<int, int, int>().id() << endl;       //实例2
    cout << S<int, int, char>().id() << endl;      //实例3
    cout << S<char, char, char>().id() << endl;    //实例4
    //cout << S<int, char, char>().id() << endl;   //实例5，有歧义
}
