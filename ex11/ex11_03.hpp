#pragma once
#include <algorithm>

template<typename T>
class sub_matrix
{
    typedef matrix<T> MT;
    MT &m;
    size_t sz;
    size_t row_bias;
    size_t col_bias;
public:
    sub_matrix(MT &m, size_t sz, size_t row_bias, size_t col_bias);
    T& operator () (size_t r, size_t c);
    T const& operator() (size_t r, size_t c) const;
    void transpose() {
        // 最通用的行列交换算法，交换沿对角线对称的元素值
        for (size_t i = 0; i < sz; ++i)
            for (size_t j = 0; j < i; ++j)
                std::swap((*this)(i, j), (*this)(j, i));
    }
};

// 成员函数实现略

// 生成sub_matrix的助手函数
template<typename T>
sub_matrix<T> sub(matrix<T> &m, size_t sz, size_t row_bias, size_t col_bias)
{return sub_matrix<T>(m, sz, row_bias, col_bias);}
