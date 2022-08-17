class my_class
{
public:
    my_class(int, char);        // #1
    my_class();                 // #2
    template<typename T>
    my_class(std::initializer_list<T> const &i); // #3
};
my_class mc0 = {1, 2, 3, 4};    // 调用#3构造函数
my_class mc1 = {1, 2};          // 调用#3构造
my_class mc2 = {1, 'c'};        // 调用#1构造
