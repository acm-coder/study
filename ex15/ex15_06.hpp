// my_tuple的实现类模板，要求至少有一个模板参数，即至少保存一个元素
template<typename T, typename ...TPack>
struct my_tuple_impl
{
    typedef T data_type;
    data_type data;             // data保存首个模板参数类型数据

    typedef my_tuple_impl<TPack...> next_type;
    next_type next;             // 剩余类型数据通过递归调用
                                // my_tuple_impl来保存

    // 构造函数
    my_tuple_impl(T const &d, TPack const & ...ppack) :
        data(d), next(ppack...) {}
};

// 用于终止递归的my_tuple_impl特例
template<typename T>
struct my_tuple_impl<T>
{
    typedef T data_type;
    data_type data;
    my_tuple_impl(T const &d) : data(d) {}
};

// my_tuple类模板，可以保存0到多个任意类型数据。通例实现保存1到多个数据，
// 调用my_tuple_impl类实现
template<typename ...TPack>
struct my_tuple
{
    my_tuple_impl<TPack...> impl;
    my_tuple(TPack const & ...ppack) : impl(ppack...) {}
};

// 特例实现保存0个数据
template<>
struct my_tuple<> {
    my_tuple() {}
};
