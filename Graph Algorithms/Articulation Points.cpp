int entry[MAXN], low[MAXN], vis[MAXN] = {} timer = 0;
void dfs(int u, int p, set<int> &cutpoints) {
    vis[u] = true;
    entry[u] = low[u] = ++timer;
    int children = 0;
    for (int v: g[u]) {
        if (v == p) continue;
        if (vis[v])
            low[u] = min(low[u], entry[v]);
        else {
            dfs(v, u, cutpoints);
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
    memset(entry, -1, sizeof(entry));
    memset(low, -1, sizeof(low));
    set<int> cutpoints;
    for (int i = 0; i < n; ++i)
        if (not vis[i]) dfs(i, -1, cutpoints);
    return cutpoints;
}