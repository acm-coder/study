concept CopyConstructable<typename T>
{
    T::T(T const&);
}

concept FooCallable<typename T>
{
    requires CopyConstructable<T>;
    void foo(T);
}
