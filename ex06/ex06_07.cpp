#include <iostream>
#include <unordered_map>
#include <set>

// 自定义散列函数
struct my_hash_func
{
    // 一个有意为之的低效散列函数，限制数据只存放在前4个桶中
    size_t operator()(int i) const {return i % 4;}
};

// my_map是一个利用自定义散列函数的散列表映射容器
typedef std::unordered_multimap<int, int, my_hash_func> my_map;

void print_map(my_map &m, int max_bucket)
{
    std::cout << "bucket count: " << m.bucket_count() << std::endl;
    for (size_t i = 0; i < max_bucket; ++i) {
        std::cout << "bucket " << i << ':';
        // auto也是C++11的新特性，根据表达式自动推导出类型

        for (auto j = m.begin(i); j != m.end(i); ++j)
            std::cout << " (" << j->first << ',' << j->second << ')';
        std::cout << std::endl;
    }
}

int main()
{
    // C++11的另一个新特性，用initializer_list构造初始容器
    my_map mm = {{8, 0}, {9, 0}, {10, 0}, {11, 0},
                 {4, 0}, {5, 0}, {6, 0}, {7, 0}};

    // 又是用auto
    for (auto p = std::make_pair(int(0), int(1));
         p.first < 20; ++p.first)
        mm.insert(p);

    print_map(mm, 4);
}
