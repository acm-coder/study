template<typename FUNC>
struct reverse_bind
{
    FUNC func;

    reverse_bind(FUNC const &func) : func(func) {}

    template<typename PARAM0, typename PARAM1>
    void operator () (PARAM0 param0, PARAM1 param1) {
        func(param1, param0);
    }
};

template<typename FUNC>
reverse_bind<FUNC>
reverse_binder(FUNC const &f) {
    return reverse_bind<FUNC>(f);
}
