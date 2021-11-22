// Floyd-Warshall Algorithm
//
// All pairs shortest paths in O(|V|^3)
// Checks every pair of vertices (i, j), and checks whether the length of the
//      path between them can be improved by passing through k. Essentially DP.
//
// Notes:
// - Graph must be represented by an adjacency matrix.
// - Vertices not directly connected are represented with INF.

void fw() {
    for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        if (g[i][k] + g[k][j] < g[i][j])
            g[i][j] = g[i][k] + g[k][j];
}