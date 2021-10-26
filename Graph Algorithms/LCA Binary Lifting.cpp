// Requires binary lifting
// returns {LCA, dist}
ii lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int dist = dep[v] - dep[u];
    for (int j = 19; j >= 0; --j)
        if (dist & (1<<j)) v = par[v][j];
    if (u == v) return dist;
    for (int j = 19; j >= 0; --j) {
        if (par[u][j] != par[v][j]) {
            u = par[u][j];
            v = par[v][j];
            dist += 2<<j;
        }
    }
    return {par[u][v], dist+2};
}