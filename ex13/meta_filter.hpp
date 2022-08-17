// 文件名：meta_filter.hpp
#pragma once

// 用于meta_filter的TMPL参数默认值
template<typename T> struct dummy_template_1 {};
template<typename T0, typename T1> struct dummy_template_2 {};

// 元函数meta_filter
template<typename T0, typename T1 = void,
         template<typename> class TMPL1 = dummy_template_1,
         template<typename, typename> class TMPL2 = dummy_template_2>
struct meta_filter
{
    // 通例返回类型即其参数类型
    typedef T0 return_type;
};

// 匹配单类型参数模板实例的特例
template<template<typename> class TMPL, typename T>
struct meta_filter<TMPL<T>, void, dummy_template_1, dummy_template_2>
{
    // 特例返回所匹配模板实例类型的代表类型
    typedef TMPL<int> return_type;
};

// 匹配双类型参数模板实例的特例
template<template<typename, typename> class TMPL, typename T0, typename T1>
struct meta_filter<TMPL<T0, T1>, void, dummy_template_1, dummy_template_2>
{
    // 特例返回所匹配模板实例类型的代表类型。
    typedef TMPL<int, int> return_type;
};
