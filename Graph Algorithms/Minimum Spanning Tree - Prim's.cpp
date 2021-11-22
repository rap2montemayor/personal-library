// Prim's Algorithm
//
// Minimum spanning tree of a weighted undirected graph in O(|E| log(|V|)).
// Tested on SPOJ MST: https://www.spoj.com/problems/MST/

typedef tuple<int,int,int> iii;
typedef vector<iii> viii;
vb vis(MAXN);
vii edges(MAXN, {-1, INF}); // {v, w}
viii prim(int start=0) {
    set<ii> q({{0, start}}); // {w, v}
    edges[start] = {start, 0};
    vis[start] = true;

    viii mst; // {u, v, w}
    while (not q.empty()) {
        int u = q.begin()->second;
        vis[u] = true;
        q.erase(q.begin());

        if (u != start)
            mst.push_back({u, edges[u].first, edges[u].second});

        for (ii& p: g[u]) {
            int v = p.first, w = p.second;
            if (vis[v] or w >= edges[v].second) continue;
            q.erase({edges[v].second, v});
            q.insert({w, v});
            edges[v] = {u, w};
        }
    }
    return mst;
}