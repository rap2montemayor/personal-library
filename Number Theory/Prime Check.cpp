vi primes({2});
void sieve() {
    for (int i = 3; i < MAXN; i += 2) {
        if (isprime[i]) primes.push_back(i);
        for (long long j = i; i*j < MAXN; ++j)
            isprime[i*j] = false;
    }
}

// Call sieve first
bool isprime(int n) {
    for (int i = 0; primes[i]*primes[i] <= n; ++i)
        if (n % primes[i] == 0) return false;
    return true;
}