// Longest Increasing Subsequence
//
// Longest increasing subsequence of an array in O(n logn).
// dp[i] contains the index of the last element that an increasing
//      subsequence of length i+1 would contain. For each element in the array,
//      its position in dp is found using binary search.
//
// Notes:
// - LIS is given as an array of indices
// - Combines DP and binary search.
// - dp[0] is initialized as 0, while the rest of dp is initialized as INF.
// - Values in dp will always be increasing as it is updated with new values.
//      Hence, binary search can be used to find the position of new values.

int dp[MAXN] = {}, par[MAXN];
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
    int len = 1;
    for (int i = 1; i < n; ++i) {
        int pos = upper_bound(dp, dp+n, i, liscomp) - dp;
        dp[pos] = i;
        len = max(len, pos);
        if (pos > 0) par[i] = dp[pos-1];
        else par[i] = i;
    }
    return constructlis(len);
}