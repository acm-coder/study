// 文件名：meta.cpp
#include "meta_functions.hpp"   // if_, if_call以及is_same
#include "meta_vector.hpp"
#include "meta_filter.hpp"
#include <cassert>

// 各种矩阵类型及模板声明
class sparse_matrix;
class dense_matrix;
template<typename T0, typename T1> class diagnal_matrix;
template<typename T> class upper_triangle_matrix;
template<typename T> class lower_triangle_matrix;
// 各种向量类型及模板声明
class sparse_vector;
template<typename T> class dense_vector;

// 标签类型
struct matrix_tag {};
struct vector_tag {};
struct unknown_tag {};

// 为矩阵类定义元容器
typedef meta_vector<sparse_matrix, dense_matrix,
                    // 以下为模板的代表类型
                    diagnal_matrix<int, int>,
                    upper_triangle_matrix<int>,
                    lower_triangle_matrix<int> >
matrix_types;

// 为向量类定义元容器
typedef meta_vector<sparse_vector,
                    dense_vector<int> > // dense_vector模板的代表类型。
vector_types;

// 取得标签的特性类
template<typename T>
struct matrix_vector_traits
{
    // 首先用meta_filter元函数自动识别及转换模板实例类型为其代表类型
    typedef typename meta_filter<T>::return_type filtered_T;

    // 分别在矩阵容器与向量容器中查找类型所得的结果
    typedef typename find<matrix_types, filtered_T>::return_type
    found_matrix_type;
    typedef typename find<vector_types, filtered_T>::return_type
    found_vector_type;
    // 根据查找结果确定返回类型
    typedef typename if_call<is_same<found_matrix_type, filtered_T>::result,
                             pipe_<matrix_tag>,
                             if_<is_same<found_vector_type, filtered_T>::result,
                                 vector_tag, unknown_tag> >::return_type
    tag;
};

int main()
{
    // 测试matrix_vector_traits的返回类型是否正确
    assert((is_same<matrix_vector_traits<sparse_matrix>::tag,
                    matrix_tag>::result));

    assert((is_same<matrix_vector_traits<dense_matrix>::tag,
                    matrix_tag>::result));

    assert((is_same<matrix_vector_traits<diagnal_matrix<double, double> >::tag,
                    matrix_tag>::result));

    assert((is_same<matrix_vector_traits<lower_triangle_matrix<char> >::tag,
                    matrix_tag>::result));

    assert((is_same<matrix_vector_traits<upper_triangle_matrix<char> >::tag,
                    matrix_tag>::result));

    assert((is_same<matrix_vector_traits<dense_vector<short> >::tag,
                    vector_tag>::result));

    assert((is_same<matrix_vector_traits<sparse_vector>::tag,
                    vector_tag>::result));

    assert((is_same<matrix_vector_traits<int>::tag,
                    unknown_tag>::result));
    
    return 0;
}
