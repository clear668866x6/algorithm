#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mp(m + 1);

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x;
        set<int> s;
        for (int j = 1; j <= x; j++) {
            cin >> y;
            s.insert(y);
        }

        for (auto y : s) {
            mp[y].push_back(i);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        map<int, int> mp2;
        for (auto z : mp[x]) {
            mp2[z]++;
        }

        for (auto z : mp[y]) {
            mp2[z]++;
            if (mp2[z] > 1) {
                ans++;
            }
        }

        cout << ans << '\n';
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