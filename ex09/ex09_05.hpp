#include <functional>
#include <algorithm>

template<typename Iterator, typename T>
Iterator remove_less_than(Iterator begin, Iterator end, T const &v)
{
    using namespace std;
    typedef typename iterator_traits<Iterator>::value_type value_type;
    return remove_if(begin, end,
                     // 调用助手函数bind2nd以生成bind2nd模板实例
                     bind2nd(less<value_type>(), v));
}
