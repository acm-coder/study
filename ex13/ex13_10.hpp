// 用于meta_filter的TMPL参数默认值
template<typename T> struct dummy_template {};

// 元函数meta_filter
template<typename T, template<typename> class TMPL = dummy_template>
struct meta_filter
{
    // 通例返回类型即其参数类型
    typedef T return_type;
};

template<template<typename> class TMPL, typename T>
struct meta_filter<TMPL<T>, dummy_template>
{
    // 特例返回所匹配模板实例类型的代表类型
    typedef TMPL<int> return_type;
};
