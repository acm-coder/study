int ext;
// auto f_glb = [ext] {}; // 全局λ表达式不能捕获变量，也不允许捕获全局变量ext
auto f_glb_1 = [] {return ext;}; // 全局变量直接使用，无须捕获

void foo(int param)
{
    using namespace std;
    int local;
    static int static_local;

    // 捕获local, param，直接使用ext
    auto f0 = [local, param] {return local + param + ext;};

    // 不捕获，直接使用static_local
    auto f1 = [] {return static_local++;};

    // 错误的用法。不能捕获函数的静态局部变量
    // auto f1 = [static_local] {return static_local++;};

    struct bar {
        void beep() const {}
        void mem_func() {
            auto f2 = [this] {
                beep();
                return mem++;
            };
            // local与param对于成员函数mem_func的函数体都不可见
            // auto f3 = [=] {return local;};
            // auto f4 = [=] {return param;};
        }
        int mem;
    };
}
