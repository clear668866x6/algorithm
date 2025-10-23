#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
using PII = pair<int, int>;
#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
constexpr int N = 2e5 + 10;

int n;
PII w[N];
int d = LLONG_MAX;

int dist(PII a, PII b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}