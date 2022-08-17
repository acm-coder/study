    // 接例16.10
    // 利用tuple_size提取tuple类型尺寸
    typedef decltype(t) tuple_type;
    static_assert(tuple_size<tuple_type>::value == 3,
                  "Unexpected tuple size.");
    // 利用tuple_element提取tuple类型中对应位置元素类型
    typedef typename tuple_element<0, tuple_type>::type element_type_0;
    typedef typename tuple_element<1, tuple_type>::type element_type_1;
    typedef typename tuple_element<2, tuple_type>::type element_type_2;
    static_assert(is_same<element_type_0, int>::value,
                  "Unexpected tuple element type.");
    static_assert(is_same<element_type_1, char>::value,
                  "Unexpected tuple element type.");
    static_assert(is_same<element_type_2, string>::value,
                  "Unexpected tuple element type.");
