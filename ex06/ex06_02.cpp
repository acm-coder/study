#include <iostream>
#include <vector>

int main()
{
    int array[] = {0, 1, 2, 3, 4};
    std::vector<int> v;

    v.reserve(5);
    v.assign(array, array + 5);

    typedef std::vector<int>::iterator iterator;
    iterator p = v.begin();
    iterator q = v.end() - 1;
    // 迭代器位置，e为v.end()位置
    // p       q e
    // 0 1 2 3 4

    v.erase(p + 1, p + 3);
    // p     e q
    // 0 3 4 - -
    std::cout<<(q - v.end())<<std::endl;

    v.insert(v.end(), array, array + 5); // 空间不足，重新申请
    // p       q
    // - - - - - ... ... 0 3 4 0 1 2 3 4
    std::cout<<(p - v.begin())<<std::endl;
    std::cout<<(q - v.end())<<std::endl;
    return 0;
}
