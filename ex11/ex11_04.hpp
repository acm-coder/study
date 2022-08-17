template<typename T>
class const_sub_matrix
{
    typedef const matrix<T> MT;
    MT &m;
    size_t sz;
    size_t row_bias;
    size_t col_bias;
public:
    const_sub_matrix(MT &m, size_t sz, size_t row_bias, size_t col_bias);
    T const& operator() (size_t r, size_t c) const;
};

// 成员函数实现略

// 助手函数
template<typename T>
const_sub_matrix<T> sub(matrix<T> const &m, size_t sz,
                        size_t row_bias, size_t col_bias)
{return const_sub_matrix<T>(m, sz, row_bias, col_bias);}
