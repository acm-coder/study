#include <cstring>
#include <iostream>
#include <iterator>
#include <algorithm>

void print(char c) {std::cout << c;}
int main()
{
    char array[] = "Madam I'm Adam";
    typedef std::reverse_iterator<char*> backward_iterator;

    using namespace std;

    for_each(backward_iterator(array + strlen(array)),
             backward_iterator(array),
             print);

    cout << endl;
    return 0;
}
