#include <iostream>
#include "1.h"

using namespace std;

struct has_type {
    using type = int;
};

struct no_type {

};

int main() {
    static_assert(sizeof(int) == get_size<int>::size, "int size is not equal");
    static_assert(sizeof(long) == get_size<long>::size, "long size is not equal");
    static_assert(sizeof(get_size<int>) == get_size<get_size<int>>::size, "lget_size<int> size is not equal");

    static_assert(size_equal<int, sizeof(int)>::value, "int type is not equal.");

    static_assert(double_type_input_equal<int>::type<char>::type<false>::value, "");
    static_assert(double_type_input_equal<int>::type<int>::type<true>::value, "");

    static_assert(double_type_input_equal<int>::template type<char>::template type<false>::value, "");
    static_assert(double_type_input_equal<int>::template type<int>::template type<true>::value, "");

    static_assert(sub_type<has_type>::value, "expect true.");
    static_assert(!sub_type<no_type>::value, "expect false");

    types_to_szvals<int, long, char, has_type, no_type>::value.print();
    static_assert(has_one<1, 3, 4, 56>::value, "expect true.");
    // static_assert(!has_one<3, 4, 56>::value, "expect false.");
    return 0;
}

