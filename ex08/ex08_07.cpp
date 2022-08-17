#include <cstring>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    char array[] = "Madam I'm Adam";
    using namespace std;
    typedef reverse_iterator<char*> backward_iterator;

    copy(backward_iterator(array + strlen(array)),
         backward_iterator(array),
         ostream_iterator<char>(cout));

    cout << endl;
    return 0;
}
