// [l,r)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l,r-1)(rng) }