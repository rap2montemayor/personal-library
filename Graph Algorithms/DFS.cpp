vector<bool> vis(MAXN);
void dfs(int u) {
    vis[u] = true;
    for (int v: g[u])
        if (not vis[v]) dfs(v);
}