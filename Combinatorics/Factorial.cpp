// ll MOD = 1e9+7;
ll fac[200000];
void init_fac() {
    fac[0] = 1;
    for (ll i = 1; i < 2e5; i++) 
        fac[i] = fac[i-1] * i % MOD;
}