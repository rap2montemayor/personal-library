void compress(int n, pair<int,int> coords[]) {
    int byx[n], byy[n];
    for (int i = 0; i < n; ++i)
        byx[i] = byy[i] = i;
    // apologies for the lambda
    sort(byx, byx+n, [coords](int l, int r) { coords[l].first < coords[r].first; });
    sort(byy, byy+n, [coords](int l, int r) { coords[l].second < coords[r].second; });
    int x = 0, y = 0,
        prevx = coords[byx[0]].first,
        prevy = coords[byy[0]].second;
    coords[byx[0]].first = coords[byy[0]].second = 0;
    for (int i = 1; i < n; ++i) {
        if (coords[byx[i]].first != prevx)
            ++x, prevx = coords[byx[i]].first;
        if (coords[byy[i]].second != prevy)
            ++y, prevy = coords[byy[i]].second;
        coords[byx[i]].first = x;
        coords[byy[i]].second = y;
    }
}