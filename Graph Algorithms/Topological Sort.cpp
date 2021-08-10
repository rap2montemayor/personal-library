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