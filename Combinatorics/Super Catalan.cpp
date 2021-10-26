// Requires fac and modinv
int supercat(int a, int b) {
    return fac[2*a] * fac[2*b] % MOD *
        modinv(fac[a+b]) % MOD * modinv(fac[a]) % MOD * modinv(fac[b]) % MOD;
}