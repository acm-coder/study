#include <type_traits>
#include <iostream>
/*
 * 对于元函数来说，数值与类型其实并没有明显的差异：元函数的输入可以是数值或类型，
 * 对应的变换可以在数值合类型之间进行，比如可以构造一个元函数，输入是一个类型，
 * 输出是一个该类型变量所占空间的大小--这就是典型的从类型变换为数值的元函数。
 * 试构造该函数，并测试之。
 */

#pragma once

template<typename T>
struct get_size {
    static constexpr unsigned long size = sizeof(T);
};

/*
 * 作为进一步的扩展，元函数的输入参数甚至可以是类型与数值混合的。
 * 尝试构造一个元函数，其输入参数为一个类型以及一个整数。
 * 如果该类型所对应对象的大小等于该整数，那么返回true，否则返回false。
 */

template<typename T, int sz>
struct size_equal {
    static constexpr bool value = sizeof(T) == sz ? true : false;
};


/*
 * 本章介绍了若干元函数的表示形式，你是否还能想到其他的形式
 */


/*
 * 本章讨论了以类模板作为元函数的输出，尝试构造一个元函数，
 * 它接受输入后会返回一个元函数，后者接收输入后会再返回一个元函数--这仅仅是一个练习，
 * 不必过于在意其应用场景。
 */

template<typename T>
struct double_type_input_equal {
    template<typename first, typename second>
    struct double_type_equal {
    private:
        template<typename ft, typename st, bool expect>
        struct equal_impl {
            constexpr static bool value = std::is_same<ft, st>::value == expect;
        };

    public:
        template<bool expect>
        using type = equal_impl<first, second, expect>;
    };

    template<typename type>
    using type = double_type_equal<T, type>;
};

/*
 * 使用SFINAE构造一个元函数：输入一个类型T，当T存在子类型type时该元函数返回true，否则返回false。
 */

template<typename T>
struct sub_type {
private:
    template<typename type>
    static char test(typename type::type*);

    template<typename type>
    static int test(...);
public:
    static constexpr bool value = sizeof(test<T>(0)) == 1 ? true : false;
};

/*
 * 使用在本章中学到的循环代码书写方式，编写一个元函数，输入一个类型数组，输出一个无符号整型数组，
 * 输出数组中的每个元素表示了输入数组中相应类型变量的大小。
 */

template<typename ... types>
struct types_to_szvals {
    template<int ... vals>
    struct iseq {
        static void print() {
            static constexpr int svals[] = {vals...};
            for (int i = 0; i < sizeof svals / sizeof (int); ++ i)
                std::cout << svals[i] << ' ';
            std::cout << std::endl;
        }
    };

    static constexpr iseq<sizeof(types)...> value{};
};

/*
 * 使用分支短路逻辑实现一个元函数，给定一个整数序列，
 * 判断其中是否存在值为1的元素，如果存在，就返回true，否则返回false。
 */


template<int ... vals>
struct has_one;

template<>
struct has_one<> {
    static constexpr bool value = false;
};

template<int t, int ... vals>
struct has_one<t, vals...> {
    static constexpr bool value = t == 1 || has_one<vals...>::value;
};



