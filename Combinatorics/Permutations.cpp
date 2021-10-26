// Requires fac and modinv
int perm(int n, int r) {
    return fac[n] * modinv(fac[n-r]) % MOD;
}