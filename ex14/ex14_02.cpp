#include "huge_data.hpp"

huge_data prepare_data(unsigned sz)
{
    huge_data h(sz);
    // 为h填充数据，略
    return h;
}

int main()
{
    huge_data a;
    a = prepare_data(1024);
    return 0;
}
