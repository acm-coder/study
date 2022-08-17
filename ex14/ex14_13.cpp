template<typename T0, typename T1>
typename get_compatible_type<T0&&, T1&&>::type
smart_min(T0 &&p0, T1 &&p1)
{
    typedef typename get_compatible_type<T0&&, T1&&>::type return_type;
    if (p0 < p1) return static_cast<return_type>(p0);
    return static_cast<return_type>(p1);
}

void foo()
{
    int a, b;
    smart_min(a, b)++;             // 可编译。将返回一个左值引用
    int const &cra(a);
    int const &cra2(smart_min(a, cra)); // 可编译。将返回一个只读左值引用

    using std::move;
    huge_data ha, hb;
    // 可编译。将返回右值引用，故将调用移动构造函数
    huge_data hc = smart_min(move(ha), move(hb));
    huge_data hd = smart_min(ha, move(hb));       // 可编译。将返回只读左值引用
}
