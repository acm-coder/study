#include <iostream>
#include <queue> // priority_queue是定义在<queue>中
#include <vector>

// 二元组类
struct my_pair
{
    int first;
    int second;
};

// 函数对象，以字典顺序比较二元组
struct comp_my_pair
{
    bool operator()(my_pair const &left,
                    my_pair const &right) {
        return
            left.first == right.first ?
            left.second > right.second :
            left.first > right.first;
    }
};

int main()
{
    my_pair array[] = {{3, 0}, {2, 1}, {1, 2}, {0, 3}, {0, 4}};
    using std::priority_queue;
    using std::vector;

    priority_queue<my_pair, vector<my_pair>, comp_my_pair>
        pq(array, array + 5);
    while (!pq.empty()) {
        std::cout<<pq.top().first<<", "<<pq.top().second<<std::endl;
        pq.pop();
    }
    return 0;
}
