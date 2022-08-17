// 以右值引用为参数的min函数
template<typename T>
T&& smart_min(T &&p0, T &&p1)
{
    using std::forward;
    if (p0 < p1) return forward<T>(p0); // 莫忘用std::forward进行自动转义
    else return forward<T>(p1);         // 同上
}

void foo()
{
    int a, b;
    smart_min(a, b)++;             // 可编译。将返回一个左值引用
    int const &cra(a);
    smart_min(a, cra);             // 不可编译

    using std::move;
    huge_data ha, hb;
    huge_data hc = smart_min(move(ha), move(hb)); // 可编译，将返回右值引用
}
