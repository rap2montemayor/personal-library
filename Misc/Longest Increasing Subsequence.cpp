// Note: returns an array of indices
bool obj(int idx, int m, vi &a) { return m != INF and a[idx] >= a[m]; }
int find(int idx, vi &a, vi &d) {
    int l = 0, r = d.size(), m;
    while (r - l > 1) {
        m = (l+r) / 2;
        if (obj(idx, d[m], a)) l = m;
        else r = m;
    }
    return l;
}

vi construct_lis(vi &d, vi &p) {
    int idx;
    for (int i = 0; i < d.size(); ++i)
        if (d[i] != INF) idx = d[i];
    vi res({idx});
    while (p[idx] != idx) {
        idx = p[idx];
        res.push_back(idx);
    }
    reverse(res.begin(), res.end());
    return res;
}

vi lis(vi &a) {
    vi d(a.size(), INF), p(a.size());
    d[0] = 0;
    for (int i = 1; i < a.size(); ++i) {
        int pos = find(i, a, d);
        if (a[i] > a[d[pos]]) ++pos;
        d[pos] = i;
        if (pos > 0) p[i] = d[pos-1];
        else p[i] = i;
    }
    return construct_lis(d, p);
}