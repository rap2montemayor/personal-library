// Dijkstra's Algorithm
//
// Single source shortest paths in O(E+|V|lg(|V|)). Weights must be nonnegative.
// Works similarly to BFS, but prioritizes paths of smaller length. Essentially
//      a greedy algorithm.
//
// Notes:
// - Shortest paths may be reconstructed by keeping track of the "parent"
//      vertex when distances are being updated.

int dist[MAXN];
void dijkstra(int start) {
    fill(dist, dist+MAXN, INF);
    priority_queue<ii> q;
    q.push({0, start});
    dist[start] = 0;

    while (not q.empty()) {
        int u = q.top().second, d = -q.top().first;
        q.pop();

        for (ii &p: g[u]) {
            int v = p.first, w = p.second;
            if (dist[v] < d+w) continue;
            dist[v] = d+w;
            q.push({-(d+w), v});
        }
    }
}