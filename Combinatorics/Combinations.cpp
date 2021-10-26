// Consider using Pascal's triangle
// Requires fac and modpow
int comb(int n, int r) {
    return fac[n] * modinv(fac[r] * fac[n - r] % MOD) % MOD;
}