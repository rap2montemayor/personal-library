// Ternary Search on Integers
//
// Returns an integer i such that obj(i) is maximal.
//
// Note:
// - Searches in the range (l, r). Both l and r are exclusive. A consequence of
//      this is that l may have to be set to -1;
// - If searching in an array a, obj() may have to access a[l] or a[r]. Make sure
//      to account for this properly.
// - This not guaranteed to work if obj(i) == obj(i+1) for some i where obj(i)
//      is not maximal.
// - Behavior can be finnicky. Make sure to test.
// - This implementation can be thought of as binary searching for 0 on the
//      differences between adjacent elements. This may be analogous to getting
//      the zeroes of a derivative.

int obj(int m) {
    return a[m];
}

int find() {
    int l = -1, r = n, m;
    while (r-l > 1) {
        m = (l+r) >> 1;
        if (obj(m) < obj(m+1)) l = m;
        else r = m;
    }
    return l+1;
}