void foo()
{
    throwing_data *old_space = (throwing_data*)malloc(sizeof(huge_data) * 3);
    // 在旧空间上生成三个throwing_data实例
    for (unsigned i = 0; i < 3; ++i) {
        new (old_space + i) throwing_data(i);
    }

    // 申请新空间
    throwing_data *new_space = (throwing_data*)malloc(sizeof(huge_data) * 3);

    try {
        move_construct_all(old_space, old_space + 3, new_space);
    }
    catch (int err) {
        std::cout << "Caught an exception during move_construct_all()" << std::endl;
    }

    free(old_space);
    free(new_space);
}
