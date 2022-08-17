#include <iostream>

template<typename T0,
         typename T1,
         typename T2,
         typename T3,
         typename T4>
T2 func(T1 v1, T3 v3, T4 v4);

int main() {

    double sv2;

    using namespace std;
    sv2 = func<double, int, int>(1, 2, 3);
    cout << "\tsv2: " << sv2 << endl;

    sv2 = func<double, int, int>(1, 2, 3);
    cout << "\tsv2: " << sv2 << endl;

    sv2 = func<double, int, int>(1, 0.1, 0.1);
    cout << "\tsv2: " << sv2 << endl;

    sv2 = func<int, double, double>(0.1, 0.1, 0.1);
    cout << "\tsv2: " << sv2 << endl;
}

template<typename T0,
         typename T1,
         typename T2,
         typename T3,
         typename T4>
T2 func(T1 v1, T3 v3, T4 v4)
{
    T0 static sv0 = T0(0);
    T2 static sv2 = T2(0);

    std::cout << "\tv1: " << v1
              << "\tv3: " << v3
              << "\tv4: " << v4
              << "\t|| sv0: " << sv0;
    T2 v2 = sv2;

    sv0 -= 1;
    sv2 -= 1;

    return v2;
}
