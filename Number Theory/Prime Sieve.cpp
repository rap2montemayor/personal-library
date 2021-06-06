vector<bool> isprime(2e6, true);
vi primes;
void sieve() {
    int n = 2e6;
    isprime[0] = isprime[1] = false;
    for (ll i = 4; i < n; i += 2)
        isprime[i] = false;
    for (ll i = 3; i < n; i += 2)
        for (ll j = i*i; j < n; j += i)
            isprime[j] = false;
    for (ll i = 0; i < n; ++i)
        if (isprime[i]) primes.push_back(i);
}