// 文件名：list.hpp
#pragma once
#include <iterator>

template<typename T>
struct list_node
{
    typedef T value_type;
    T value;
    list_node *next;
    list_node *prev;
    list_node(T const &value, list_node *next = 0, list_node *prev = 0) :
        value(value), next(next), prev(prev) {}
};

template<typename T> class list; // 前置声明

template<typename T>
class list_iterator :
    public std::iterator<std::bidirectional_iterator_tag, T>
{
    list_node<T> *pos;
    typedef std::iterator<std::bidirectional_iterator_tag, T> base_type;
public:
    list_iterator(list_node<T> *pos) : pos(pos) {}
    list_iterator() : pos() {}

    list_iterator& operator++() {pos = pos->next;}
    list_iterator& operator--() {pos = pos->prev;}
    bool operator==(list_iterator const &right) {return pos == right.pos;}
    bool operator!=(list_iterator const &right) {return pos != right.pos;}
    
    typename base_type::reference
    operator *() {return pos->value;}

    friend class list<T>;
};

template<typename T>
class list
{
private:
    typedef list_node<T> node_type;
    node_type *head;
    node_type *tail;
    size_t sz;

    // 二
    list& push_back_only(T const &v) {
        node_type *p = new node_type(v, 0, tail);
        if (tail) {
            tail->next = p;
            tail = p;
        }
        else {
            tail = p;
            head = p;
        }
        return *this;
    }

    // 一
    void& pop_back_only() {
        if (tail) {
            node_type *p = tail;
            tail = tail->prev;
            delete p;
        }
    }

    // 一
    void erase(node_type *pos) {
        if (pos == head) {
            head = head->next;
            if (head) head->prev = 0;
            else tail = 0;
        }
        else if (pos == tail) {
            tail = tail->prev;
            tail->next = 0;
        }
        else {
            pos->prev->next = pos->next;
            pos->next->prev = pos->prev;
        }
        delete pos;
        --sz;
    }



public:
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef list_iterator<T> iterator;

    list() : head(0), tail(0), sz(0) {}
    ~list() {while (tail) pop_back_only();}

    // 一
    size_t size() {return sz;}

    // 三
    iterator begin() {return iterator(head);}
    iterator end() {return iterator();}

    // 三
    list& push_back(T const &v) {
        push_back_only(v);
        ++sz;
        return *this;
    }

    // 二
    list& pop_back() {
        pop_back_only();
        --sz;
        return *this;
    }

    // 二
    list& reverse() {
        node_type *p = head;
        while (p) {
            std::swap(p->prev, p->next);
            p = p->prev;
        }
        std::swap(head, tail);
        return *this;
    }

    // 一
    void swap(list &r) {
        std::swap(head, r.head);
        std::swap(tail, r.tail);
        std::swap(sz, r.sz);
    }

    // 三
    void assign(list &r) {
        iterator i = begin();
        iterator r_i = r.begin();

        if (sz <= r.sz) {
            for (; i != end(); ++i, ++r_i) *i = *r_i;
            while (r_i != r.end()) push_back_only(*r_i);
            sz = r.sz;
        }
        else {                  // size() > r.size()
            for (; r_i != r.end(); ++i, ++r_i) *i = *r_i;
            while (sz != r.sz) erase(tail);
        }
    }

    // 三
    void erase(iterator i) {erase(i.pos);}
};
