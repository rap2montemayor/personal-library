// Note if n, r are small, it's better to calculate with Pascal's triangle
// ll MOD = 1e9+7;
// fac[]
// modpow()
// modinv()
ll comb(ll n, ll r) {
    return fac[n] * modinv(fac[r] * fac[n - r] % MOD) % MOD;
}