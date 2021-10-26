vi primes({2});
vector<bool> isprime(MAXN, true);
void sieve() {
    isprime[0] = isprime[1] = false;
    for (int i = 4; i < MAXN; i += 2)
        isprime[i] = false;
    for (int i = 3; i < MAXN; i += 2) {
        if (isprime[i]) primes.push_back(i);
        for (int j = i; i*j < MAXN; ++j)
            isprime[i*j] = false;
    }
}