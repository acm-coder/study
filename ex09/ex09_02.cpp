#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

int main()
{
    using namespace std;
    int array[] = {0, 0, 0, 1, 2, 3};
    list<int> l(array, array + 6);
    cout << "Pre-removing:  ";
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    remove(l.begin(), l.end(), 0); // 删除所有0值
    cout << endl << "Post-removing: ";
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
