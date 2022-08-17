////// 判断两类型是否相等的元函数is_same //////
template<typename T0, typename T1>
struct is_same
{
    enum {result = 0};
};

// 当两类型相同时，将匹配以下特例
template<typename T>
struct is_same<T, T>
{
    enum {result = 1};
};
////// 元函数is_same结束 //////

////// 条件返回类型的元函数if_ //////
// 当cond为true时返回Type_True，否则返回Type_False
// 通例对应cond==true时
template<bool cond, typename Type_True, typename Type_False>
struct if_
{
    typedef Type_True return_type;
};

// 特例对应cond==false时
template<typename Type_True, typename Type_False>
struct if_<false, Type_True, Type_False>
{
    typedef Type_False return_type;
};
////// 元函数if_结束 //////
