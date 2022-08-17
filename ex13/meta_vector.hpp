// 文件名：meta_vector.hpp
#pragma once
#include "meta_functions.hpp"

// 用于计算有效参数数即meta_vector::size的元函数
template<typename T0, typename T1, typename T2, typename T3, typename T4>
struct get_argument_number
{
    static const unsigned result =
        get_argument_number<T1, T2, T3, T4, void>::result + 1;
};

template<>
struct get_argument_number<void, void, void, void, void>
{
    static const unsigned result = 0;
};
// 元函数结束

// 元容器meta_vector，最多可保存5个类型
template<typename T0 = void, typename T1 = void, typename T2 = void,
         typename T3 = void, typename T4 = void>
struct meta_vector
{
    typedef T0 type0;
    typedef T1 type1;
    typedef T2 type2;
    typedef T3 type3;
    typedef T4 type4;
    static const unsigned size =
        get_argument_number<T0, T1, T2, T3, T4>::result;
};

// 用于从meta_vector中取得所存类型的元函数get
template<typename V, unsigned i>
struct get;

template<typename V>
struct get<V, 0> {typedef typename V::type0 return_type;};

template<typename V>
struct get<V, 1> {typedef typename V::type1 return_type;};

template<typename V>
struct get<V, 2> {typedef typename V::type2 return_type;};

template<typename V>
struct get<V, 3> {typedef typename V::type3 return_type;};

template<typename V>
struct get<V, 4> {typedef typename V::type4 return_type;};

// 续文件meta_vector.hpp
// 元函数find_n。实现在元容器V中从0到i-1位的类型中搜索类型T
template<typename V, typename T, unsigned i>
struct find_n
{
    typedef typename get<V, i>::return_type type_i; // 取得第i位类型type_i.

    // if (type_i == T) return T;
    // else return find_n<V, T, i-1>::return_type;
    typedef typename if_call<is_same<T, type_i>::result,
                             pipe_<T>,
                             find_n<V, T, i - 1> >::return_type return_type;
};

// find_n特例，中止递归
template<typename V, typename T>
struct find_n<V, T, 0>
{
    typedef typename get<V, 0>::return_type type_0; // 取得第0位类型type_0
    // if (type_0 == T) return T;
    // else return void;
    typedef typename if_<is_same<T, type_0>::result,
                         T, void>::return_type return_type;
};
    
// 元函数find，从元容器V中搜索类型T，如果搜到T，则返回T，否则返回void
template<typename V, typename T>
struct find
{
    static const unsigned size = V::size;
    // 调用递归元函数find_n实现搜索
    typedef typename find_n<V, T, size - 1>::return_type return_type;
};
