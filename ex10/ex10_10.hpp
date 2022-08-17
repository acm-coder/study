#include <boost/concept_check.hpp>
#include <boost/concept/usage.hpp>

template<typename T>
struct FooCallable : boost::CopyConstructible<T>
{
    T a;
    BOOST_CONCEPT_USAGE(FooCallable) // 宏需要知道类名以生成析构函数声明
    {
        foo(a);
    }
};

// 应用新定义的FooCallable概念检查类
template<typename T>
BOOST_CONCEPT_REQUIRES(((FooCallable<T>)), (void))
test_foo_callable(T const &a)
{
    foo(a);
}
