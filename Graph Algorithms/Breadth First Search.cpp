// Breadth First Search
// Traveses a graph in a "breadth first" manner.

vector<bool> vis(MAXN);
void bfs(int start) {
    queue<int> q({start});
    vis[start] = true;

    while (not q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v: g[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            q.push(v);
        }
    }
}