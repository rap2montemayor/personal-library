ll fac[2000001];
void init_fac() {
    fac[0] = 1;
    for (ll i = 1; i <= 2e6; i++) 
        fac[i] = fac[i-1] * i % MOD;
}