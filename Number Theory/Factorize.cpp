vi primes({2});
void sieve() {
    vector<bool> isprime(MAXN, true);
    for (int i = 3; i < MAXN; i += 2) {
        if (isprime[i]) primes.push_back(i);
        for (long long j = i; i*j < MAXN; ++j)
            isprime[i*j] = false;
    }
}

// Call sieve first
vi factorize(int n) {
    vi factors;
    long long idx = 0, p = primes[0];
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