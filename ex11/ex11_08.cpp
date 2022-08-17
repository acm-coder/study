// 文件名：code_bloat.cpp
#if defined COMMON_BASE
  #include "list_common_base.hpp"
#else
  #include "list.hpp"
#endif

// 用于生成不同类型的类模板
template<int i>
struct unique_type
{
    int v;
    unique_type() : v() {}
    unique_type(unique_type const &u) : v(u.v) {}
};

// 调用链表成员函数的测试函数
template<typename List>
void call_all_member_func()
{
    List l;
    typename List::value_type v0;
    l.push_back(v0);
    l.reverse();
    List l0;
    l.assign(l0);
    l.erase(l.begin());
    l.pop_back();
}

int main()
{
    call_all_member_func<list<unique_type<0> > >();
#if defined TYPE_10 || TYPE_20
    call_all_member_func<list<unique_type<1> > >();
    call_all_member_func<list<unique_type<2> > >();
    call_all_member_func<list<unique_type<3> > >();
    call_all_member_func<list<unique_type<4> > >();
    call_all_member_func<list<unique_type<5> > >();
    call_all_member_func<list<unique_type<6> > >();
    call_all_member_func<list<unique_type<7> > >();
    call_all_member_func<list<unique_type<8> > >();
    call_all_member_func<list<unique_type<9> > >();
#endif

#if defined TYPE_20
    call_all_member_func<list<unique_type<10> > >();
    call_all_member_func<list<unique_type<11> > >();
    call_all_member_func<list<unique_type<12> > >();
    call_all_member_func<list<unique_type<13> > >();
    call_all_member_func<list<unique_type<14> > >();
    call_all_member_func<list<unique_type<15> > >();
    call_all_member_func<list<unique_type<16> > >();
    call_all_member_func<list<unique_type<17> > >();
    call_all_member_func<list<unique_type<18> > >();
    call_all_member_func<list<unique_type<19> > >();
#endif
    return 0;
}
