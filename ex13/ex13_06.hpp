template<typename M_P, typename T>
struct find_in_pair
{
    // if (T == M_P::first) return T;
    // else if (T == M_P::second) return T;
    // else return void;
    typedef typename if_call<is_same<typename M_P::first, T>::result,
                             pipe_<T>,
                             if_<is_same<typename M_P::second, T>::result,
                                 T, void> >::return_type return_type;
};
