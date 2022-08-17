#include "matrix.hpp"
#include "accumulate_iterator.hpp"
#include <algorithm>
#include <stdexcept>

template<typename T>
matrix<T> operator * (matrix<T> const &m0, matrix<T> const &m1)
    throw (std::runtime_error)
{
    // 矩阵尺寸不符合时，无法相乘。抛出一个运行期异常
    if (m0.num_col() != m1.num_row())
        throw std::runtime_error("Bad matrix size for multiplication.");

    matrix<T> m(m0.num_row(), m1.num_col());

    typename matrix<T>::iterator pos = m.begin();
    
    for (size_t i = 0; i < m.num_row(); ++i) {
        for (size_t j = 0; j < m.num_col(); ++j) {
            *pos = 0;
            std::transform(m0.row_begin(i), m0.row_end(i),
                           m1.col_begin(j),
                           accumulater(*pos, std::plus<T>()),
                           std::multiplies<T>());
            ++pos;
        }
    }

    return m;
}
