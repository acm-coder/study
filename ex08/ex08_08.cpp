#include <iostream>
#include <iterator>
#include <map>

namespace std {
    // 必须在std命名空间内为pair声明“<<”重载函数
    template<typename T0, typename T1>
    ostream& operator << (ostream& os, pair<T0, T1> const &p)
    {
        os << '(' << p.first << ", " << p.second << ')';
        return os;
    }
}

int main()
{
    using namespace std;
    typedef map<int, char> ic_map;
    typedef ic_map::value_type value_type;
    // 映射初始值
    value_type data[] = {value_type(0, 'a'),
                         value_type(1, 'b'),
                         value_type(2, 'c')};

    ic_map m(data, data + 3);

    copy(m.begin(), m.end(),
         ostream_iterator<ic_map::value_type>(cout, " "));
    return 0;
}
