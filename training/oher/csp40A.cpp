#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> s(m + 1), t(m + 1);

    for (int i = 1; i <= m; i++) {
        int x, y, t = 0;
        cin >> x;
        while (x--) {
            cin >> y;
            s[i].push_back(y);
            t ^= a[y];
        }
        s[i].push_back(t);
    }

    for (int i = 1; i <= m; i++) {
        int x, y, p = 0;
        cin >> x;
        while (x--) {
            cin >> y;
            p ^= a[y];
            t[i].push_back(y);
        }
        t[i].push_back(p);
    }

    for (int i = 1; i <= m; i++) {
        int t1 = 0, t2 = 0;
        vector<int> c1, c2;
        for (int j = 0; j < (int)s[i].size() - 1; j++) c1.push_back(s[i][j]);
        for (int j = 0; j < (int)t[i].size() - 1; j++) c2.push_back(t[i][j]);
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        if (s[i].back() == t[i].back()) {
            if (c1 != c2) {
                cout << "wrong\n";
            } else {
                cout << "correct\n";
            }
        } else {
            if (c1 != c2) {
                cout << "correct\n";
            } else {
                cout << "wrong\n";
            }
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