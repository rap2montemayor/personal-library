// const int INF = ~(1<<31);
// int n;
// vi dist;
// vvii g; 
void bellmanford(int s) {
    for (int u = 0; u < n; ++u)
        dist[u] = INF;
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