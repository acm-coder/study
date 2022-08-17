template <typename T0, typename ...TPack>
struct highest_precision_of
{
    typedef typename highest_precision_of<TPack...>::type T1;
    typedef decltype(*((T0*)0) + *((T1*)0)) type;
};
