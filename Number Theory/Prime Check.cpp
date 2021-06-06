bool isprime(ll n) {
    // sieve();
    for (int i = 0; primes[i]*primes[i] <= n; ++i)
        if (n % primes[i] == 0) return false;
    return true;
}