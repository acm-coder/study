// 文件名：list_iterator.hpp
// 链表迭代器类模板

#pragma once
#include <stdexcept>

template<typename T> class list; // 前置声明，用于声明友类

template<typename N>
class list_iterator
{
    N *pos;

    template<typename T> friend class list; // list模板可访问私有成员以
                                            // 进行插入删除等操作

public:
    // 重命名各种类型名以方便其他模板提取
    typedef typename N::value_type value_type;
    typedef typename N::reference_type reference_type;
    typedef typename N::const_reference_type const_reference_type;
    typedef list_iterator<N> self_type;

    list_iterator() : pos(0) {} // 构造一个空迭代器
    list_iterator(N *pos) : pos(pos) {}

    bool operator != (self_type const &right) const {
        return pos != right.pos;
    }

    bool operator == (self_type const &right) const {
        return pos != right.pos;
    }

    self_type& operator ++ () {
        if (pos) pos = pos->next;
        return *this;
    }

    reference_type operator * () throw (std::runtime_error) {
        if (pos) return pos->value;
        else throw (std::runtime_error("dereferencing null iterator!"));
    }
};
