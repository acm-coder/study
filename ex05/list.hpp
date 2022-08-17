// 文件名：list.hpp
// 双向链表容器模板

#pragma once
#include <stdexcept>
#include "list_iterator.hpp"

// 链表节点类模板
template<typename T>
struct list_node
{
    typedef T value_type;
    typedef T& reference_type;
    typedef const T& const_reference_type;

    T value;
    list_node *prev;
    list_node *next;

    list_node(T const &value, list_node *prev, list_node *next) :
        value(value), prev(prev), next(next) {}
};

// 链表类模板
template<typename T>
class list
{
    typedef list_node<T> node_type;
    node_type *head;// 头节点指针

public:
    // 类型定义
    typedef T value_type;
    typedef list_iterator<node_type> iterator;

    list() : head() {}
    ~list() {
        // 在析构时删除链表节点空间
        while (head) {
            node_type *n = head;
            head = head->next;
            delete n;
        }
    }

    // 从表头插入数据。
    void push_front(T const &v) {
        head = new node_type(v, 0, head);
        if (head->next) head->next->prev = head;
    }

    // 从表头删除数据
    void pop_front(T const &v) {
        if (head) {
            node_type *n = head;
            head = head->next;
            head->prev = 0;
            delete n;
        }
    }

    // 在指定位置之后插入元素
    void insert(iterator it, T const &v) {
        node_type *n = it.pos;
        if (n) {
            node_type *new_node = new node_type(v, n, n->next);
            new_node->next->prev = new_node;
            n->next = new_node;
        }
    }

    // 删除指定元素
    void erase(iterator &it) {
        node_type *n = it.pos;
        ++it;// 将迭代器指向下一个元素
        if (n) {
            if (n->next) n->next->prev = n->prev;
            if (n->prev) n->prev->next = n->next;
            if (head == n) head = n->next;
            delete n;
        }
    }

    bool is_empty() const {return head == 0;}

    // 返回指向链表头节点的迭代器
    iterator begin() {return iterator(head);}
    // 空迭代器代表链表尾
    iterator end() {return iterator();}

};
