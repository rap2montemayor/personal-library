// Kahn's Algorithm
//
// Topological sorting in O(|V|+|E|).
// Constructs a topological sorting starting from vertices with indegrees of 0.
//      Vertices currently being processed are "removed" and the indegrees of
//      adjacent vertices are decreased. Vertices whose indegrees become 0 are
//      queued for processing.
 
vi toposort() {
    queue<int> q;
    int degs[n];
    for (int i = 0; i < n; ++i) {
        degs[i] = g[i].size();
        if (degs[i] == 0) q.push(i);
    }

    vi topo;
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v: g[u])
            if (--degs[v] == 0)
                q.push(v);
    }
    
    return topo;
}