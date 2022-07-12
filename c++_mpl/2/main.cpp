#include <iostream>
#include <type_traits>
#include <cassert>
using namespace std;


template<typename T>
struct add_const_ref {
    typedef T const & type;
};

// template<typename T>
// struct add_const_ref<T&> {
//     typedef T& type;
// };


void test_2_0() {
    cout << __func__ << endl;
    static_assert(is_same<add_const_ref<int&>::type, int&>::value);
    static_assert(is_same<add_const_ref<int>::type, int const&>::value);
    static_assert(is_same<add_const_ref<int const&>::type, const int&>::value);
    static_assert(is_same<add_const_ref<int const>::type, const int&>::value);
}


/*
 * IsMatch is used to resolve partial specialization ambiguity. 
 * The termination case is only specialized if IsMatch true, and all type traversal specializations, for when it's false.
 * Consider there to be no IsMatch
 * The second test case from the book uncovers the bug: 
 *           replace_type<int const*[10], int const, long>
 * Eventually, we'll reach replace_type<int const, int const, long>
 * But now we have 2 possible specs! 
 * The one that replaces type and the one that decomposes it.
 * Specializing with IsMatch solves this problem
 */

template <class T, 
         class OldType, 
         class NewType, 
         class IsMatch = typename is_same<T, OldType>::type
         >
struct replace_type
{
    typedef T type;
};

// Termination case
// ----------------

template <class OldType, class NewType>
struct replace_type<OldType, OldType, NewType, true_type>
{
    typedef NewType type;
};

// Type tree traversal
// -------------------

template <class T, class OldType, class NewType>
struct replace_type<T*, OldType, NewType, false_type>
{
    typedef typename replace_type<T, OldType, NewType>::type* type;
};

template <class T, class OldType, class NewType>
struct replace_type<T[], OldType, NewType, false_type>
{
    typedef typename replace_type<T, OldType, NewType>::type type[];
};

template <class T, size_t Size, class OldType, class NewType>
struct replace_type<T[Size], OldType, NewType, false_type>
{
    typedef typename replace_type<T, OldType, NewType>::type type[Size];
};

template <class T, class OldType, class NewType>
struct replace_type<T const, OldType, NewType, false_type>
{
    typedef typename replace_type<T, OldType, NewType>::type const type;
};

template <class T, class OldType, class NewType>
struct replace_type<T volatile, OldType, NewType, false_type>
{
    typedef typename replace_type<T, OldType, NewType>::type volatile type;
};

template <class T, class OldType, class NewType>
struct replace_type<T&, OldType, NewType, false_type>
{
    typedef typename replace_type<T, OldType, NewType>::type& type;
};

template <class Ret, class OldType, class NewType>
struct replace_type<Ret(), OldType, NewType, false_type>
{
    typedef typename replace_type<Ret, OldType, NewType>::type type();
};

template <class Ret, class ...Args, class OldType, class NewType>
struct replace_type<Ret(Args...), OldType, NewType, false_type>
{
    typedef typename replace_type<Ret, OldType, NewType>::type type(typename replace_type<Args, OldType, NewType>::type...);
};


void test_2_1() {
    cout << __func__ << endl;
    static_assert(is_same<replace_type<void, void, int>::type, int>::value);
    static_assert(is_same<replace_type<void*, void, int>::type, int*>::value);
    static_assert(is_same<replace_type<int[], int, char>::type, char[]>::value);
    static_assert(is_same<replace_type<int[2], int, char>::type, char[2]>::value);
    static_assert(is_same<replace_type<int const, int, char>::type, char const>::value);
    static_assert(is_same<replace_type<int volatile, int, char>::type, char volatile>::value);
    static_assert(is_same<replace_type<int&, int, char>::type, char&>::value);
    static_assert(is_same<replace_type<int(), int, char>::type, char()>::value);
    static_assert(is_same<replace_type<int(int), int, char>::type, char(char)>::value);
    static_assert(is_same<replace_type<int(int, char, int, char), int, char>::type, char(char, char, char, char)>::value);

    static_assert(is_same<replace_type<int const*[10], int const, long>::type, long*[10]>::value);
    static_assert(is_same<replace_type<char& (*)(char&), char&, long&>::type, long& (*)(long&)>::value);
}


template<typename T, typename S>
inline T polymorphic_downcast();

template<typename T, typename S>
inline T polymorphic_downcast(S* s) {
    assert(dynamic_cast<T>(s) == s);
    return static_cast<T>(s);
}

template<typename T, typename S>
inline T polymorphic_downcast(S& s) {
    assert(&dynamic_cast<T>(s) == &s);
    return static_cast<T>(s);
}

struct A {
    virtual ~A() {}
};

struct B : public A {};


void test_2_2() {
    cout << __func__ << endl;
    B b;
    A* a_ptr = &b;
    B* b_ptr = polymorphic_downcast<B*>(a_ptr);

    A& a_ref = b;
    B& b_ref = polymorphic_downcast<B&>(a_ref);
}


template<typename T>
struct type_descriptor;

template<>
struct type_descriptor<int> {
    friend ostream& operator<<(ostream& o, const type_descriptor& td) {
        return o << "int";
    }
};

template<>
struct type_descriptor<char> {
    friend ostream& operator<<(ostream& o, const type_descriptor& td) {
        return o << "char";
    }
};

template<>
struct type_descriptor<long> {
    friend ostream& operator<<(ostream& o, const type_descriptor& td) {
        return o << "long";
    }
};

template<>
struct type_descriptor<short int> {
    friend ostream& operator<<(ostream& o, const type_descriptor& td) {
        return o << "short int";
    }
};

template<typename T>
struct type_descriptor<T*> {
    friend ostream& operator<<(ostream& o, const type_descriptor& td) {
        return o << type_descriptor<T>() << "*";
    }
};

template<typename T>
struct type_descriptor<T&> {
    friend ostream& operator<<(ostream& o, const type_descriptor& td) {
        return o << type_descriptor<T>() << "&";
    }
};

template<typename T>
struct type_descriptor<T const> {
    friend ostream& operator<<(ostream& o, const type_descriptor& td) {
        return o << type_descriptor<T>() << " const";
    }
};


void test_2_3() {
    cout << __func__ << endl;
    cout << type_descriptor<int>() << endl;
    cout << type_descriptor<char*>() << endl;
    cout << type_descriptor<long const *&>() << endl;
}

int main() {
    test_2_0();
    test_2_1();
    test_2_2();
    test_2_3();
    return 0;
}


