int countfactors(ll n) {
    int ans = 0;
    for (ll i = 1; i*i <= n; ++i) {
        if (n % i == 0) ans += 2;
        if (i*i == n) --ans;
    }
    return ans;
}