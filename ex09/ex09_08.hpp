// 文件名：for_each_call_mem_func.hpp
#include <algorithm>
#include <functional>

template<typename Iterator,
         typename T, typename Arg, typename Result, // 用于描述成员函数
         typename V
         >
void for_each_call_mem_func(Iterator begin, Iterator end,
                            Result (T::*mem_func)(Arg),
                            V v)
{
    std::for_each(begin, end, std::bind2nd(std::mem_fun_ref(mem_func), v));
}
