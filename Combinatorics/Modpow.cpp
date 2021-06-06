// ll MOD = 1e9+7;
ll modpow(ll n, ll x) {
    ll res = 1;
    while (x) {
        if (x & 1) res = (res * n) % MOD;
        x >>= 1, n = (n * n) % MOD;
    }
    return res;
}