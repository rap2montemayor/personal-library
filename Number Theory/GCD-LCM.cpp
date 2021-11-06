// Notes:
// __gcd(a, b) is available in C++14
// gcd(a, b) is available in C++17
// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }