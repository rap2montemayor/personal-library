struct segtree {
    int n, vals[2*MAXN] = {};
    segtree(int n, int a[]) : n(n) {
        for (int i = 0; i < n; ++i)
            vals[n+i] = a[i];
        for (int i = n - 1; i > 0; --i)
            vals[i] = vals[i<<1] + vals[i<<1|1];
    }

    // Increases the value at [p] by val
    void update(int p, int val) {
        for (vals[p += n] = val; p > 1; p >>= 1)
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