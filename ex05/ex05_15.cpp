#include "list.hpp"
#include "algorithms.hpp"

int main()
{
    list<int> la;

    for (int i = 0; i < 7; ++i)
	la.push_front(i * 2 % 7);

    typedef list<int>::iterator iterator;
    iterator it1 = find(la.begin(), la.end(), 3);
    iterator it2 = find(la.begin(), la.end(), 3);
    // 迭代器it1与it2此时都指向数据“3”
    la.erase(it1);

    la.erase(it2);		// 致命内存错
}
