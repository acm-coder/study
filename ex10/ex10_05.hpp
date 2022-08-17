template<SampleConcept T, typename U>
requires (Constructable<T, U>, FooCallable<T>)
void sample_function(T const &v, U const &w)
{
    // 以下两行需要SampleConcept<T>
    typedef typename T::value_type value_type; 
    free_func(v);
    // 以下需要SampleConcept<T>及Constructable<T, U>
    T(w).member_func();
    // 以下需要FooCallable<T>
    foo(v);
}
