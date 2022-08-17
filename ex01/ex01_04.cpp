#include <iostream>
#include "ex01_03.hpp"

int main()
{
    int l[] = {2, 0, 1, 1, 0, 8, 2, 5};
    char cl[] = "August";

    using namespace std;
    cout << max_element<int>(l, 8) << endl;
    cout << max_element<char>(cl, 6) << endl;

    return 0;
}
