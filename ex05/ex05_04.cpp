#include <iostream>

struct root {int data;};

struct user_class : root {int user_data;};

class root_container
{
    root *holder;
public:
    root_container() : holder(0) {}
    void set(root *data) {
        if (holder) delete holder; // 释放旧数据内存
        holder = data;
    }
    root* get() {return holder;}
    ~root_container() {
        if (holder) delete holder; // 释放数据内存
    }
};

int main()
{
    // 第一部分
    root_container c;
    user_class *data = new user_class(); // 需要用户先申请内存
    data->user_data = 1;
    // data->user_data没有丢失
    c.set(data);
    std::cout<<((user_class*)c.get())->user_data<<std::endl;

    // 第二部分
    {
        user_class data2;
        c.set(&data2);          // 致命错误
    }
}
