// nxt() gives the next element
int nxt(int n) {
    return (n+1)%10;
}

// Returns the start mu and length l of the cycle
ii findcycle(int start) {
    int t = nxt(start), h = nxt(nxt(start)), mu, l;
    // Detects the cycle
    while (t != h)
        t = nxt(t), h = nxt(nxt(h));

    // Finds the start of the cycle
    mu = 0, h = start;
    while (t != h)
        t = nxt(t), h = nxt(h), ++mu;
    
    // Finds the length of the cycle
    l = 1, h = nxt(t);
    while (h != t)
        h = nxt(h), ++l;
    
    return {mu, l};
}