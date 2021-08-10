// Requires fac and modinv
ll perm(ll n, ll r) {
    return fac[n] * modinv(fac[n-r]) % MOD;
}