// int n;
// vvi g;
cin >> n;
g.resize(n);
for (int i = 0; i < n-1; ++i) {
    int u, v, w; cin >> u >> v >> w;
    --u, --v;
    g[u].push_back({v, w});
    g[v].push_back({v, w}); // Remove for digraph
}