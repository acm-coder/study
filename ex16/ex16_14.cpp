{
    using namespace std;
    shared_ptr<my_data> sp0;
    {
        shared_ptr<my_data> sp1(new my_data[10],
                                default_delete<my_data[]>() // 删除器实例
                                );
        sp0 = sp1;
    }
}
