#include <set>
std::multiset<int> msi; //整数集合
// 用于粗略比较浮点数的函数对象
struct rough_comp
{
    // 相差不大于0.01的值可认为大约相等
    bool operator()(float const &l, float const &r) const {
        return (l - r) < -0.01f;
    }
};
std::set<float, rough_comp> fs;
