// Articulation Points and Bridges
//
// Articulation points and bridges in O(|V|+|E|).
// Runs DFS and maintains entry times and lowlinks for each vertex visited.
//      The lowlink low[i] keeps track of the highest ancestor a node or one
//      of its descendants has a back edge to.
// For the current edge (u, v) being checked in the DFS:
//      - if v doesn't connect back to u or higher, then (u, v) is a bridge.
//      - if v doesn't connect back to a node higher than u, and u isn't the
//          DFS root, then u is an articulation point.
// If the root has more than one child, it is also an articulation point.

int entry[MAXN], low[MAXN], timer = 0;
set<int> cutpoints;
set<ii> bridges;
vector<bool> vis(MAXN);
void dfscuts(int u, int p) {
    vis[u] = true;
    entry[u] = low[u] = ++timer;
    int children = 0;
    for (int v: g[u]) {
        if (v == p) continue;
        if (vis[v])
            low[u] = min(low[u], entry[v]);
        else {
            dfscuts(v, u);
            low[u] = min(low[u], low[v]);
            if (entry[u] < low[v])
                bridges.insert({u, v});
            if (entry[u] <= low[v] and p != -1)
                cutpoints.insert(u);
            ++children;
        }
    }
    if (p == -1 and children > 1)
        cutpoints.insert(u);
}

void getcuts() {
    fill(entry, entry+MAXN, -1);
    fill(low, low+MAXN, -1);
    fill(vis.begin(), vis.end(), false);
    cutpoints.clear();
    bridges.clear();
    timer = 0;
    for (int i = 0; i < n; ++i)
        if (not vis[i]) dfscuts(i, -1);
}