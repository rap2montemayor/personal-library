// Notes:
// - If x not in a, return the index of the largest
// element less than x
// - Consider using lower_bound(), upper_bound(),
// or binary_search() from the standard library
bool obj(int x, int m, vi &a) {
    return a[m] <= x;
}

int find(int x, vi &a) {
    int l = 0, r = a.size(), m;
    while (r - l > 1) {
        m = (l+r) / 2;
        if (obj(x, m, a)) l = m;
        else r = m;
    }
    return l;
}