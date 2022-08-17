// 一个不合规范的分配器
template<class T>
struct alien_allocator
{
    T* alien_allocate(size_t n) {/*略。*/}
};

// 及其allocator_taits特例
template<class T>
struct allocator_traits<alien_allocator<T> >
{
    typedef alien_allocator<T> Alloc;
    typedef T* pointer;
    // 其他嵌套类型也须一一定义
    pointer allocate(Alloc &a, size_t n) {return a.alien_allocator(n);}
    // 其他成员函数略
};
