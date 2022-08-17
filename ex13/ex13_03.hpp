////// 元函数if_call //////
// 当cond为true时调用元函数MF_True求得返回值，否则调用元函数MF_False求得返回值
template<bool cond, typename MF_True, typename MF_False>
struct if_call
{
    typedef typename MF_True::return_type return_type;
};
// 特例对应cond==false时
template<typename MF_True, typename MF_False>
struct if_call<false, MF_True, MF_False>
{
    typedef typename MF_False::return_type return_type;
};
////// 元函数if_call结束 //////

////// 元函数pipe_ //////
// 其返回值即为其模板参数
template<typename T>
struct pipe_
{
    typedef T return_type;
};
////// 元函数pipe_ 结束 //////
