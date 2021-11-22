// Bellman-Ford Algorithm
//
// Single source shortest paths in O(|V||E|). Negative cycles can be detected.
// Distances are initialized with INF, except for the source vertex which is
//      initialized as 0. The algorithm goes through every edge (u, v) and
//      attempts to improve dist[v]. This is repeated n-1 times.
//
// Notes:
// - The algorithm may be stopped early if no changes occur.
// - A shortest path can be reconstructed by keeping track of the "parent"
//      vertex when distances are being updated.
// - Negative cycles can be detected if some distance can still be improved
//      even further after calculating their distances.

int dist[MAXN];
void bellmanford(int s) {
    fill(dist, dist+MAXN, INF);
    dist[s] = 0;
    for (int i = 0; i < n-1; ++i)
        for (int u = 0; u < n; ++u)
            for (ii &p: g[u]) {
                int v = p.first, w = p.second;
                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
}

bool negcycle() {
    for (int u = 0; u < n; ++u)
        for (ii &p : g[u]) {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v])
                return true;
        }
    return false;
}