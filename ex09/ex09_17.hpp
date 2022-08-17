// 实现为指定两矩阵的某行与某列计算向积
template<typename T>
struct row_col_inner_prod
{
    matrix<T> const &m0;
    matrix<T> const &m1;
    row_col_inner_prod(matrix<T> const &m0, matrix<T> const &m1) :
        m0(m0), m1(m1) {}

    template<typename C_I>      // C_I是一个组合迭代器类型
    T operator() (C_I const ci) {
        T result = 0;
        std::transform(m0.row_begin(ci.get_outer().get_value()),
                       m0.row_end(ci.get_outer().get_value()),
                       m1.col_begin(ci.get_value()),
                       accumulater(result, std::plus<T>()),
                       std::multiplies<T>());
        return result;
    }
};

// 矩阵乘法
template<typename T>
matrix<T> operator * (matrix<T> const &m0, matrix<T> const &m1)
    throw (std::runtime_error)
{
    if (m0.num_col() != m1.num_row())
        throw std::runtime_error("Bad matrix size for multiplication.");

    matrix<T> m(m0.num_row(), m1.num_col());

    std::transform(combinator(size_t(0), m1.num_col(),
                              combinator(size_t(0), m0.num_row())),
                   combinator<size_t>(combinator<size_t>()),
                   m.begin(),
                   row_col_inner_prod<T>(m0, m1));
    return m;
}
