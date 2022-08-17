template<typename T, typename ...TPack>
T emplace_construct(TPack && ...ppack)   // 声明函数参数包时将模板参数
                                         // 包按只读引用模式展开
{
    return T(std::forward<TPack>(ppack)...);
}
// 调用emplace_construct<std::pair<int, char> >(0, 'a')将用参数
// (0, 'a')构造并返回std::pair<int, char>实例


template<typename ...Bases>
struct derived_class: Bases...  // 在基类列表处展开模板参数包
{};

typedef derived_class<std::string, std::istream, std::ostream>
the_derived_class;
// the_derived_class将继承自模板参数包中的三个类型
