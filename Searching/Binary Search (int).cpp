bool obj(int m) {
    //
}

int find(int x) {
    int l = 0, r = n, m;
    while (r-l > 1) {
        m = (l+r) >> 1;
        if (obj(m)) l = m;
        else r = m;
    }
    return l;
}