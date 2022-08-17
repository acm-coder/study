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
