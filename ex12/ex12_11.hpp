// 终止移位过程的特例
template <typename T0>
struct type_shift_node<T0, null_type, null_type, null_type>
{
    typedef T0 data_type;
    T0 data;
    type_shift_node() : data() {}
    type_shift_node(T0 const &d0, null_type, null_type, null_type) :
        data(d0) {}
};
