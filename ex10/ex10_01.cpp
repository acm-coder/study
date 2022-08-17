#include <vector>

class my_data
{
    my_data(const my_data &data) {} // 私有的复制构造函数
public:
    my_data() {}
};

int main()
{
    std::vector<my_data> my_data_vector; // 错误的源头。my_data不能复制构造，不满足容器数据要求
    my_data_vector.push_back(my_data()); // 错误发生地。此处引发编译器生成vector<my_data>实例，从而出错
}
