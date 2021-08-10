// sort(v.begin(), v.end(), comp);
bool comp(int a, int b) {
    return a < b;
}

// set<int, comp> my_set;
struct comp {
    bool operator() (const int& a, const int& b) {
        return a < b;
    }
};