template<typename T0, typename T1 = null_type,
         typename T2 = null_type, typename T3 = null_type>
struct my_tuple
{
    typedef type_shift_node<T0, T1, T2, T3> data_type;
    data_type data;

    my_tuple(T0 const &d0 = T0(), T1 const &d1 = T1(),
             T2 const &d2 = T2(), T3 const &d3 = T3()) :
        data(d0, d1, d2, d3) {}
};
