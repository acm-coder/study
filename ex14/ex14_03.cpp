void prepare_data(unsigned sz, huge_data *anonymous_address)
{
    huge_data h(sz);            // ＃2. 调用huge_data的sz构造函数
    // 为h填充数据。略
    new (anonymous_address) huge_data(h); // ＃3. 调用huge_data的复制构造函数
}

int main()
{
    huge_data a;                // ＃1. 调用huge_data的默认构造函数
    char anonymous_space[sizeof(huge_data)]; // 为调用prepare_data而预留的空间
    prepare_data(1024, (huge_data*)anonymous_space);
    huge_data *ptr = (huge_data*)anonymous_space; // 指针转义
    a = *ptr;               // ＃4. 调用huge_data的operator=
    ptr->~huge_data();      // 析构该huge_data对象
    return 0;
}
