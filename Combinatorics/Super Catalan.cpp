// ll MOD = 1e9+7;
// fac[]
// modpow()
// modinv()
ll supercat(ll a, ll b) {
    return fac[2*a] * fac[2*b] % MOD *
        modinv(fac[a+b]) % MOD * modinv(fac[a]) % MOD * modinv(fac[b]) % MOD;
}