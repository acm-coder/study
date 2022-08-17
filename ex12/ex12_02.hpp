// 矩阵与向量标签
struct matrix_tag {};
struct vector_tag {};

// 提取矩阵及向量类型标准的特性类
template<typename MV>
struct matrix_vector_traits {
    typedef typename MV::tag tag;
};

////// 元函数return_type_of//////
// 求得矩阵×矩阵、矩阵×向量、向量×矩阵三种情况下的算式结果类型
// 通例：默认情况，返回左算子类型
template<typename MV1, typename MV2,
         typename tag1, typename tag2>
struct return_type_of {
    typedef MV1 type;
};

// 特例：只有矩阵×向量时，返回右算子即向量的类型
template<typename MV1, typename MV2>
struct return_type_of<MV1, MV2, matrix_tag, vector_tag> {
    typedef MV2 type;
};
////// 元函数return_type_of结束//////
