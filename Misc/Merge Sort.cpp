// Also returns inversions
int mergesort(vi &a, int l=-1, int r=-1) {
    if (l == -1) l = 0, r = a.size();
    int ans = 0, m = (l+r) / 2;
    if (r-l > 1) ans += mergesort(a, l, m) + mergesort(a, m, r);

    int left[m-l+1], right[r-m+1];
    left[m-l] = 2e9, right[r-m] = 2e9;
    for (int i = l; i < m; ++i) left[i-l] = a[i];
    for (int i = m; i < r; ++i) right[i-m] = a[i];

    int i = 0, j = 0, k = l;
    while (k < r)
        if (left[i] < right[j]) a[k++] = left[i++];
        else a[k++] = right[j++], ans += left[i] != 2e9 ? m-l-i : 0;
    return ans;
}