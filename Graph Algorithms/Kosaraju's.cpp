// Note: needs g and rev
vi order;
bool vis[MAXN] = {};
void dfs1(int u) {
    vis[u] = true;
    for (int v: g[u])
        if (not vis[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u, vvi &scc) {
    vis[u] = true;
    scc.back().push_back(u);
    for (int v: rev[u])
        if (not vis[v]) dfs2(v, scc);
}

vvi kosaraju() {
    for (int i = 0; i < n; ++i)
        if (not vis[i]) dfs1(i);

    vvi scc;
    fill(vis, vis+MAXN, false);
    reverse(order.begin(), order.end());
    for (int i: order) {
        if (not vis[i]) {
            scc.push_back(vi());
            dfs2(i, scc);
        }
    }
    return scc;
}