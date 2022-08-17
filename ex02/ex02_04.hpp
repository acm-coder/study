template<typename T, typename N>
hetero_node<T, N>* push(T const &v, N *n)
{
    return new hetero_node<T, N>(v, n);
}
