typedef std::pair<int, int> pair_ii;
typedef std::list<pair_ii> list_pair_ii;

void sort_by_second(list_pair_ii &l)
{
    l.sort([]                   // λ表达式捕获列表，稍后介绍
           (pair_ii const &p1,
            pair_ii const &p2)  // λ表达式参数列表
           {                    // 函数体
               return p1.second < p2.second;
           }
           );
}
