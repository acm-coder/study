template<typename T>
T const& max_element(T const *l, unsigned sz)
{
    T const *max_value(l);
    for (unsigned i = 1; i < sz; ++i)
        if (l[i] > *max_value) max_value = &(l[i]);
    return *max_value;
}
