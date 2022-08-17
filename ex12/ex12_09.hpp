template<typename T, typename NT>
struct hetero_node {
    T data;
    NT next;
};

templat<typename T0, typename T1, typename T2, typename T3>
struct my_tuple_4 {
    hetero_node<T0, hetero_node<T1, hetero_node<T2, T3> > > data;
};
