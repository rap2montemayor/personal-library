// Recursive, Array-based Segment Tree
// 
// Range queries and point updates in O(log n). Constructed in O(n logn).
// Recursively builds a binary tree that stores the results of queries on the
//      original array's halves, quarters, eighths, etc. Queries on any range
//      can be constructed with the largest segments that fill up the range.
//
// Notes:
// - Queries are [l, r]
// - Queries and updates require the following additional information:
//      - The range of the current vertex [i, j]
//      - The index of the current vertex p
// - Tested on SPOJ FENTREE https://www.spoj.com/problems/FENTREE/

struct segtree {
    int n, vals[4*MAXN];
    
    segtree(int n) : n(n) {
        build(1, 0, n-1);
    }

    void build(int p, int i, int j) {
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
    
    // Increases the element in idx by val
    void update(int idx, int val, int p=-1, int i=-1, int j=-1) {
        if (j == -1) p = 1, i = 0, j = n-1;
        if (idx <= i and j <= idx)
            vals[p] += val;
        else if (idx < i or j < idx)
            return;
        else {
            int k = (i+j) >> 1;
            update(idx, val, p<<1, i, k);
            update(idx, val, p<<1|1, k+1, j);
            pull(p);
        }
    }
    
    // Gets the sum of elements in [l,r]
    int query(int l, int r, int p=-1, int i=-1, int j=-1) {
        if (j == -1) p = 1, i = 0, j = n-1;
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