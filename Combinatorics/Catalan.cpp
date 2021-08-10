// Requires modinv
ll catalan(ll n) {
    return fac[2*n] * modinv(fac[n+1]) % MOD * modinv(fac[n]) % MOD;
}