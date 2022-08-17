// 文件名：tree_iterator.hpp
// 二叉树迭代器模板，中序遍历

#pragma once

template<typename N>
class tree_iterator
{
    const N *pos;// 当前位置
public:
    typedef typename N::value_type value_type;
    typedef typename N::const_reference_type const_reference_type;
    typedef tree_iterator<N> self_type;

    tree_iterator() : pos(0) {}
    tree_iterator(const N *pos) : pos(pos) {}

    bool operator == (self_type const &right) const {
        return pos == right.pos;
    }

    self_type& operator ++ () {
        if (pos) {
            // 首先确保不是空迭代器
            // 再查看有没有右子树
            if (pos->right) {
                // 定位到右子树的最左叶节点
                pos = pos->right;
                while (pos->left) pos = pos->left;
            }
            else {
                // 定位到尚未访问过的祖先节点
                while ((pos->parent) &&
                       (pos->parent->right == pos))
                    pos = pos->parent;
                pos = pos->parent;
            }
        }
        return *this;
    }


    const_reference_type operator * () const
        throw (std::runtime_error) {
        if (pos) return pos->value;
        else throw std::runtime_error("dereferencing null iterator!");
    }
};

template<typename N>
bool operator != (tree_iterator<N> const &left,
                  tree_iterator<N> const &right)
{
    return !(left == right);
}
