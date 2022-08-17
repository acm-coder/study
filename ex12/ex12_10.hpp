struct null_type {};            // 空类型，用于标记参数列表末尾

template <typename T0, typename T1, typename T2, typename T3>
struct type_shift_node
{
    typedef T0 data_type;
    typedef type_shift_node<T1, T2, T3, null_type> next_type;

    data_type data;             // 本节点保存T0类型的数据
    next_type next; // 其余类型移位后用另一个type_shift_node实例实现

    type_shift_node() : data(), next() {} // 默认构造函数
    type_shift_node(T0 const &d0, T1 const &d1, T2 const &d2, T3 const &d3) :
        data(d0), next(d1, d2, d3, null_type()) {}
    // 在给定数据的构造函数中，与类型移位的原理类似，参数值通过移位及用
    // null_type()补全后用来设置各个节点的data值
};
