#include <iomanip>
#include <iostream>
#include <set>

typedef std::set<int> int_set;
typedef void func_type(int*, int*);

// 测试函数的运行时间
float measure(func_type func, int *start, int *end)
{
    int start_clock = clock();
    func(start, end);
    int end_clock = clock();

    return float(end_clock - start_clock) / CLOCKS_PER_SEC;
}

// 调用insert(i, j)插入
void test_plain_insert(int *start, int *end)
{
    int_set s;
    s.insert(start, end);
}

// 调用insert(p, v)智能插入
void test_smart_insert(int *start, int *end)
{
    int_set s;
    int_set::iterator prev = s.begin();
    for (; start != end; ++start)
        prev = s.insert(prev, *start);
}

int main()
{
    const int num = 1e6;
    const int half = num / 2;

    int array1[num];
    int array2[num];

    // array1是一个单调递增序列，形如[0, 1, 2, 3, ...]
    // array2是一个振荡收敛序列，形如[9, -8, 7, -6, ...]
    for (int i = 0; i < num; ++i) {
        array1[i] = i;
        array2[i] = (i&1) ? (i - num) : (num - i);
    }

    using namespace std;
    
    cout << std::setprecision(2)
         << "plain insert for array1: "
         << measure(test_plain_insert, array1, array1 + num)
         << " sec." << endl;

    cout << "smart insert for array1: "
         << measure(test_smart_insert, array1, array1 + num)
         << " sec." << endl;

    cout << "plain insert for array2: "
         << measure(test_plain_insert, array2, array2 + num)
         << " sec." << endl;
    cout << "smart insert for array2: "
         << measure(test_smart_insert, array2, array2 + num)
         << " sec." << endl;
}
