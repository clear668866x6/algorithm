#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        int c, s;
        cin >> c >> s;
        mp[c] = max(mp[c], s);
    }

    for (int i = 1; i <= m; i++) {
        if (!mp[i])
            cout << "-1 ";
        else
            cout << mp[i] << ' ';
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