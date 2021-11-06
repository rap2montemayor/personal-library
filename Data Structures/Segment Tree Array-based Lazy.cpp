// Recursive, Array-based, Lazy Segment Tree
// 
// Segment tree that supports both O(log n) range queries and range updates.
//
// Notes:
// - Queries are [l, r]
// - The current vertex coveres [i, j]
// - The index of the current vertex is p
// - Update and query must be called with p=1, i=0, j=n-1. This is handled
//      automatically by setting their default values to -1, and checking for
//      them when they're called.
// - Works like a normal segment tree, but leaves a delta/lazy flag if a query
//      no longer needs to propagate further down a tree. Subsequent queries
//      will pick up that lazy flag and continue propagating changes when they
//      need to.
// - Tested on SPOJ HORRIBLE https://www.spoj.com/problems/HORRIBLE/

struct segtree {
    int n, vals[4*MAXN], deltas[4*MAXN];

    segtree(int n) : n(n) {
        build(1, 0, n-1);
    }

    void build(int p, int i, int j) {
        deltas[p] = 0;
        if (i == j)
            vals[p] = a[i];
        else {
            int k = (i+j) >> 1;
            build(p<<1, i, k);
            build(p<<1|1, k+1, j);
            pull(p);
        }
    }

    void pull(int p) {
        vals[p] = vals[p<<1] + vals[p<<1|1];
    }

    void push(int p, int i, int j) {
        if (deltas[p]) {
            vals[p] += (j - i + 1) * deltas[p];
            if (i != j) {
                deltas[p<<1] += deltas[p];
                deltas[p<<1|1] += deltas[p];
            }
            deltas[p] = 0;
        }
    }
    
    // Increases all elements in [l,r] by val
    void update(int l, int r, int val, int p=-1, int i=-1, int j=-1) {
        if (j == -1) p = 1, i = 0, j = n-1;
        push(p, i, j);
        if (l <= i and j <= r) {
            deltas[p] += val;
            push(p, i, j);
        } else if (r < i or j < l) {
            return;
        } else {
            int k = (i+j) >> 1;
            update(l, r, val, p<<1, i, k);
            update(l, r, val, p<<1|1, k+1, j);
            pull(p);
        }
    }
    
    // Gets the sum of elements in [l,r]
    int query(int l, int r, int p=-1, int i=-1, int j=-1) {
        if (j == -1) p = 1, i = 0, j = n-1;
        push(p, i, j);
        if (l <= i and j <= r)
            return vals[p];
        else if (r < i or j < l)
            return 0;
        else {
            int k = (i+j) >> 1;
            return query(l, r, p<<1, i, k) +
                query(l, r, p<<1|1, k+1, j);
        }
    }
};