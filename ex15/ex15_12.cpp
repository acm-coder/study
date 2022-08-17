template<typename T0, typename T1>
struct my_pair
{
    T0 _first;
    T1 _second;

    template<typename TT0, typename TT1>
    my_pair(TT0 const &first, TT1 const &second) :
        _first(first), _second(second) {}
    
    T0 & first() {return _first;}
    T1 & second() {return _second;}
};
