// 矩阵与向量乘法的入口函数
template<typename MV1, typename MV2>
typename return_type_of<MV1, MV2,
                        typename matrix_vector_traits<MV1>::tag,
                        typename matrix_vector_traits<MV2>::tag>::type
prod(MV1 const &mv1, MV2 const &mv2) {
    return prod(mv1, mv2,
                typename matrix_vector_traits<MV1>::tag(),
                typename matrix_vector_traits<MV2>::tag());
}

// 两矩阵相乘
template<typename Matrix1, typename Matrix2>
Matrix1 prod(Matrix1 const &m1, Matrix2 const &m2, matrix_tag, matrix_tag);

// 矩阵×向量
template<typename Matrix, typename Vector>
Vector prod(Matrix const &m, Vector const &v, matrix_tag, vector_tag);

// 向量×矩阵
template<typename Vector, typename Matrix>
Vector prod(Vector const &v, Matrix const &m, vector_tag, matrix_tag);
