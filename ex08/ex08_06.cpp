void foo() {
    using namespace std;
    istringstream s("The quick brown fox jumps over the lazy dog.");

    typedef istream_iterator<char> char_istream_iterator;
    cout << count(char_istream_iterator(s),
                  char_istream_iterator(),
                  'o')  // 统计流中某字符的出现次数
         << endl;
}
