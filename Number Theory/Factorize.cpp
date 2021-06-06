vi factorize(ll n) {
    // sieve();
    vi factors;
    ll idx = 0, p = primes[0];
    while (p*p <= n) {
        while (n % p == 0) {
            n /= p;
            factors.push_back(p);
        }
        p = primes[++idx];
    }
    if (n != 1) factors.push_back(n);
    return factors;
}