// 文件名：vector_policies.hpp
#pragma once

#include <cstdlib>

// 实例存储策略
template <typename T>
struct instance_data_policy
{
    typedef T holder_type;
    typedef T value_type;

    // 在h上构造复制构造数据v的实例
    static
    void construct_data(holder_type &h, value_type const &v) {
        new (&h) holder_type(v); // placement new语法，在已申请的空间地址上构造
    }

    // 从h上销毁数据
    static
    void destruct_data(holder_type const &h) {
        h.~holder_type();       // 只调用析构函数，不释放内存
    }

    // 两个取得数据引用的函数，分别返回只读及可写两种引用
    static
    value_type& get_value(holder_type &h) {return h;}

    static
    value_type const& get_const_value(holder_type const &h) {return h;}
};

// 指针存储策略
template <typename T>
struct pointer_data_policy
{
    typedef T* holder_type;
    typedef T value_type;

    static
    void construct_data(holder_type &h, T const &v) {
        h = new T(v);           // 新申请空间复制构造v
    }

    static
    void destruct_data(holder_type h) {
        delete h;               // 析构及释放h所指空间
    }

    // 两个取得数据引用的函数，通过指针找到对应数据引用
    static
    value_type& get_value(holder_type &h) {return *h;}

    static
    value_type const& get_const_value(holder_type const &h) {return *h;}
};
