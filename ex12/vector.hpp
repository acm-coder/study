// 文件名：vector.hpp
#pragma once
#include "vector_policies.hpp"
#include <cstddef>

template <typename T,
          // data_policy是模板类模板函数
          template <typename> class data_policy = instance_data_policy>
class vector
{
    typedef data_policy<T> policy_type; // 由data_policy得到所需的策略类型
    typedef typename policy_type::holder_type holder_type;
public:
    typedef size_t size_type;
    typedef T value_type;
    typedef value_type& reference;
    typedef value_type const& const_reference;

private:
    holder_type *data_ptr;      // 数组指针
    size_type sz;               // 容器尺寸
    size_type buffer_sz;        // 所申请的空间尺寸

public:
    // 在vector中我们用malloc/free申请及释放内存，用policy_type中的
    // 静态成员函数构造及析构数据
    // 在vector的构造函数中先预先申请存放一个数据的空间
    vector() :
        data_ptr((holder_type*)malloc(sizeof(holder_type))),
        sz(0), buffer_sz(1)
    {}

    template<typename I>
    vector(I begin, I end) :
        data_ptr((holder_type*)malloc(sizeof(holder_type))),
        sz(0), buffer_sz(1) {
        for (; begin != end; ++begin) push_back(*begin);
    }

    ~vector() {
        // 首先析构所有数据
        for (size_t i = 0; i < sz; ++i)
            policy_type::destruct_data(data_ptr[i]);
        free(data_ptr);         // 再释放内存
    }


    size_type size() const {return sz;}

    void push_back(value_type const &v) {
        if (sz == buffer_sz) {
            // 预留空间已用尽，须新申请更大空间
            buffer_sz *=  2;
            holder_type *new_data_ptr =
                (holder_type*)malloc(sizeof(holder_type) * buffer_sz);

            // 将旧空间内的holder_type数据利用placement new复制构造到新
            // 空间对应位置
            for (size_type i = 0; i < sz; ++i) {
                new (new_data_ptr + i) holder_type(data_ptr[i]);
                data_ptr[i].~holder_type(); // 同时析构旧空间中的
                                            // holder_type数据
            }
            free(data_ptr);
            data_ptr = new_data_ptr;
        }
        // 利用策略类的成员函数构造新数据
        policy_type::construct_data(data_ptr[sz++], v);
    }
    void pop_back() {
        // 利用策略类的成员函数析构数据
        policy_type::destruct_data(data_ptr[sz--]);
    }

    // 利用策略类成员函数取得所需数据引用。
    reference operator[](size_type pos) {
        return policy_type::get_value(data_ptr[pos]);
    }
    const_reference operator[](size_type pos) const {
        return policy_type::get_const_value(data_ptr[pos]);
    }
};
