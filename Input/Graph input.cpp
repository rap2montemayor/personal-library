cin >> n >> m;
for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
}