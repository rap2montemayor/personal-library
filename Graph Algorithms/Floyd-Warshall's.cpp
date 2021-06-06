// Note: This will modify the matrix
// int n;
// vvi g;
void fw() {
    for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        if (g[i][k] + g[k][j] < g[i][j])
            g[i][j] = g[i][k] + g[k][j];
}