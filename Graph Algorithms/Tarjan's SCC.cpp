int entry[MAXN], low[MAXN], timer = 0;
vector<bool> vis(MAXN), stacked(MAXN);
void dfs(int u, vi &s, vvi &scc) {
    vis[u] = stacked[u] = true;
    entry[u] = low[u] = ++timer;
    s.push_back(u);
    for (int v: g[u]) {
        if (vis[v] and not stacked[v]) continue;
        if (not vis[v]) dfs(v, s, scc);
        low[u] = min(low[u], low[v]);
    }

    if (low[u] == entry[u]) {
        int last;
        scc.push_back(vi());
        do {
            last = s.back();
            s.pop_back();
            scc.back().push_back(last);
            stacked[last] = false;
        } while (last != u);
    }
}

vvi tarjan() {
    fill(entry, entry+MAXN, -1);
    fill(low, low+MAXN, -1);
    vvi scc;
    vi s;
    for (int i = 0; i < n; ++i)
        if (not vis[i]) dfs(i, s, scc);
    return scc;
}