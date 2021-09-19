#include "config.h"

#ifdef USE_MYMATH
#include "math/funcs.h"
#else
#include "iostream"
using namespace std;
#endif


int main() {
#ifdef USE_MYMATH
    print();
#else
    cout << "system library used" << endl;
#endif
    return 0;
}