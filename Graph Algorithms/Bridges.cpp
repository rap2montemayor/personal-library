int entry[MAXN], low[MAXN], timer = 0;
bool vis(MAXN);
void dfs(int u, int p, set<pair<int, int>> &bridges) {
    vis[u] = true;
    entry[u] = low[u] = timer++;
    for (int v: g[u]) {
        if (v == p) continue;
        if (vis[v])
            low[u] = min(low[u], entry[v]);
        else {
            dfs(v, u, bridges);
            low[u] = min(low[u], low[v]);
            if (entry[u] < low[v])
                bridges.insert({u, v});
        }
    }
}

set<pair<int, int>> getbridges() {
    fill(entry, entry+MAXN, -1);
    fill(low, low+MAXN, -1);
    set<ii> bridges;
    for (int i = 0; i < n; ++i)
        if (not vis[i]) dfs(i, -1, bridges);
    return bridges;
}