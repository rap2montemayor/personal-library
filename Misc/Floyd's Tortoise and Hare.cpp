int nxt(int n) {
    //
}
// {start, length}
pair<int, int> findcycle(int start) {
    int t = nxt(start), h = nxt(nxt(start)), mu, l;
    while (t != h) t = nxt(t), h = nxt(nxt(h));
    mu = 0, h = start;
    while (t != h) t = nxt(t), h = nxt(h), ++mu;
    l = 1, h = nxt(t);
    while (h != t) h = nxt(h), ++l;
    return {mu, l};
}