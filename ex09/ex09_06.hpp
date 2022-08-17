// 自定义的一个返回较小值的函数
template<typename T>
T my_min(T a, T b) {return a < b ? a : b;}

template<typename Iterator0, typename Iterator1, typename T>
void denoise(Iterator0 begin0, Iterator0 end0,
             Iterator1 begin1,
             T const &threshold)
{
    using namespace std;
    typedef typename iterator_traits<Iterator0>::value_type value_type;

    transform(begin0, end0, begin1,
              bind2nd(ptr_fun(my_min<T>), threshold));
}
