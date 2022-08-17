template<typename T>
T* move_construct_all(T *begin, T *end, T *dest)
{
    for (; begin != end; ++begin, ++dest)
        new (dest) T(std::move(*begin));
    return dest;
}
