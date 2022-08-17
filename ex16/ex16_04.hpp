template<typename I>
auto sum(I first, I second)
    -> decltype(*first + *second)
{
    typedef decltype(*first + *second) sum_type;

    sum_type ret = 0;

    std::for_each(first, second,
                  [&ret](sum_type const &v) {ret += v;});
    //             捕获对ret的引用。           ^^操作会修改ret值
    return ret;
}
