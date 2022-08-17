// 消元函数。
template<typename T>
struct elim_func
{
    T factor;
    elim_func(T const &factor) : factor(factor) {}
    T operator() (T const &arg0, T const &arg1) {
        return arg0 - arg1 * factor;
    }
};

template<typename T>
bool lu_decompose(matrix<T> &m, matrix<T> &lm)
{
    if ((m.num_row() != m.num_col()) ||
        (lm.num_row() != lm.num_col()) ||
        (m.num_row() != lm.num_row()))
        return false;

    size_t n = m.num_row();
    typedef typename matrix<T>::row_iterator row_iterator;

    // 将lm对角线赋1，上三角阵清零
    for (size_t i = 0; i < n; ++i) {
        row_iterator r = lm.row_begin(i) + i;
        *r = T(1);
        std::fill(++r, lm.row_end(i), T(0));
    }

    for (size_t i = 0; i < n - 1; ++i) {
        row_iterator ri = m.row_begin(i) + i;
        if (*ri == 0) return false;
        for (size_t j = i + 1; j < n; ++j) {
            row_iterator rj = m.row_begin(j) + i;
            T factor = *rj / *ri;
            *rj = T(0);
            std::transform(rj + 1, m.row_end(j), ri + 1, rj + 1,
                           elim_func<T>(factor));
            lm(j, i) = factor;
        }
    }

    return true;
}
