// 续文件meta_vector.hpp
// 元函数find_n。实现在元容器V中从0到i-1位的类型中搜索类型T
template<typename V, typename T, unsigned i>
struct find_n
{
    typedef typename get<V, i>::return_type type_i; // 取得第i位类型type_i.

    // if (type_i == T) return T;
    // else return find_n<V, T, i-1>::return_type;
    typedef typename if_call<is_same<T, type_i>::result,
                             pipe_<T>,
                             find_n<V, T, i - 1> >::return_type return_type;
};

// find_n特例，中止递归
template<typename V, typename T>
struct find_n<V, T, 0>
{
    typedef typename get<V, 0>::return_type type_0; // 取得第0位类型type_0
    // if (type_0 == T) return T;
    // else return void;
    typedef typename if_<is_same<T, type_0>::result,
                         T, void>::return_type return_type;
};
    
// 元函数find，从元容器V中搜索类型T，如果搜到T，则返回T，否则返回void
template<typename V, typename T>
struct find
{
    static const unsigned size = V::size;
    // 调用递归元函数find_n实现搜索
    typedef typename find_n<V, T, size - 1>::return_type return_type;
};
