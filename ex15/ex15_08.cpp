void foo(std::vector<std::string> const &vs)
{
    using namespace std;
    for (vector<string>::const_iterator i = vs.begin();
         // 冗长的迭代器类型声明
         i != vs.end(); ++i) {
        // ...
    }
}
