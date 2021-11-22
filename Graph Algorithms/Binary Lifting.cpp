// Binary Lifting
//
// Kth ancestor queries in O(log n).
// Given a tree, creates a table that stores each vertex's 2^ith ancestor a la
//      sparse table. A vertex's kth ancestor can be queried in O(log n) time by
//      breaking down k into powers of two.

int dep[MAXN], par[MAXN][20];
void dfslift(int u, int d, int p) {
    fill(par[i], par[i]+20, -1);
    par[u][0] = p, dep[u] = d;
    for (int v: g[u])
        if (par[v][0] == -1)
            dfslift(v, d+1, u);
}

void process(int start) {
    dfslift(start, 0, start);
    for (int j = 1; j < 20; ++j)
        for (int v = 0; v < n; ++v)
            par[v][j] = par[par[v][j-1]][j-1];
}

int getancestor(int v, int k) {
    for (int j = 0; j < 20; ++j)
        if (k & (1<<j)) v = par[v][j];
    return v;
}