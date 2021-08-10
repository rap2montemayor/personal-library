int obj(int m) {
	// 
}

// Returns index of largest value
int find() {
    int l = -1, r = n, m;
    while (r-l > 1) {
        m = (l+r) >> 1;
        if (obj(m) < obj(m+1)) l = m;
        else r = m;
    }
    return l+1;
}