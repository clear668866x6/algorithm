#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> y0, y1;
    vector<int> mp(3e6 + 10, 0);

    int mx = -1e9, mn = 1e9;
    int del = 1e6;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == 0) {
            y0.push_back(x);
        } else if (y == 1) {
            y1.push_back(x);
        } else {
            mp[x + del] = 1;
            mx = max(mx, x);
            mn = min(mn, x);
        }
    }

    if (mx < mn || y0.empty() || y1.empty()) {
        cout << -1;
        return;
    }

    sort(y0.begin(), y0.end());
    y0.erase(unique(y0.begin(), y0.end()), y0.end());
    sort(y1.begin(), y1.end());
    y1.erase(unique(y1.begin(), y1.end()), y1.end());

    int t0 = y0.size(), t1 = y1.size();

    struct E {
        int x, y, z;
        bool operator<(const E &t) const {
            if (y == t.y) return x < t.x;
            return y < t.y;
        }

        bool operator==(const E &t) const {
            return x == t.x && y == t.y && z == t.z;
        }
    };

    vector<E> ans;

    for (int i = 0; i < t1; i++) {
        int mn1 = 2 * y1[i] - mx, mx1 = 2 * y1[i] - mn;
        auto it1 = lower_bound(y0.begin(), y0.end(), mn1);
        auto it2 = prev(upper_bound(y0.begin(), y0.end(), mx1));
        for (auto it = it1; it <= it2; it++) {
            int t = 2 * y1[i] - *it;
            if (mp[t + del]) {
                ans.push_back({*it, y1[i], t});
            }
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    if (ans.empty())
        cout << -1;
    else {
        for (auto [x, y, z] : ans) {
            cout << "[" << x << ", 0] [" << y << ", 1] [" << z << ", 2]\n";
        }
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