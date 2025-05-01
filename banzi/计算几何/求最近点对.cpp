void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> w[i].first >> w[i].second;

    sort(w + 1, w + 1 + n);

    set<PII> s = {{w[1].second, w[1].first}};
    int j = 1;

    FOR(i, 2, n) {
        int dd = ceil(sqrt(d));
        while (j < i && w[j].first < w[i].first - dd) {
            s.erase({w[j].second, w[j].first});
            j++;
        }
        auto l = s.lower_bound({w[i].second - dd, 0});
        auto r = s.upper_bound({w[i].second + dd, 0});
        for (auto it = l; it != r; ++it) {
            d = min(d, dist({it->second, it->first}, w[i]));
        }
        s.insert({w[i].second, w[i].first});
    }
    cout << d << endl;
}
