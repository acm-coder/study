#include <string>
#include <iostream>

template<typename T>
void print(T v)
{
    std::cout << v << std::endl;
}

//定义成模板特例
template<>
void print<char>(char v)
{
    std::cout << '\'' << v << '\'' << std::endl;
}

//模板特例，模板参数依赖推导
template<>
void print(const char *v)
{
    std::cout << '"' << v << '"' << std::endl;
}

//函数重载
inline
void print(std::string const &v)
{
    std::cout << "\'\'\'" << v << "\'\'\'" << std::endl;
}

inline
void print(bool v)
{
    std::cout << (v ? "true" : "false") << std::endl;
}

//函数模板重载
template<typename T>
void print(T *v)
{
    std::cout << '*';
    print(*v);
}
