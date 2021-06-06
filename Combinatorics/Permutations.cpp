// ll MOD = 1e9+7;
// fac[]
// modpow()
// modinv()
ll perm(ll n, ll r) {
    return fac[n] * modinv(fac[n-r]) % MOD;
}
