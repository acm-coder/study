template <typename T0, typename ...TPack>
struct highest_precision_of
{
    typedef typename highest_precision_of<TPack...>::type T1;
    // 先求得剩余参数中精度最高的类型
    typedef decltype(T0(0) + T1(0)) type;
    // 两数相加，结果类型与两者中精度高者相同
};

// 终止递归用
template <typename T0>
struct highest_precision_of<T0>
{
    typedef T0 type;
};
