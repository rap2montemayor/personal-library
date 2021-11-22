// Lowest Common Ancestor - Binary Lifting
//
// Lowest common ancestor queries in O(log |V|)
// Uses the binary lifting table to look for the LCA of two vertices a la binary
//      search. The vertices' depths must be matched first.

// returns {LCA, dist}
ii lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int dist = dep[v] - dep[u];
    for (int j = 19; j >= 0; --j)
        if (dist & (1<<j)) v = par[v][j];
    if (u == v) return {u, dist};
    for (int j = 19; j >= 0; --j) {
        if (par[u][j] != par[v][j]) {
            u = par[u][j];
            v = par[v][j];
            dist += 2<<j;
        }
    }
    return {par[u][0], dist+2};
}