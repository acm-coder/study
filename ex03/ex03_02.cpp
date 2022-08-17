#include <iostream>

class some_value;

typedef int (some_value::* some_value_mfp)(int);

template<some_value_mfp func> //func是一个成员函数指针型模板参数
int call(some_value &value, int op) {return (value.*func)(op);}

class some_value
{
    int value;
public:
    some_value(int _value) : value(_value) {}
    int add_by(int op) {return value += op;}
    int sub_by(int op) {return value -= op;}
    int mul_by(int op) {return value *= op;}
};

int main()
{
    using namespace std;
    some_value v0(0);
    cout << call<&some_value::add_by>(v0, 1) << endl;
    cout << call<&some_value::sub_by>(v0, 2) << endl;
    cout << call<&some_value::mul_by>(v0, 3) << endl;
}
