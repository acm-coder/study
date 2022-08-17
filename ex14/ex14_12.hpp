#include <type_traits>

template<typename T0, typename T1>
struct get_compatible_type
{
    // 假定T0与T1的基本类型相同，且T0与T1必然为左值或右值引用类型。二者
    // 都有可能带只读约束

    // 首先得到T0与T1去除引用后的类型nr_type0与nr_type1
    typedef typename std::remove_reference<T0>::type nr_type0;
    typedef typename std::remove_reference<T1>::type nr_type1;
    // 再借用nr_type0得到去除（可能的）只读修饰后的基本类型
    //根据假定，这一基本类型应于nr_type1的基本类型相同，但在本元函数中不做检查
    typedef typename std::remove_const<nr_type0>::type base_type;
    typedef typename std::add_const<base_type>::type const_base_type;

    // std::is_const只能判断非引用类型是否有只读修饰，所以我们必须准备
    // nr_type0与nr_type1

    // 只要一方为只读类型，则选择const_base_type否则选择base_type 
    // 用于生成返回类型
    typedef typename if_<std::is_const<nr_type0>::value ||
                         std::is_const<nr_type1>::value,
                         const_base_type,
                         base_type
                         >::return_type mid_type;

    // 为三种情况：同为左值、同为右值以及一左一右值准备返回值类型
    typedef typename std::add_lvalue_reference<mid_type>::type
    lvr_type;                   // 左值引用类型，可能为只读

    typedef typename std::add_rvalue_reference<mid_type>::type
    rvr_type;                   // 右值引用类型，可能为只读

    typedef typename std::add_lvalue_reference<const_base_type>::type
    clvr_type;                  // 确定的只读左值引用类型

    // 如果同为左值，则返回lvr_type，如果同为右值，则返回rvr_type
    //如果一左一右，则返回clvr_type
    typedef typename if_call<std::is_lvalue_reference<T0>::value &&
                             std::is_lvalue_reference<T1>::value,
                             pipe_<lvr_type>,
                             if_<std::is_rvalue_reference<T0>::value &&
                                 std::is_rvalue_reference<T1>::value,
                                 rvr_type,
                                 clvr_type
                                 >
                             >::return_type type;
};
