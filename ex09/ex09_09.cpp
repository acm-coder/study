#include <functional>

void to_bind(int a, int b, int c) {
    std::cout << a << ", " << b << ", " << c << std::endl;
}

void foo(int a, int b, int c)
{
    using namespace std::placeholders; // 引入所有的_1、 _2等常数
    using std::bind;
    // 将参数全部绑定为固定值
    auto f0 = bind(to_bind, 0, 0, 0);
    f0();                       // to_bind(0, 0, 0);

    // 同样是将参数全部绑定为固定值
    int x = 1, y = 2, z = 3;
    auto f1 = bind(to_bind, x, y, z);
    f1();                       // to_bind(1, 2, 3);

    // 将参数与所生成的函数对象（即f2）的参数顺序一一关联
    auto f2 = bind(to_bind, _1, _2, _3);
    f2(a, b, c);                // to_bind(a, b, c);

    // 将参数与所生成的函数对象（即f3）的参数逆序一一关联
    auto f3 = bind(to_bind, _3, _2, _1);
    f3(a, b, c);                // to_bind(c, b, a);

    // 混合绑定方式
    auto f4 = bind(to_bind, 0, x, _1);
    f4(a);                      // to_bind(0, 1, a);
}
