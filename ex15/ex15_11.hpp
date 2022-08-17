// 终止递归用重载函数模板
template <typename RetT, typename T>
T const& sum_impl(T const &v) {return v;}

// 返回值由模板参数决定
template <typename RetT, typename T, typename ...TPack>
RetT sum_impl(T const &v, TPack const &...ppack)
{
    return v + sum_impl<RetT>(ppack...);
}

// sum函数是个外壳，确定返回值类型后调用sum_impl实现
template<typename ...TPack>
typename highest_precision_of<TPack...>::type
sum(TPack const &...ppack)
{
    typedef typename highest_precision_of<TPack...>::type return_type;
    return sum_impl<return_type>(ppack...);
}
