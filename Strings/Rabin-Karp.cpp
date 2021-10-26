// Find occurences of s2 in s1
vi rabinkarp(string &s1, string &s2) {
    vii h1(s1.size()+1);
    ii h2 = rollhash(s2);

    int m1 = 1, m2 = 1;
    for (int i = 0; i < s1.size(); ++i) {
        h1[i+1].first = h1[i].first + (s1[i]-'a'+1)*m1 % MOD;
        h1[i+1].second = h1[i].second + (s1[i]-'a'+1)*m2 % MOD;
        m1 = m1*29 % MOD, m2 = m2*31 % MOD;
    }
    
    vi res;
    for (int i = s2.size(); i < s1.size(); ++i) {
        ii cur = h1[i];
        cur.first -= h1[i-s2.size()].first;
        cur.second -= h1[i-s2.size()].second;
        if (h2 == cur)
            res.push_back(i-s2.size());
        h2.first = h2.first * 29 % MOD;
        h2.second = h2.second * 31 % MOD;
    }
    return res;
}