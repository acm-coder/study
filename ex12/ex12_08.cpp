#include "vector.hpp"
#include <iostream>

struct huge_data
{
    static unsigned ever_copy_constructed; // 记录调用构造函数的次数
    huge_data() {}
    huge_data(huge_data const &hd) {++ever_copy_constructed;}
};

unsigned huge_data::ever_copy_constructed = 0;

void print_ecc()
{
    static unsigned old_ecc = 0;
    std::cout << "ECC: " << huge_data::ever_copy_constructed
              << "\t delta ECC: " << (huge_data::ever_copy_constructed - old_ecc)
              << std::endl;
    old_ecc = huge_data::ever_copy_constructed;
}

int main()
{
    huge_data array[] = {huge_data(), huge_data(), huge_data(),
                         huge_data(), huge_data(), huge_data(),
                         huge_data(), huge_data()};
    std::cout << "ECC means \"ever copy constructed\"." << std::endl;
    print_ecc();

    // 采用实例保存数据策略的容器
    vector<huge_data> v(array, array + 8);
    print_ecc();

    // 采用指针保存数据策略的容器
    vector<huge_data, pointer_data_policy> pv(array, array + 8);
    print_ecc();
}
