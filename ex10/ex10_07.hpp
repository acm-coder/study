// 文件名：concept_check.hpp
template<typename T>
struct less_than_comparable
{
    static bool check() {
        T a, b;
        return a < b;           // 用一个真正的“小于”比较语句强制检查
    }
};
