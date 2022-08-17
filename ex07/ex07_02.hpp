template<class Value, class Alloc = std::allocator<Value> >
class list
{
public:
    explicit list(const Alloc& = Alloc());
    explicit list(size_type n);
    list(size_type n, const Value&, const Alloc& = Alloc());
    template<typename InputIterator>
    list(InputIterator first, InputIterator last, const Alloc& = Alloc());
    list(const list<Value, Alloc>&);
    // C++11中新的构造函数未列出
};
