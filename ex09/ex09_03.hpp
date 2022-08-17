#include <algorithm>
#include <iterator>
#include <set>

template<typename T>
std::multiset<T> operator || (std::multiset<T> const& l,
                              std::multiset<T> const& r)
{
    std::multiset<T> result;
    std::set_union(l.begin(), l.end(), r.begin(), r.end(),
                   std::inserter(result, result.end()));
    return result;
}
