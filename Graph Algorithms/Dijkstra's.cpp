// const int INF = ~(1<<31);
// int n;
// vvii g;
vi dist(n, INF);
void dijkstra(int start) {
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