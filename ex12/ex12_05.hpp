// 矩阵×向量
template<typename T0, typename T1>
typename vector_concept<T0>::type
operator * (matrix_concept<T0> const &mc, vector_concept<T1> const &vc)
{
    typedef typename matrix_concept<T0>::type matrix_type;
    typedef typename vector_concept<T1>::type vector_type;

    // 将函数参数下转义
    matrix_type const &m(*reinterpret_cast<const matrix_type*>(&mc));
    vector_type const &v(*reinterpret_cast<const vector_type*>(&vc));
    // 具体实现略
}

// 向量×矩阵
template<typename T0, typename T1>
typename vector_concept<T1>::type
operator * (vector_concept<T0> const &vc, matrix_concept<T1> const &mc)
{
    typedef typename vector_concept<T0>::type vector_type;
    typedef typename matrix_concept<T1>::type matrix_type;

    // 将函数参数下转义
    vector_type const &v(*reinterpret_cast<const vector_type*>(&vc));
    matrix_type const &m(*reinterpret_cast<const matrix_type*>(&mc));

    // 具体实现略
}
