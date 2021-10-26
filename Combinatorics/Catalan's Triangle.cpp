int cat[2001][2001] = {};
void initcat() {
    for (int i = 1; i <= 2000; ++i) {
        cat[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            cat[i][j] = (cat[i-1][j] + cat[i][j-1]) % MOD;
    }
}