template<typename C>
typename C::value_type
sum(C &c)
{
    typedef typename C::value_type value_type;
    typedef typename C::iterator iterator;

    value_type sum(0);

    for (iterator i = c.begin(); i != c.end(); ++i) sum += *i;
    return sum;
}
