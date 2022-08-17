#include <cstring>
#include <iostream>
#include <iterator>

int main()
{
    char array[] = "Madam I'm Adam";
    using namespace std;
    typedef reverse_iterator<char*> backward_iterator;
    backward_iterator b(array + strlen(array));
    backward_iterator end(array);

    for (; b != end; ++b) cout << *b;
    cout << endl;
    return 0;
}
