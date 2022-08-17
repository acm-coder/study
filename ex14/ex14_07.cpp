#pragma once
#include <iostream>
#include <algorithm>

struct huge_data
{
    // 旧有构造，复制构造，赋值及析构函数与例14.1相同，略

    // 移动构造与赋值函数
    huge_data(huge_data &&r) : content(0), sz(0) {
        using namespace std;
        swap(r);
        // 打印调用信息
        cout << this << "->huge_data(" << &r << ")rr" << endl;
    }

    huge_data& operator = (huge_data &&r) {
        using namespace std;

        if (content) delete[] content;
        sz = 0;
        swap(r);
        // 打印调用信息
        cout << this << "->operator=(" << &r << ")rr" << endl;

        return *this;
    }
    void swap(huge_data &r) {
        using std::swap;
        swap(content, r.content);
        swap(sz, r.sz);
    }
};
