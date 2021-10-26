int entry[MAXN], low[MAXN], timer = 0;
vector<bool> vis(MAXN);
void dfscutpoints(int u, int p, set<int> &cutpoints) {
    vis[u] = true;
    entry[u] = low[u] = ++timer;
    int children = 0;
    for (int v: g[u]) {
        if (v == p) continue;
        if (vis[v])
            low[u] = min(low[u], entry[v]);
        else {
            dfscutpoints(v, u, cutpoints);
            low[u] = min(low[u], low[v]);
            if (entry[u] <= low[v] and p != -1)
                cutpoints.insert(u);
            ++children;
        }
    }
    if (p == -1 and children > 1)
        cutpoints.insert(u);
}

set<int> getcutpoints() {
    fill(entry, entry+MAXN, -1);
    fill(low, low+MAXN, -1);
    set<int> cutpoints;
    for (int i = 0; i < n; ++i)
        if (not vis[i]) dfscutpoints(i, -1, cutpoints);
    return cutpoints;
}