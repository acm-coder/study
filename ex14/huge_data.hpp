// 文件名：huge_data.hpp
#pragma once
#include <iostream>
#include <algorithm>

struct huge_data
{
    char *content;
    unsigned sz;
    huge_data() : content(0), sz(0) {
        using namespace std;
        cout << this << "->huge_data()" << endl;
    }
    huge_data(unsigned sz) : content(new char[sz]), sz(sz) {
        using namespace std;
        // 打印调用信息
        cout << this << "->huge_data("<<sz<<')' << endl;
    }
    huge_data(huge_data const& h) : content(new char[h.sz]), sz(h.sz) {
        using namespace std;
        // 将h的内容复制至本实例
        copy(h.content, h.content + sz, content);
        // 打印调用信息
        cout << this << "->huge_data("<<&h<<')' << endl;
    }
    huge_data& operator = (huge_data const& h) {
        using namespace std;

        if (&h == this) return *this; // 防止自身赋值

        // 释放原有内容
        if (content) delete[] content;

        // 将h的内容复制到本实例
        content = new char[h.sz];
        copy(h.content, h.content + sz, content);
        sz = h.sz;
        // 打印调用信息
        cout << this << "->operator=("<<&h<<')' << endl;

        return *this;
    }

    ~huge_data() {
        // 释放内存
        if (content) delete[] content;
    }
};
