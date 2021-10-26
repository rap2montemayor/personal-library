vi factorize(int n) {
    vi factors;
    for (int i = 2; i*i <= n; ++i) {
        while (n%i == 0) {
            n /= i;
            factors.push_back(i);
        }
    }
    return factors;
}