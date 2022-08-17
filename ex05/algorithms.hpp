// 文件名：algorithms.hpp

#include <iostream>

// 迭代器特性模板，通例
template<typename I>
struct iterator_traits
{
    typedef typename I::value_type value_type;
};

// 迭代器特性模板，特例，用于指针
template<typename P>
struct iterator_traits<P*>
{
    typedef P value_type;
};

// 打印容器内数据
template<typename I>
void print(I begin, I end)
{
    if (begin != end) {
        std::cout<<*begin;
        for (++begin; begin != end; ++begin)
            std::cout<<' '<<*begin;
        std::cout<<std::endl;
    }
}

// 求指定范围内数据之和
template<typename I>
typename iterator_traits<I>::value_type
sum(I begin, I end)
{
    typedef typename iterator_traits<I>::value_type value_type;

    value_type sum(0);
    for (; begin != end; ++begin) sum += *begin;
    return sum;
}

// 指定范围内数据循环移位
template<typename I>
void shift(I begin, I end)
{
    typedef typename iterator_traits<I>::value_type value_type;

    I it = begin;
    if (it != end) {
        value_type v = *begin, tmp;

        for (++it; it != end; ++it) {
            // 交换v与it所指的值
            tmp = *it;
            *it = v;
            v = tmp;
        }
        *begin = v;
    }
    return;
}

// 在容器内查找并定位指定数据
template<typename I>
I find(I begin, I end, typename I::value_type const &v)
{
    for (; begin != end; ++begin)
        if (*begin == v) break;
    return begin;
}
