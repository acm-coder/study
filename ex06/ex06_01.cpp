#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    // v.reserve(10);
    for (unsigned i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout<<i
                 <<": size="<<v.size()
                 <<", capacity="<<v.capacity()<<std::endl;
    }
    return 0;
}
