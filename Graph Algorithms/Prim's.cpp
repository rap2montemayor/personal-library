// typedef vector<tuple<int, int, int>> viii;
// vvii g;
viii prim(int start) {
    priority_queue<ii, vii, greater<ii>> q;
    q.push{{0, start}};
    vis[start] = true;

    viii res;
    while (not q.empty()) {
        int u = q.top().second;
        q.pop();

        for (ii &p: g[u]) {
            int v = p.first, w = p.second;
            if (vis[v]) continue;
            vis[v] = true;
            res.push_back({u, v, w});
            pq.push({w, v});
        }
    }
}