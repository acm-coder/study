// 取得嵌套在N中的第i层type_shift_node
template<unsigned i, typename T0, typename T1, typename T2, typename T3>
auto get_node(type_shift_node<T0, T1, T2, T3> &n)
{
    return get_node<i-1, T0, T1, T2, T3>(n).next;
}

// 假想的函数特例，第0层嵌套即N本身
template<typename T0, typename T1, typename T2, typename T3>
auto get_node<0>(type_shift_node<T0, T1, T2, T3> &n)
{
    return n;
}

// 取得第i层嵌套type_shift_node后即其data成员即可
template<unsigned i, typename T0, typename T1, typename T2, typename T3>
auto get(my_tuple<T0, T1, T2, T3> &tup)
{
    return get_node<i, T0, T1, T2, T3>(tup.data).data;
}
