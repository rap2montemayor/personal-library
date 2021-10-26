// Ternary Search on Integers
//
// Returns an integer i such that obj(i) is maximal.
//
// Note:
// - This implementation assumes that obj is bitonic, and opens downards
// - Don't forget to check for literal edge cases.
// - Behavior can be finnicky like binary search. Make sure to test.
// - This implementation can be thought of as binary searching for 0 on the
//      differences between adjacent elements. This is analogous to getting the
//      zeroes of a derivative of a quadratic function.

int obj(int m) {
    return a[m];
}

int find() {
    int l = -1, r = n, m;
    while (r-l > 1) {
        m = (l+r) >> 1;
        if (obj(a, m) < obj(a, m+1))
            l = m;
        else
            r = m;
    }
    return l+1;
}