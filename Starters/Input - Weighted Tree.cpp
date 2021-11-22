cin >> n;
for (int i = 0; i < n-1; ++i) {
    int u, v, w; cin >> u >> v >> w;
    g[u-1].push_back({v-1, w});
    g[v-1].push_back({u-1, w});
}