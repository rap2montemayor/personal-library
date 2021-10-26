// Requires modinv
int catalan(int n) {
    return fac[2*n] * modinv(fac[n+1]) % MOD * modinv(fac[n]) % MOD;
}