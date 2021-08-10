int dep[MAXN], par[MAXN][20];
void dfs(int u, int d, int p) {
    par[u][0] = p, dep[u] = d;
    for (int v: g[u])
        if (par[v][0] == -1)
            dfs(v, d+1, u);
}

void process(int start) {
    memset(par, -1, sizeof(par));
    dfs(start, 0, start);
    for (int j = 1; j < 20; ++j)
        for (int v = 0; v < n; ++v)
            par[v][j] = par[par[v][j-1]][j-1];
}

int getancestor(int v, int k) {
    for (int j = 0; j < 20; ++j)
        if (k & (1<<j)) v = par[v][j];
    return v;
}