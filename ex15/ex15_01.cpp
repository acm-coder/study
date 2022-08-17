#include <cstdarg>
// 求任意数量整数参数之和。 count为待求和整数个数
int sum(unsigned count, ...)    // 以三连点标识变长参数序列
{
    va_list ap;                 // 首先声明一个va_list型参数序列变量

    va_start(ap, count);        // 准备遍历参数调用栈内的变长参数数据
                                // 首先利用最后一个固定参数（即count）
                                // 定位变长参数序列的起始位置
    int result = 0;
    for (int i = 0; i < count; ++i) {
        result += va_arg(ap, int); // 从参数序列中取出一个参数，假定其为int型
    }
    va_end(ap);                 // 结束遍历参数序列
    return result;
}
