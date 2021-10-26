int modpow(int n, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = (res * n) % MOD;
        x >>= 1, n = (n * n) % MOD;
    }
    return res;
}