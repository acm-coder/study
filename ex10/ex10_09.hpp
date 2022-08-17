// 要求模板参数I实现输入迭代器概念，参数T必须可进行“相等”比较
template<typename I, typename T>
BOOST_CONCEPT_REQUIRES(((boost::InputIterator<I>))
                       ((boost::EqualityComparable<T>)),
                       (I))     // 函数返回一个迭代器
find(I start, I end, T const &v)
{
    for (; start != end; ++start)
        if (*start == v) return start;
    return end;
}

// 将BOOST_CONCEPT_REQUIRES用于类模板的成员函数
template<typename T0, typename T1>
struct pair
{
    T0 first;
    T1 second;

    BOOST_CONCEPT_ASSERT((boost::CopyConstructible<T0>));
    BOOST_CONCEPT_ASSERT((boost::CopyConstructible<T1>));

    // 构造函数无返回值，故也不能用BOOST_CONCEPT_REQUIRES
    pair(T0 const &first, T1 const &second) : first(first), second(second) {}

    // 要求T0与T1都可进行“相等”比较
    BOOST_CONCEPT_REQUIRES(((boost::EqualityComparable<T0>))
                           ((boost::EqualityComparable<T1>)),
                           (bool)) // 函数返回值是bool
    operator == (pair r) {
        return (first == r.first) && (second == r.second);
    }
};
