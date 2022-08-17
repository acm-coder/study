struct root {int data;};

struct user_class : root {int user_data;};

struct root_container
{
    root holder;
public:
    void set(root data) {holder = data;}
};

int main()
{
    root_container c;
    user_class data;
    c.set(data);  // 对象data.user_data丢失
}
