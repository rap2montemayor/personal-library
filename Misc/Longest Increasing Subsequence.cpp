// Longest Increasing Subsequence
//
// Gets the longest increasing subsequence of an array, a. The LIS is given as
// an array of indices.
//
// Notes:
// - This is done with a combination of DP and binary search.
// - dp[i] contains the index of the last element that an increasing
//      subsequence of length i+1 would contain.
// - dp[0] is initialized as a[0], while the rest of dp is initialized as INF.
// - Values in dp will always be increasing as it is updated with values from
//      a. Hence, the position of the next value of a can be found using
//      binary search.
// - Binary search is handled by upper_bound(), which gives the last position
//      that an element can be inserted into without breaking the ordering.
// - par[i] contains a pointer to the previous element before a[i] if it were
//      included in an increasing subsequence.
// - If only the length of an LIS is needed, and not an actual LIS, len may be
//      returned instead of constructlis()

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