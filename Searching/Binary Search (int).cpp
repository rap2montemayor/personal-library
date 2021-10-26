// Binary Search on Integers
//
// Returns the last integer i such that obj(i) < x.
//
// Note:
// - This implementation assumes obj monotonically increases
// - Behavior can be finnicky when changes are made on
//      - the comparison
//      - how l and r are updated
//      - how m is computed
// - Make sure to test when making changes
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