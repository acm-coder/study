template<typename T, unsigned sz>
struct array0
{
    T data[sz];
    array0() {}
    array0(array0 &&a) {
        for (unsigned i = 0; i < sz; ++i)
            data[i] = std::move(a.data[i]);
    }
};

template<typename T, unsigned sz>
struct array1
{
    T *data;
    array1() : data(new T[sz]) {}
    ~array1() {delete data;}
    array1(array1 &&a) : data(new T[sz]) {
        std::swap(data, a.data);
    }
};
