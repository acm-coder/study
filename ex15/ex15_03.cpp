template <typename ...TPack>
void bar(TPack ...ppack, int i); // 函数参数包ppack不在参数列表末尾

void foo2()
{
    bar<int, int>(0, 1, 2);
    // 模板参数包TPack内容由显式声明的模板实参列表决定为int, int。则函
    // 数参数包ppack将匹配两个整数型参数。函数模板实例需要三个整数型参数

    bar(0);
    // 无函数模板实参，则模板与函数参数包内容均由函数实参推导而得。由于
    // ppack不处于参数列表末尾，将不匹配任何参数。函数模板实例只有一个
    // 整数型参数，即函数模板中的非包参数i

    bar('a', 0);
    // 错误用法。因为ppack将不匹配任何参数
}
