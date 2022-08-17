// 文件名：combination_iterator.hpp

#pragma once
#include <iterator>

// 一个可嵌套的组合迭代器类模板
template<typename T,            // 本层循环的数据类型
         typename Outer>        // 外层组合迭代器类型
class combination_iterator :
    public std::iterator<std::input_iterator_tag,
                         combination_iterator<T, Outer> >
{
private:
    T value;                    // 当前值
    T begin;                    // 起始值
    T end;                      // 终止值
    Outer outer;                // 外层循环的组合迭代器
public:
    typedef std::iterator<std::input_iterator_tag, combination_iterator> base;

    combination_iterator(T const &begin, T const &end, Outer const &outer) :
        value(begin), begin(begin), end(end), outer(outer) {}

    combination_iterator&
    operator ++ () {
        ++value;
        if (value == end) {
            ++outer;
            if (!outer.is_end()) value = begin;
        }
        return *this;
    }

    bool is_end() const {return (value == end) && outer.is_end();}

    typename base::reference
    operator * () {return *this;}

    bool operator == (combination_iterator &rhs) {
        // 只有两迭代器都“处于”结束状态才相等
        return is_end() && rhs.is_end();
    }

    bool operator != (combination_iterator &rhs) {return !(*this == rhs);}

    T const& get_value() const {return value;}
    Outer const& get_outer() const {return outer;}
};

// 生成组合迭代器的助手函数
template<typename T, typename Outer>
combination_iterator<T, Outer>
combinator(T const &begin, T const &end, Outer const &outer) {
    return combination_iterator<T, Outer>(begin, end, outer);
}

// 生成一个处于“结束”的组合迭代器
template<typename T, typename Outer>
combination_iterator<T, Outer>
combinator(Outer const &outer) {
    return combination_iterator<T, Outer>(T(), T(), outer);
}

// 接例9.16
// 最外层组合迭代器模板特例
template<typename T>
class combination_iterator<T, void> : // 通过将Outer参数赋为void来标记最外层循环
    public std::iterator<std::input_iterator_tag,
                         combination_iterator<T, void> >
{
private:
    T value;
    T begin;
    T end;
    // 没有outer
public:
    typedef std::iterator<std::input_iterator_tag, combination_iterator> base;
    combination_iterator(T const &begin, T const &end) :
        value(begin), begin(begin), end(end) {}

    combination_iterator&
    operator ++ () {++value;}
    bool is_end() const {return (value == end);}

    typename base::reference
    operator * () {return *this;}

    bool operator == (combination_iterator &rhs) {
        return is_end() && rhs.is_end();
    }

    bool operator != (combination_iterator &rhs) {return !(*this == rhs);}

    T const& get_value() const {return value;}
    // 也没有get_outer()成员函数
};

// 及生成特例的助手函数
template<typename T>
combination_iterator<T, void>
combinator(T const &begin, T const &end) {
    return combination_iterator<T, void>(begin, end);
}

template<typename T>
combination_iterator<T, void>
combinator() {
    return combination_iterator<T, void>(T(), T());
}
