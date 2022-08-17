#include <functional>
#include <algorithm>

template<typename Iterator0, typename Iterator1>
bool all_are_multiples(Iterator0 begin0, Iterator0 end0, Iterator1 begin1)
{
    using namespace std;
    // 首先利用iterator_traits得到迭代器所指数据类型
    typedef iterator_traits<Iterator0> traits;
    typedef typename traits::value_type value_type;
    
    vector<bool> result;   // 用于保存transform的结果，即判断对应
                           // 元素对是否满足整除关系
    transform(begin0, end0, begin1,
              back_inserter(result), // 运算结果push_back进result
              not2(modulus<value_type>()) // !(a % b)
              );
    return find(result.begin(), result.end(), false) == result.end();
}
