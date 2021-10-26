int dp[MAXN] = {}, par[MAXN] = {};
vi constructlis(int idx) {
    vi lis({idx});
    while (par[idx] != idx)
        lis.push_back(idx = par[idx]);
    reverse(lis.begin(), lis.end());
    return lis;
}
 
bool liscomp(int l, int r) { return r == INF or a[l] <= a[r]; }
vi getlis() {
    fill(dp+1, dp+n, INF);
    for (int i = 1; i < n; ++i) {
        int pos = upper_bound(dp, dp+n, i, liscomp) - dp;
        dp[pos] = i;
        if (pos > 0) par[i] = dp[pos-1];
        else par[i] = i;
    }
    int len = 0;
    for (int i = 0; i < n; ++i)
        if (dp[i] != INF) len = dp[i];
    return constructlis(len);
}