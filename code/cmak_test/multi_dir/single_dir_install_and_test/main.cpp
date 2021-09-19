#include "config.h"

#ifdef USE_MYMATH
#include "funcs.h"
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
    cout << app_VERSION_MAJOR << ": " << app_VERSION_MINOR << endl;
    return 0;
}