#include <iostream>
#include <set>

struct rough_comp
{
    float threshold;
    rough_comp(float const & thres = -1.e-2) :
        threshold( thres > 0. ? -1 * thres : thres) {}
    // 只有相差大于阈值threshold时才判断小于关系
    bool operator()(float const &l, float const &r) const {
        return (l - r) < threshold;
    }
};
int main()
{
    using namespace std;
    set<float, rough_comp>
        sf0,                    // 默认采用rough_comp()对象，即
                                // threshold=-1.e-2
        sf1(rough_comp(1.e-4));  // threshold=-1.e-4;

    sf0.insert(0.2f);
    sf1.insert(0.2f);

    cout << ((sf0.find(0.201f) != sf0.end()) ? "Yes" : "No") << endl;
    cout << ((sf1.find(0.201f) != sf1.end()) ? "Yes" : "No") << endl;

    return 0;
}
