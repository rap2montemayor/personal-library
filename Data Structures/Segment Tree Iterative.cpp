// Iterative Segment Tree
// 
// Segment tree that supports O(log n) range queries and point updates.
//
// Notes:
// - Queries are [l, r).
// - Works like the recursive version, but the tree is built starting from the
//      leaves instead of the root. Bottom-up style.
// - Queries take advantage of various properties of this implementation.
//      - The original array is contained in vals[n,2*n]
//      - Queries start from the two farthest leaves corresponding to [l, r).
//      - Whether vals[i/2] contains elements outside of the range [l, r) can
//          be determined by checking the parity of i. When that happens, it is
//          safe to "jump" to a more "inner" branch.
// - Tested on SPOJ FENTREE https://www.spoj.com/problems/FENTREE/
// - Reference: https://codeforces.com/blog/entry/18051

struct segtree {
    int n, vals[2*MAXN];

    segtree(int a[], int n) : n(n) {
        for (int i = 0; i < n; ++i)
            vals[n+i] = a[i];
        for (int i = n - 1; i > 0; --i)
            vals[i] = vals[i<<1] + vals[i<<1|1];
    }

    // Increases the value at p by val
    void update(int p, int val) {
        for (vals[p += n] += val; p > 1; p >>= 1)
            vals[p>>1] = vals[p] + vals[p^1];
    }

    // Gets the sum of elements in [l,r)
    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += vals[l++];
            if (r&1) res += vals[--r];
        }
        return res;
    }
};