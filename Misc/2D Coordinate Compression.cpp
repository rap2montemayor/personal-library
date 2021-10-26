bool compx(int l, int r) { return coords[l].first < coords[r].first; }
bool compy(int l, int r) { return coords[l].second < coords[r].second; }
void compress(int n, ii coords[]) {
    int sortedx[n], sortedy[n];
    for (int i = 0; i < n; ++i)
        sortedx[i] = sortedy[i] = i;
    sort(sortedx, sortedx+n, compx);
    sort(sortedy, sortedy+n, compy);
    int x = 0, y = 0,
        prevx = coords[sortedx[0]].first,
        prevy = coords[sortedy[0]].second;
    coords[sortedx[0]].first = coords[sortedy[0]].second = 0;
    for (int i = 1; i < n; ++i) {
        if (coords[sortedx[i]].first != prevx)
            ++x, prevx = coords[sortedx[i]].first;
        if (coords[sortedy[i]].second != prevy)
            ++y, prevy = coords[sortedy[i]].second;
        coords[sortedx[i]].first = x;
        coords[sortedy[i]].second = y;
    }
}