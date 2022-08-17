void prepare_data(unsigned sz, huge_data *anonymous_address)
{
    new (anonymous_address) huge_data(sz);
    // 直接在anonymous_address所指对象上填充数据。略
}

int main()
{
    huge_data a;
    char anonymous_space[sizeof(huge_data)];
    prepare_data(1024, (huge_data*)anonymous_space);
    huge_data *ptr = (huge_data*)anonymous_space; // 指针转义
    a = *ptr;
    ptr->~huge_data();      // 析构该huge_data对象
    return 0;
}
