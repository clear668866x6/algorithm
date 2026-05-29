#include <bits/stdc++.h>
#include <istream>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> c[i];

    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++) d[i] = 1;

    vector<int> mp(m + 1, 0);
    for (int cnt = 1; cnt <= k; cnt++) {
        int x, l, r;
        cin >> x >> l >> r;

        vector<int> e, f;

        for (int i = l; i <= r; i++) {
            if (d[i] == x) {
                e.push_back(i);
                d[i] = cnt + 1;
            }
        }

        int cnt2 = 0;

        for (auto y : e) {
            f.push_back(c[y]);
            if (!mp[c[y]]) {
                cnt2++;
            }
            mp[c[y]]++;
        }

        cout << cnt2 << ' ';

        for (auto y : e) mp[c[y]]--;

        if (!f.empty()) {
            f.erase(unique(f.begin(), f.end()), f.end());
        }

        cout << f.size() << '\n';
    }
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