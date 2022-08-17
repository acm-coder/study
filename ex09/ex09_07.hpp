template<typename Iterator, typename V>
void for_each_call_erase(Iterator begin, Iterator end, V v)
{
    typedef std::iterator_traits<Iterator> traits;
    typedef typename traits::value_type container_type;
    typedef typename container_type::size_type size_type;
    typedef typename container_type::key_type key_type;

    // 用于分辨重载函数
    size_type (container_type::*erase_func)(key_type const&) =
        &container_type::erase;

    std::for_each(begin, end, std::bind2nd(std::mem_fun_ref(erase_func), v));
}
