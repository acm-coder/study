// 文件名：set.hpp
// 以二叉搜索树实现的集合容器模板

#pragma once
#include <iostream>
#include "tree_iterator.hpp"

// 二叉树节点模板
template<typename T>
struct tree_node
{
    typedef T value_type;
    typedef T& reference_type;
    typedef const T& const_reference_type;

    T value;
    tree_node *parent;
    tree_node *left;
    tree_node *right;

    tree_node(T const &value,
              tree_node *parent,
              tree_node *left, tree_node *right) :
        value(value),
        parent(parent),
        left(left), right(right) {}
    ~tree_node() {
        if (left) delete left;
        if (right) delete right;
    }
};

// 集合容器模板
template<typename T>
class set
{
    typedef tree_node<T> node_type;
    node_type *root;
public:
    typedef T value_type;
    typedef tree_iterator<node_type> const_iterator;

    set() : root() {};
    ~set() {if (root) delete root;}

    // 尝试向集合中插入值，返回是否成功插入
    // 当集合中已有该值时返回false，否则返回true
    bool insert(T const &v) {
        node_type **n = &root;
        node_type *p = 0;
        while (*n) {
            if (v == (*n)->value) // 集合中已有该值，无须再插入
                return false;
            else {
                p = *n;
                n = v < (*n)->value ? &((*n)->left) : &((*n)->right);
            }
        }
        *n = new node_type(v, p, 0, 0);
        return true;
    }

    // 查询集合中是否有某值。有时返回true，无时则返回false
    bool has(T const &v) {
        node_type *n = root;
        while (n) {
            if (v == n->value)
                return true;
            n = v < n->value ? n->left : n->right;
        }
        return false;
    }

    bool is_empty() const {return root == 0;}

    const_iterator begin() const {
        // 定位到最左节点即中序遍历的第一个节点，返回一个指向该节点的迭代器
        node_type *n = root;
        while (n->left) n = n->left;
        return const_iterator(n);
    }
    const_iterator end() const {return const_iterator();}
};
