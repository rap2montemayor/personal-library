int fac[MAXN] = {1};
void initfac() {
    for (int i = 1; i <= MAXN; i++) 
        fac[i] = fac[i-1] * i % MOD;
}