template<typename I>
typename iterator_traits<I>::value_type
sum(I begin, I end)
{
    typedef typename iterator_traits<I>::value_type value_type;

    value_type sum(0);
    for (; begin != end; ++begin) sum += *begin;
    return sum;
}
