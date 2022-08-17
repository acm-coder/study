template<typename I, typename V>
I remove_if_greater_than(I first, I second, V const &value)
{
    typedef typename std::iterator_traits<I>::value_type value_type;
    return std::remove_if(first, second,
                          [value](value_type const &v) {return v > value;});
}
