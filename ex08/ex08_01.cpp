#include <iostream>
#include <stack>

template<typename Stack>
class stack_iterator
{
public:
    typedef typename Stack::value_type value_type;
    typedef typename Stack::reference reference;

private:
    Stack &s;
    value_type *pos;
public:
    stack_iterator(Stack &_s) : s(_s), pos(_s.size() ? &_s.top() : 0) {}
    reference operator * () const {return *pos;}
    stack_iterator& operator ++ () {
        s.pop();
        pos = s.size() ? &s.top() : 0;
        return *this;
    }
    bool operator == (stack_iterator const &rh) const {return pos == rh.pos;}
    bool operator != (stack_iterator const &rh) const {return pos != rh.pos;}
};

int main()
{
    using namespace std;
    int numbers[] = {0, 1, 2, 3, 4};
    typedef stack<int> int_stack;
    int_stack s;
    for (int i = 0; i < 5; ++i) s.push(numbers[i]);

    stack_iterator<int_stack> a(s);
    stack_iterator<int_stack> b(s);

    cout << ((a == b) ? "a == b" : "a != b") << endl;
    ++a; ++b;
    cout << ((a == b) ? "++a == ++b" : "++a != ++b") << endl;

    // cout << *a << endl;   // 危险操作，a所指数据已经出栈，空间已经被释放
}
