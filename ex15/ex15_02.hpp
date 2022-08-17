template <typename ...TPack>
int sum(TPack ...ppack);     // ppack为一函数参数包

void foo()
{
    sum();                   // ppack为空参数包
    sum(int(0));                  // ppack包含一个整数实参，值为0
    sum(int(0), float(1.2), std::string("zero"));
    // ppack包含三个实参，类型分别为整数型，浮点型以及std::string型。虽然std::string类型出现在sum函数中不合理，但在仅有函数声明时是可编译的
}
