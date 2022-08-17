// 终止递归用重载函数模板
template <typename T>
T const& sum(T const &v) {return v;}

template <typename T, typename ...TPack>
T sum(T const &v, TPack const &...ppack)
{
    return v + sum(ppack...);
    // 将ppack展开再应用于sum函数模板，则包内首个实参将映射至非包参数v
    // 直至ppack只含有一个实参时将调用上一个重载函数模板实现，递归终止
}
