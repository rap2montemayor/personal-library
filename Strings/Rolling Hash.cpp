// Needs modification for uppercase characters
int rollhash(string &s, int p) {
    int res = 0, mult = 1;
    for (char c: s) {
        res = (res + (c-'a'+1)*mult) % MOD;
        mult = mult*p % MOD;
    }
    return res;
}
ii rollhash(string &s) { return {rollhash(s, 29), rollhash(s, 31)}; }