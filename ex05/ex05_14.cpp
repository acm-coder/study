#include "list.hpp"
#include "algorithms.hpp"

int main()
{
    list<int> la, lb;

    for (int i = 0; i < 7; ++i) {
	la.push_front(i * 2 % 7);
	lb.push_front(i * 2 % 7);
    }

    list<int>::iterator it = find(lb.begin(), lb.end(), 3);
    la.erase(it);        // 容器与迭代器不一致，不涉及修改容器的
                         // 链表头指针

    print(la.begin(), la.end());
    print(lb.begin(), lb.end());

    it = find(lb.begin(), lb.end(), 5);
    la.erase(it);         // 容器与迭代器不一致，且需要修改容器的
                          // 链表头指针

    print(la.begin(), la.end());
    print(lb.begin(), lb.end());
}
