template<class Value, class Alloc = allocator<Value> >
class vector;                   // list, forward_list, deque同

template<class Value,
         class Compare = less<Value>,
         class Alloc = allocator<Value> >
class set;                      // multiset同

template<class Key, class Value,
         class Compare = less<Key>,
         class Alloc = allocator<pair<const Key, Value> > >
class map;                      // multimap同

template<class Value,
         class Hash = hash<Value>,
         class Pred = equal_to<Value>,
         class Alloc = allocator<Value> >
class unordered_set;            // unordered_multiset同

template<class Key, class Value,
         class Hash = hash<Key>,
         class Pred = equal_to<Key>,
         class Alloc = allocator<pair<const Key, Value> > >
class unordered_map;            // unordered_multimap同
