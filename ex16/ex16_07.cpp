class my_class
{
public:
    my_class(int, char);
    my_class();
};
my_class mc0 = {1, 'c'};           // 等价于my_class mc(1, 'c');
my_class mc1 {1, 'c'};            // 同上
