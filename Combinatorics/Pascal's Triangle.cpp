// ll MOD = 1e9+7;
ll comb[2000][2000] = {0};
void initcomb() {
    comb[0][0] = 1;
    for (int i = 1; i < 2000; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
    }
}