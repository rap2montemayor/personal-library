// Iterative Segment Tree
// 
// Range queries and point updates in O(log n). Constructed in O(n logn).
// The tree is built starting from the leaves. Bottom-up style.
// Queries take advantage of various properties of this implementation.
//      - The original array is contained in vals[n,2*n]
//      - Whether vals[i] contains elements outside of the range [l, r) can be
//          determined by checking the parity of i, and the side i started from.
//          This lets us know if it is okay to "jump" to a more "inner" branch.
//
// Notes:
// - Queries are [l, r).
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