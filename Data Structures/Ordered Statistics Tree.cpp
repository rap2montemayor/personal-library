#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;
// Usage:
// ordered_set<int> t;
// t.insert(key)
// t.find_by_order(index); // 0-based. returns iterator to key
// t.order_of_key(key);
// t.erase(key);