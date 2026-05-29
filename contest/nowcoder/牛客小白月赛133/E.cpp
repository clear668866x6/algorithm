#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> d[i];

    vector<array<int, 2>> c;
    for (int i = 1; i <= n; i++) {
        c.push_back({d[i], i});
    }
    sort(c.begin(), c.end(), greater());

    if (l == 1) {
        cout << "-1\n";
        return;
    }

    if (c[n - l - 1][0] < 2) {
        cout << "-1\n";
        return;
    }

    deque<int> q;

    vector<array<int, 2>> ans;

    for (int i = 1; i <= l; i++) {
        if (i == 1) {
            ans.push_back({c[0][1], c.back()[1]});
        } else {
            q.push_back(c.back()[1]);
        }
        c.pop_back();
    }

    while (!q.empty() && !c.empty()) {
        auto [dd, ver] = c.back();
        c.pop_back();
        int t = dd - 1;

        while (t--) {
            if (q.empty()) {
                break;
            }
            ans.push_back({q.front(), ver});
            q.pop_front();
        }
        q.push_back(ver);
    }

    if (ans.size() != n - 1) {
        cout << "-1\n";
    } else {
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}