    矩阵类集合={sparse_matrix, dense_matrix, diagnal_matrix,
               upper_triangle_matrix, lower_triangle_matrix};
    向量类集合={sparse_vector, dense_vector};
    template<typename T>
    struct matrix_vector_traits {
        typedef typename if_call<T属于矩阵类集合,
                                 pipe_<matrix_tag>,
                                 if_<T属于向量类集合,
                                     vector_tag,
                                     unknown_tag>
                                 >::return_type tag;
    };
