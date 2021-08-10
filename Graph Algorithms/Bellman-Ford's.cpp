vi dist(MAXN, INF);
void bellmanford(int s) {
    dist[s] = 0;
    for (int i = 0; i < n-1; ++i)
        for (int u = 0; u < n; ++u)
            for (ii &p: g[u])
                if (dist[u] + p.second < dist[p.first])
                    dist[p.first] = dist[u] + p.second;
}

bool negcycle() {
    for (int u = 0; u < n; ++u)
        for (ii &p : g[u])
            if (dist[p.first] > dist[u] + p.second)
                return true;
    return false;
}