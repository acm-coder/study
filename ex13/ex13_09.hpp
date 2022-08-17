// 各种矩阵类型
class sparse_matrix {};
class dense_matrix {};
class diagnal_matrix {};
class upper_triangle_matrix {};
class lower_triangle_matrix {};
// 各种向量类型
class sparse_vector {};
class dense_vector {};

// 标签类型
struct matrix_tag {};
struct vector_tag {};
struct unknown_tag {};

// 为矩阵类定义元容器
typedef meta_vector<sparse_matrix, dense_matrix, diagnal_matrix,
                    upper_triangle_matrix, lower_triangle_matrix>
matrix_types;
// 为向量类定义元容器
typedef meta_vector<sparse_vector, dense_vector>
vector_types;

// 矩阵与向量的特性类
template<typename T>
struct matrix_vector_traits
{
    // 分别在矩阵容器与向量容器中查找类型所得的结果
    typedef typename find<matrix_types, T>::return_type found_matrix_type;
    typedef typename find<vector_types, T>::return_type found_vector_type;
    // 根据查找结果确定返回类型
    typedef typename if_call<is_same<found_matrix_type, T>::result,
                             pipe_<matrix_tag>,
                             if_<is_same<found_vector_type, T>::result,
                                 vector_tag, unknown_tag> >::return_type
    tag;
};
