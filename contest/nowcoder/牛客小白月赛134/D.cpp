#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> r(n, 0), b(m, 0);
    set<i64> s, s2;
    for (int i = 0; i < n; i++) cin >> r[i], s2.insert(r[i]);
    for (int i = 0; i < m; i++) cin >> b[i], s.insert(b[i]);

    i64 rd = 2e9, bl = 2e9;

    for (int i = 0; i < n; i++) rd = min(rd, abs(r[i]));
    for (int i = 0; i < m; i++) bl = min(bl, abs(b[i]));

    i64 mn = 2e9;

    sort(r.begin(), r.end());
    sort(b.begin(), b.end());

    for (auto x : r) {
        auto it = s.lower_bound(x);
        if (it != s.end()) {
            mn = min(mn, abs(*it - x));
        }
        if (it != s.begin()) {
            it--;
            mn = min(mn, abs(*it - x));
        }
    }

    for (auto x : b) {
        auto it = s2.lower_bound(x);
        if (it != s2.end()) {
            mn = min(mn, abs(*it - x));
        }
        if (it != s2.begin()) {
            it--;
            mn = min(mn, abs(*it - x));
        }
    }

    i64 ans = min({rd + mn + min(mn + rd, bl), bl + mn + min(mn + bl, rd)});

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}