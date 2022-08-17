// 第i层type_shift_node的特性类
template<unsigned i, typename T0, typename T1, typename T2, typename T3>
struct type_shift_node_traits
{
    typedef type_shift_node<T0, T1, T2, T3> top_node_type; // 顶层节点类型

    // 上一层特性类类型
    typedef type_shift_node_traits<i - 1, T0, T1, T2, T3> prev_level_traits;
    // 由上一层节点类型得到本层节点类型
    typedef typename prev_level_traits::node_type::next_type node_type;
    // 再定义与节点类型有关的引用类型
    typedef node_type& node_reference;
    typedef node_type const& node_const_reference;

    // 本层节点所存数据类型
    typedef typename node_type::data_type data_type;

    // 取得本层嵌套节点引用
    static
    node_reference
    get_node(top_node_type &n) {
        // 本层节点即上层节点的next成员变量
        return prev_level_traits::get_node(n).next;
    }
};

// 特性类特例，用于顶层节点时
template<typename T0, typename T1, typename T2, typename T3>
struct type_shift_node_traits<0, T0, T1, T2, T3>
{
    typedef type_shift_node<T0, T1, T2, T3> top_node_type;
    typedef top_node_type node_type; // 本层节点类型即顶层节点类型
    // 相关引用类型定义
    typedef node_type& node_reference;
    typedef node_type const& node_const_reference;

    // 顶层节点所存数据类型
    typedef typename node_type::data_type data_type;

    // 直接返回顶层节点的引用
    static
    node_reference
    get_node(top_node_type &n) {return n;}
    
};

// 利用type_shift_node_traits得到相应层节点所存数据类型作为返回值类型
template<unsigned i, typename T0, typename T1, typename T2, typename T3>
typename type_shift_node_traits<i, T0, T1, T2, T3>::data_type
get(my_tuple<T0, T1, T2, T3> &tup)
{
    return type_shift_node_traits<i, T0, T1, T2, T3>::get_node(tup.data).data;
}
