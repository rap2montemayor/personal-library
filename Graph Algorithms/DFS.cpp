// int n;
// vvi g;
vector<bool> vis(n);
void dfs(int u) {
    vis[u] = true;
    for (int v: g[u])
        if (not vis[v]) dfs(v);
}