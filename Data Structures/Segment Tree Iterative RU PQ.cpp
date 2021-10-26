struct segtree {
    int n, vals[2*MAXN] = {};
    segtree(int n, int a[]) : n(n) {
        for (int i = 0; i < n; ++i)
            vals[n+i] = a[i];
        for (int i = n - 1; i > 0; --i)
            vals[i] = vals[i<<1] + vals[i<<1|1];
    }

    // Increase all elements in [l,r) by val
    void update(int l, int r, int val) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) vals[l++] += val;
            if (r&1) vals[--r] += val;
        }
    }

    int query(int p) {
        int res = 0;
        for (p += n; p > 0; p >>= 1)
            res += vals[p];
        return res;
    }
};
