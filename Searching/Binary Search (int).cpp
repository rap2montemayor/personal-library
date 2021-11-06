// Binary Search on Integers
//
// Returns the last integer i such that obj(i) < x.
//
// Note:
// - Searches in the range [l, r)
// - Behavior can be finnicky. Make sure to test.
// - Consider using lower_bound() or upper_bound() if you are simply searching
//      for an element in an array.

int obj(int m) {
    return a[m];
}

int find(int x) {
    int l = 0, r = n, m;
    while (r-l > 1) {
        m = (l+r) >> 1;
        if (obj(m) < x) l = m;
        else r = m;
    }
    return l;
}