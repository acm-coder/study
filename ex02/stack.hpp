//-----------------------------
//文件名：stack.hpp
#include <stdexcept>

template<typename T> class my_stack; //前置栈类模板声明

template<typename T>
class list_node
{
    T value;
    list_node *next;

    //私有构造函数，只能由其友类构造
    list_node(T const &v, list_node *n) :
        value(v), next(n) {}

    //友类必须是类模板my_stack的实例
    friend class my_stack<T>;
};

template<typename T=int>
class my_stack
{
    typedef list_node<T> node_type;
    node_type *head;

    //my_stack不可复制构造，也不可赋值
    my_stack operator=(my_stack const &) {}
    my_stack(my_stack const &s) {}

public:
    //构造与析构。
    my_stack() : head(0) {}
    ~my_stack() {while (!empty()) pop();}

    //在类模板内实现的成员函数模板
    bool empty() const {return head == 0;}
    T const& top() const throw (std::runtime_error) {
        if (empty())
            throw std::runtime_error("stack is empty.");
        return head->value;
    }
    void push(T const &v) {head = new node_type(v, head);}

    //成员函数声明，将在类模板外实现
    void pop();
};

//在类模板外实现的成员函数模板
template<typename T>
void my_stack<T>::pop()
{
    if (head) {
        node_type *tmp = head;
        head = head->next;
        delete tmp;
    }
}
