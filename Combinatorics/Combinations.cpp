// Consider using Pascal's triangle
// Requires fac and modpow
ll comb(ll n, ll r) {
    return fac[n] * modinv(fac[r] * fac[n - r] % MOD) % MOD;
}