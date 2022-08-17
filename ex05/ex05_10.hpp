template<typename I>
typename I::value_type
sum(I begin, I end)
{
    typedef typename I::value_type value_type;

    value_type sum(0);
    for (; begin != end; ++begin) sum += *begin;
    return sum;
}
