struct segtree {
    int n, h, vals[2*MAXN] = {}, deltas[MAXN] = {};
    segtree(int n, int a[]) {
        h = sizeof(int) * 8 - __builtin_clz(n);
        for (int i = 0; i < n; ++i)
            vals[n+i] = a[i];
        for (int i = n - 1; i > 0; --i)
            vals[i] = vals[i<<1] + vals[i<<1|1];
    }

    void build(int p) {
        while (p > 1) {
            p >>= 1;
            vals[p] = vals[p<<1] + vals[p<<1|1] + deltas[p];
        }
    }

    void apply(int p, int value) {
        vals[p] += value;
        if (p < n) deltas[p] += value;
    }

    void push(int p) {
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (deltas[i] != 0) {
                apply(i<<1, deltas[i]/2);
                apply(i<<1|1, deltas[i]/2);
                deltas[i] = 0;
            }
        }
    }

    void update(int l, int r, int value) {
        l += n, r += n;
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) apply(l++, value);
            if (r&1) apply(--r, value);
            value *= 2;
        }
        build(l0);
        build(r0 - 1);
    }

    // [l, r)
    int query(int l, int r) {
        l += n, r += n;
        push(l);
        push(r - 1);
        int res = 0;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += vals[l++];
            if (r&1) res += vals[--r];
        }
        return res;
    }
};