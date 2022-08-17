// 文件名：list_common_base.hpp
#pragma once
#include <iterator>

struct list_node_base
{
    list_node_base* next;
    list_node_base* prev;
    list_node_base(list_node_base *next = 0, list_node_base *prev = 0) :
        next(next), prev(prev) {}
};

template<typename T>
struct list_node : list_node_base
{
    typedef T value_type;
    T value;
    list_node(T const &value,
              list_node_base *next = 0, list_node_base *prev = 0) :
        list_node_base(next, prev), value(value) {}
};

template<typename T> class list; // 前置声明

template<typename T>
class list_iterator :
    public std::iterator<std::bidirectional_iterator_tag, T>
{
    list_node_base *pos;
    typedef std::iterator<std::bidirectional_iterator_tag, T> base_type;
public:
    list_iterator(list_node<T> *pos) : pos(pos) {}
    list_iterator() : pos() {}

    list_iterator& operator++() {pos = pos->next;}
    list_iterator& operator--() {pos = pos->prev;}
    bool operator==(list_iterator const &right) {return pos == right.pos;}
    bool operator!=(list_iterator const &right) {return pos != right.pos;}
    
    typename base_type::reference
    operator *() {return static_cast<list_node<T>*>(pos)->value;}

    friend class list<T>;
};

class list_base
{
protected:
    list_node_base *head;
    list_node_base *tail;
    size_t sz;

    void push_back_only(list_node_base *pos) {
        if (tail) {
            tail->next = pos;
            pos->prev = tail;
            tail = pos;
        }
        else {
            tail = pos;
            head = pos;
            pos->prev = 0;
            pos->next = 0;
        }
    }

    void pop_back_only() {
        if (tail) {
            list_node_base *p = tail;
            tail = tail->prev;
            delete p;
        }
    }

    void swap(list_base &r) {
        std::swap(head, r.head);
        std::swap(tail, r.tail);
        std::swap(sz, r.sz);
    }

public:
    typedef size_t size_type;

    list_base() :head(0), tail(0), sz(0) {}
    ~list_base() {while (tail) pop_back_only();}

    size_t size() {return sz;}

    void reverse() {
        list_node_base *p = head;
        while (p) {
            std::swap(p->prev, p->next);
            p = p->prev;
        }
        std::swap(head, tail);
    }

    void push_back(list_node_base *pos) {
        push_back_only(pos);
        ++sz;
    }

    void pop_back() {
        pop_back_only();
        --sz;
    }

    void erase(list_node_base *pos) {
        if (pos == head) {
            head = head->next;
            if (head) {head->prev = 0;}
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
};

template<typename T>
class list : public list_base
{
private:
    typedef list_node<T> node_type;
    typedef list_base base_type;

    void push_back_only(T const &v) {
        base_type::push_back_only(new node_type(v, 0, 0));
    }
public:
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef list_iterator<T> iterator;

    list() : list_base() {}
    ~list() {}

    iterator begin() {
        return iterator(reinterpret_cast<node_type*>(head));
    }
    iterator end() {return iterator();}

    list& push_back(T const &v) {
        node_type *n = new node_type(v, 0, 0);
        base_type::push_back(n);
        return *this;
    }

    list& pop_back() {
        base_type::pop_back();
        return *this;
    }

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
            while (sz != r.sz) base_type::erase(tail);
        }
    }

    void erase(iterator i) {
        base_type::erase(i.pos);
    }
};
