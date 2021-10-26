int entry[MAXN], low[MAXN], timer = 0;
vector<bool> vis(MAXN);
void dfsbridges(int u, int p, set<ii> &bridges) {
    vis[u] = true;
    entry[u] = low[u] = timer++;
    for (int v: g[u]) {
        if (v == p) continue;
        if (vis[v])
            low[u] = min(low[u], entry[v]);
        else {
            dfsbridges(v, u, bridges);
            low[u] = min(low[u], low[v]);
            if (entry[u] < low[v])
                bridges.insert({u, v});
        }
    }
}

set<ii> getbridges() {
    fill(entry, entry+MAXN, -1);
    fill(low, low+MAXN, -1);
    set<ii> bridges;
    for (int i = 0; i < n; ++i)
        if (not vis[i]) dfsbridges(i, -1, bridges);
    return bridges;
}