// 适用于前向迭代器的advance函数实现，n次加1操作
template<typename I>
void advance_impl(I &i,
                  typename std::iterator_traits<I>::difference_type n,
                  std::forward_iterator_tag)
{for (; n > 0; --n) ++i;}

// 适用于跳转迭代器的advance函数实现，直接用i += n
template<typename I>
void advance_impl(I &i,
                  typename std::iterator_traits<I>::difference_type n,
                  std::random_access_iterator_tag)
{i += n;}

template<typename I>
void advance(I &i, typename I::difference_type n)
{
    // 以iterator_category()为哑参数指导编译器选择适当的重载实现
    advance_impl(i, n,
                 typename std::iterator_traits<I>::iterator_category());
}
