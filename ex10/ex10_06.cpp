#include <concepts>

concept RandomAccessIterator<typename T> : std::CopyConstructible<T>
{
    typename value_type;
    T operator + (T, unsigned n);
    T advance(T, unsigned n);
}

template<typename T>
concept_map RandomAccessIterator<T*>
{
    typedef T value_type;
    T* advance(T* i, unsigned n) {return i + n;} // 在概念映射中实现概念所需函数
}

// 一个应用概念的示例函数模板
template<typename T>
requires RandomAccessIterator<T>
void random_access_iterator_operations(T i)
{
    typedef typename T::value_type value_type;
    advance(i, 10);
}

void foo(int *i)
{
    // 将整数指针用于示例函数模板以检验概念映射的作用
    random_access_iterator_operations(i);
}
