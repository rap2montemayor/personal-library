int dep[MAXN], par[MAXN][20];
void dfsbinlift(int u, int d, int p) {
    fill(par[i], par[i]+20, -1);
    par[u][0] = p, dep[u] = d;
    for (int v: g[u])
        if (par[v][0] == -1)
            dfsbinlift(v, d+1, u);
}

void process(int start) {
    dfsbinlift(start, 0, start);
    for (int j = 1; j < 20; ++j)
        for (int v = 0; v < n; ++v)
            par[v][j] = par[par[v][j-1]][j-1];
}

int getancestor(int v, int k) {
    for (int j = 0; j < 20; ++j)
        if (k & (1<<j)) v = par[v][j];
    return v;
}