#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/plus.hpp>
#include <iostream>
#include <tuple>
#include <limits>
#include <boost/mpl/int_fwd.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/transform.hpp>

namespace mpl = boost::mpl;

#include <boost/mpl/placeholders.hpp>
using namespace mpl::placeholders;

namespace units
{

typedef mpl::vector_c<int,0,0,0,0,0,0,0> scalar;

typedef mpl::vector_c<int,1,0,0,0,0,0,0> mass;          // kilogram
typedef mpl::vector_c<int,0,1,0,0,0,0,0> length;        // meters
typedef mpl::vector_c<int,0,0,1,0,0,0,0> time;          // seconds
typedef mpl::vector_c<int,0,0,0,1,0,0,0> charge;        // ampere
typedef mpl::vector_c<int,0,0,0,0,1,0,0> temperature;   // kelvin
typedef mpl::vector_c<int,0,0,0,0,0,1,0> intensity;     // candela
typedef mpl::vector_c<int,0,0,0,0,0,0,1> substance;     // mole

// base dimension:        m l  t ...
typedef mpl::vector_c<int,0,1,-1,0,0,0,0> velocity;
typedef mpl::vector_c<int,0,1,-2,0,0,0,0> acceleration;
typedef mpl::vector_c<int,1,1,-1,0,0,0,0> momentum;
typedef mpl::vector_c<int,1,1,-2,0,0,0,0> force;

// An integral wrapper type, parametrized on the dimension unit
template <class T, class Dimension>
struct quantity
{
    explicit quantity(T x) : m_value(x)
    {}

    template <class OtherDimension>
    quantity(quantity<T, OtherDimension> const& rhs) : m_value(rhs.value())
    {
        static_assert(mpl::equal<Dimension, OtherDimension>::type::value, "trying to assign a value of different dimension");
    }

    T value() const
    {
        return m_value;
    }

private:
    T m_value;
};

// template <class T, class D>
// auto operator+(const quantity<T, D>& x, const quantity<T, D>& y)
// {
//     return quantity<T, D>{x.value() + y.value()};
// }

// template <class T, class D>
// auto operator-(const quantity<T, D>& x, const quantity<T, D>& y)
// {
//     return quantity<T, D>{x.value() - y.value()};
// }

template <class T, class D>
quantity<T, D> operator+(const quantity<T, D>& x, const quantity<T, D>& y)
{
    return quantity<T, D>{x.value() + y.value()};
}

template <class T, class D>
quantity<T, D> operator-(const quantity<T, D>& x, const quantity<T, D>& y)
{
    return quantity<T, D>{x.value() - y.value()};
}


// Transformations using a metafunction class
struct plus_f
{
    template <class A, class B>
    struct apply 
        : mpl::plus<A, B> {};
};

// template <class T, class D1, class D2>
// auto operator*(const quantity<T, D1>& x, const quantity<T, D2>& y)
// {
//     typedef typename mpl::transform<D1, D2, plus_f>::type dim;
//     return quantity<T, dim>{x.value() * y.value()};
// }

template <class T, class D1, class D2>
quantity<T, typename mpl::transform<D1, D2, plus_f>::type> operator*(const quantity<T, D1>& x, const quantity<T, D2>& y)
{
    typedef typename mpl::transform<D1, D2, plus_f>::type dim;
    return quantity<T, dim>{x.value() * y.value()};
}

// Transform using placeholder expression
template <class D1, class D2>
struct DivideDimensions
    : mpl::transform<D1, D2, mpl::minus<_1, _2>> {};

// template <class T, class D1, class D2>
// auto operator/(const quantity<T, D1>& x, const quantity<T, D2>& y)
// {
//     typedef typename DivideDimensions<D1, D2>::type dim;
//     return quantity<T, dim>{x.value() / y.value()};
// }

template <class T, class D1, class D2>
quantity<T, typename DivideDimensions<D1, D2>::type> operator/(const quantity<T, D1>& x, const quantity<T, D2>& y)
{
    typedef typename DivideDimensions<D1, D2>::type dim;
    return quantity<T, dim>{x.value() / y.value()};
}

} // namespace units

void test() {
    units::quantity<float, units::mass> m{2.0f};
    units::quantity<float, units::acceleration> a{10.0f};

    std::cout << "mass:         " << m.value() << " kilograms\n";
    std::cout << "acceleration: " << a.value() << " m/s^2\n";

    units::quantity<float, units::force> f = m * a;
    units::quantity<float, units::mass> m2 = f / a;

    float roundingError = std::abs((m - m2).value());

    std::cout << "rounding error: " << roundingError << "\n";
}

struct IntType;

template<int N>
struct Int {
    static const int value = N;
    typedef IntType typetype;
    typedef Int type;

    // template<typename T>
    // auto operator+(const T& t) const -> Int<T::value + value> {
    //     static_assert(std::is_same<typetype, typename T::typetype>::value, "type is different");
    //     return Int<T::value + value>();
    // }

    // template<typename T>
    // auto operator-(const T& t) const -> Int<T::value - value> {
    //     static_assert(std::is_same<typetype, typename T::typetype>::value, "type is different");
    //     return Int<T::value - value>();
    // }


    template<typename T>
    Int<T::value + value> operator+(const T& t) const {
        static_assert(std::is_same<typetype, typename T::typetype>::value, "type is different");
        return Int<T::value + value>();
    }

    template<typename T>
    Int<T::value - value> operator-(const T& t) const {
        static_assert(std::is_same<typetype, typename T::typetype>::value, "type is different");
        return Int<T::value - value>();
    }
};

template<typename T, typename Dimensions>
struct tquantity {
    typedef Dimensions type;
    typedef T value_type;

    explicit tquantity(T x) : value_(x) {}
    const T& value() const { return value_; }

private:
    T value_;
};

typedef std::tuple<Int<0>, Int<0>, Int<0>, Int<0>, Int<0>, Int<0>, Int<0>> tscalar;
typedef std::tuple<Int<1>, Int<0>, Int<0>, Int<0>, Int<0>, Int<0>, Int<0>> tmass;
typedef std::tuple<Int<0>, Int<1>, Int<0>, Int<0>, Int<0>, Int<0>, Int<0>> tlength;
typedef std::tuple<Int<0>, Int<0>, Int<1>, Int<0>, Int<0>, Int<0>, Int<0>> ttime;
typedef std::tuple<Int<0>, Int<0>, Int<0>, Int<1>, Int<0>, Int<0>, Int<0>> tcharge;
typedef std::tuple<Int<0>, Int<0>, Int<0>, Int<0>, Int<1>, Int<0>, Int<0>> ttemperature;
typedef std::tuple<Int<0>, Int<0>, Int<0>, Int<0>, Int<0>, Int<1>, Int<0>> tintensity;
typedef std::tuple<Int<0>, Int<0>, Int<0>, Int<0>, Int<0>, Int<0>, Int<1>> tamount_of_substance;
typedef std::tuple<Int<0>, Int<1>, Int<-1>, Int<0>, Int<0>, Int<0>, Int<0>> tvelocity;
typedef std::tuple<Int<0>, Int<1>, Int<-2>, Int<0>, Int<0>, Int<0>, Int<0>> tacceleration;
typedef std::tuple<Int<1>, Int<1>, Int<-1>, Int<0>, Int<0>, Int<0>, Int<0>> tmomentum;
typedef std::tuple<Int<1>, Int<1>, Int<-2>, Int<0>, Int<0>, Int<0>, Int<0>> tforce;


template<typename T = tscalar, typename D = tscalar>
struct DimensionsBinaryOperatorPlus {
    static_assert(
            std::is_same<typename std::remove_reference<decltype(std::get<0>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<0>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<1>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<1>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<2>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<2>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<3>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<3>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<4>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<4>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<5>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<5>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<6>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<6>(D()))>::type::typetype>::value,
            "DimensionsBinaryOperatorPlus typetype is different");
    typedef std::tuple<
        decltype(std::get<0>(T()) + std::get<0>(D())),
        decltype(std::get<1>(T()) + std::get<1>(D())),
        decltype(std::get<2>(T()) + std::get<2>(D())),
        decltype(std::get<3>(T()) + std::get<3>(D())),
        decltype(std::get<4>(T()) + std::get<4>(D())),
        decltype(std::get<5>(T()) + std::get<5>(D())),
        decltype(std::get<6>(T()) + std::get<6>(D()))
        > type;
};

template<typename T = tscalar, typename D = tscalar>
struct DimensionsBinaryOperatorMinus {
    static_assert(
            std::is_same<typename std::remove_reference<decltype(std::get<0>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<0>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<1>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<1>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<2>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<2>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<3>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<3>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<4>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<4>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<5>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<5>(D()))>::type::typetype>::value &&
            std::is_same<typename std::remove_reference<decltype(std::get<6>(T()))>::type::typetype,
                typename std::remove_reference<decltype(std::get<6>(D()))>::type::typetype>::value,
            "DimensionsBinaryOperatorPlus typetype is different");
    typedef std::tuple<
        decltype(std::get<0>(T()) - std::get<0>(D())),
        decltype(std::get<1>(T()) - std::get<1>(D())),
        decltype(std::get<2>(T()) - std::get<2>(D())),
        decltype(std::get<3>(T()) - std::get<3>(D())),
        decltype(std::get<4>(T()) - std::get<4>(D())),
        decltype(std::get<5>(T()) - std::get<5>(D())),
        decltype(std::get<6>(T()) - std::get<6>(D()))
        > type;
};

template<typename T = tscalar, typename D = tscalar, typename BinaryOperator = DimensionsBinaryOperatorPlus<T, D>>
struct DimensionsTypeOperator {
    typedef typename BinaryOperator::type type;
};

template<typename T1, typename T2>
tquantity<typename T1::value_type, typename T1::type> operator+(const T1& lhs, const T2& rhs) {
    static_assert(std::is_same<typename T1::type, typename T2::type>::value, "T1::type must be same as T2::type");
    return tquantity<typename T1::value_type, typename T1::type>(lhs.value() + rhs.value());
}

template<typename T1, typename T2>
tquantity<typename T1::value_type, typename T1::type> operator-(const T1& lhs, const T2& rhs) {
    static_assert(std::is_same<typename T1::type, typename T2::type>::value, "T1::type must be same as T2::type");
    return tquantity<typename T1::value_type, typename T1::type>(lhs.value() - rhs.value());
}

template<typename T1, typename T2>
tquantity<typename T1::value_type, typename DimensionsTypeOperator<typename T1::type, typename T2::type>::type>
operator*(const T1& lhs, const T2& rhs) {
    typedef typename DimensionsTypeOperator<typename T1::type, typename T2::type>::type type;
    return tquantity<typename T1::value_type, type>(lhs.value() + rhs.value());
}

template<typename T1, typename T2>
tquantity<typename T1::value_type,
    typename DimensionsTypeOperator<typename T1::type, typename T2::type,
        DimensionsBinaryOperatorMinus<typename T1::type, typename T2::type>>::type>
operator/(const T1& lhs, const T2& rhs) {
    typedef typename DimensionsTypeOperator<typename T1::type, typename T2::type,
        DimensionsBinaryOperatorMinus<typename T1::type, typename T2::type>>::type type;
    return tquantity<typename T1::value_type, type>(lhs.value() / rhs.value());
}

void quantity_test() {
    tquantity<float, tmass> m(0.5f);
    tquantity<float, tacceleration> a(9.8f);
    tquantity<float, tforce> f = m * a;
    std::cout << "operator + test:" << (m + m).value() << std::endl;
    std::cout << "operator - test:" << (m - m).value() << std::endl;
    std::cout << "operator * test:" << (m * a).value() << std::endl;
    std::cout << "operator / test:" << (m / a).value() << std::endl;
}

namespace tymeta {

    template<class T, T ...Args>
    struct tyVector {
        typedef tyVector<T, Args...> type;
    };

    typedef tyVector<int, 1, 0, 0, 0, 0, 0, 0> mass;
    typedef tyVector<int, 0, 1, 0, 0, 0, 0, 0> length;
    typedef tyVector<int, 0, 0, 1, 0, 0, 0, 0> time;
    typedef tyVector<int, 0, 0, 0, 1, 0, 0, 0> charge;
    typedef tyVector<int, 0, 0, 0, 0, 1, 0, 0> temperature;
    typedef tyVector<int, 0, 0, 0, 0, 0, 1, 0> intensity;
    typedef tyVector<int, 0, 0, 0, 0, 0, 0, 1> amount_of_substance;

    template<class T1, class T2, class bop>
    struct tyTransform {};

    template<
        template<class Tv, Tv ...Args1> class T1,
        template<class Tv, Tv ...Args2> class T2,
        class Tv,
        Tv ...Args1,
        Tv ...Args2,
        class bop
    >
    struct tyTransform<T1<Tv, Args1...>, T2<Tv, Args2...>, bop> {
        typedef tyVector<Tv, bop::template apply<Tv, Args1, Args2>::value...> type;
    };

    template<class Tv, Tv v1, Tv v2>
    struct tyPlus_impl {
        typedef tyPlus_impl<Tv, v1, v2> type;
        const static Tv value = v1 + v2;
    };

    struct tyPlus {
        template<class Tv, Tv v1, Tv v2>
        struct apply : tyPlus_impl<Tv, v1, v2> {
        };
    };

    template<class Tv, Tv v1, Tv v2>
    struct tyMinus_impl{
        typedef tyMinus_impl<Tv, v1, v2> type;
        const static Tv value = v1 - v2;
    };

    struct tyMinus{
        template<class Tv, Tv v1, Tv v2>
        struct apply : tyMinus_impl<Tv, v1, v2> {
        };
    };

    template <class T, class Dimensions>
    struct quantity {
        explicit quantity(T x) : m_value(x) {}
        T value() const { return m_value; }
    private:
        T m_value;
    };

    template<class T, class D> quantity<T, D>
    operator+(const quantity<T, D>& x, const quantity<T, D>& y) {
        return quantity<T, D>(x.value() + y.value());
    }

    template<class T, class D> quantity<T, D>
    operator-(const quantity<T, D>& x, const quantity<T, D>& y) {
        return quantity<T, D>(x.value() - y.value());
    }

    template<class T, class D1, class D2> quantity<T, typename tyTransform<D1, D2, tyPlus>::type>
    operator* (const quantity<T, D1>& x, const quantity<T, D2>& y) {
        typedef typename tyTransform<D1, D2, tyPlus>::type dim;
        return quantity<T, dim>(x.value() * y.value());
    }

    template<class T, class D1, class D2> quantity<T, typename tyTransform<D1, D2, tyMinus>::type>
    operator/ (const quantity<T, D1>& x, const quantity<T, D2>& y) {
        typedef typename tyTransform<D1, D2, tyMinus>::type dim;
        return quantity<T, dim>(x.value() / y.value());
    }

    void test() {
        quantity<float, mass> m(0.5f);
        quantity<float, time> a(9.8f);
        auto f = m * a;
        std::cout << "operator + test:" << (m + m).value() << std::endl;
        std::cout << "operator - test:" << (m - m).value() << std::endl;
        std::cout << "operator * test:" << (m * a).value() << std::endl;
        std::cout << "operator / test:" << (m / a).value() << std::endl;
    }
}


template<int N>
struct Binary {
    static_assert(N % 10 + 1 <= 2, "expect 0 or 1");
    const static int value = Binary<N / 10>::value * 2 + N % 10;
};

template<>
struct Binary<0> {
    const static int value = 0;
};

void test_3_0() {
    std::cout << __func__ << std::endl;
    std::cout << Binary<10>::value << std::endl;
    // std::cout << Binary<20>::value << std::endl;
}

struct plus_t {
    template<long T>
    struct plus_tt {
        const static long value = (long long)T == std::numeric_limits<long long>::max() ? std::numeric_limits<long long>::max() : T + 1;
    };

    template<typename T>
    struct apply;
    template<template<typename, long... Args> class T, typename TT, long... Args>
    struct apply<T<TT, Args...>> {
        typedef T<TT, plus_tt<Args>::value...> type;
    };
};

void test_3_1() {
    std::cout << __func__ << std::endl;
    std::cout << 
        std::is_same<boost::mpl::vector_c<int, 2, 3, 4>,
            typename plus_t::apply<boost::mpl::vector_c<int, 1, 2, 3>>::type>::value << std::endl;
    static_assert(std::is_same<boost::mpl::vector_c<int, 2, 3, 4>,
            typename plus_t::apply<boost::mpl::vector_c<int, 1, 2, 3>>::type>::value);
}

struct multi_t {
    template<long T>
    struct multi_tt {
        const static long value = (long long)T >= std::numeric_limits<long long>::max() / 2 ?
                std::numeric_limits<long long>::max() : T * T;
    };
    template<typename T>
    struct apply;

    template<template<typename TT, long... Args> class T, long... Args>
    struct apply<T<int, Args...>> {
        typedef T<int, multi_tt<Args>::value...> type;
    };

};

void test_3_2() {
    std::cout << __func__ << std::endl;
    std::cout << 
        std::is_same<boost::mpl::vector_c<int, 1, 4, 9>,
            typename multi_t::apply<boost::mpl::vector_c<int, 1, 2, 3>>::type>::value << std::endl;
    static_assert(std::is_same<boost::mpl::vector_c<int, 1, 4, 9>,
            typename multi_t::apply<boost::mpl::vector_c<int, 1, 2, 3>>::type>::value);
}

template<typename T, template<typename TT> class func>
struct twice {
    typedef typename func<typename func<T>::type>::type type;
};

template<typename T>
struct add_pointer {
    typedef T** type;
};

void test_3_3() {
    std::cout << __func__ << std::endl;
    std::cout << std::is_same<twice<int, add_pointer>::type, int****>::value << std::endl;
    static_assert(std::is_same<twice<int, add_pointer>::type, int****>::value);
}

int main() {
    test();
    quantity_test();
    tymeta::test();
    test_3_0();
    test_3_1();
    test_3_2();
    test_3_3();
    return 0;
}

