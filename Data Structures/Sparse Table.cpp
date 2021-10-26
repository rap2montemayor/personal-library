struct sparse_table {
    int st[MAXN][20] = {};
    sparse_table(int n, int a[]) {
        for (int i = 0; i < n; ++i)
            st[i][0] = a[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 0; i + (1<<j) <= n; ++i)
                st[i][j] = st[i][j-1] + st[i + (1<<(j-1))][j-1];
    }

    // [l,r)
    int query(int l, int r) {
        int ans = st[l][0];
        for (int j = 20; j >= 0; --j) {
            if ((1<<j) <= r-l) {
                ans += st[l][j];
                l += 1<<j;
            }
        }
        return ans;
    }
};