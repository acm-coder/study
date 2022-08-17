#include "stack.hpp"

template<typename T=int>
class count_stack : public my_stack<T>
{
    typedef my_stack<T> base_type; //非常有用的typedef
    unsigned size;
public:
    count_stack() : base_type(), size(0) {}

    void push(T const &v) {
        base_type::push(v);
        size++;
    }

    void pop() {
        if (size > 0) {
            base_type::pop();
            size--;
        }
    }

    unsigned getSize() const {return size;}
};
