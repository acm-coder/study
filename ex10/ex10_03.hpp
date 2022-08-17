concept SampleConcept<typename T>
{
    typename value_type;        // 嵌套类型定义约束
    void free_func(T const &);  // 普通函数约束
    void T::member_func() const; // 成员函数约束
}
