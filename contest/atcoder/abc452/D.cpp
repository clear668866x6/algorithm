#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;

    map<int, set<int>> mp;

    for (int i = 1; i <= n; i++) {
        mp[s[i]].insert(i);
    }

    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        int lst = i;
        for (int j = 1; j <= m; j++) {
            auto it = mp[t[j]].lower_bound(lst);
            if (it == mp[t[j]].end()) {
                lst = n + 2;
                break;
            }
            lst = (*it) + 1;
        }
        ans += (lst - i - 1);
    }

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