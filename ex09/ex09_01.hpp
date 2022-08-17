template<typename RandomAccessIterator, typename Value>
RandomAccessIterator
find(RandomAccessIterator first, RandomAccessIterator last, Value const &v)
{
    typename std::iterator_traits<RandomAccessIterator>::difference_type
        steps = (last - first) >> 2;
    // 每个step做四次比较
    for (; steps > 0; --steps) {
        if (*first == v) return first;
        ++first;
        if (*first == v) return first;
        ++first;
        if (*first == v) return first;
        ++first;
        if (*first == v) return first;
        ++first;
    }
    // 剩余数据的比较
    switch (last - first) {
    case 3:
        if (*first == v) return first;
        ++first;
    case 2:
        if (*first == v) return first;
        ++first;
    case 1:
        if (*first == v) return first;
        ++first;
    default:
        return last;
    }
}
