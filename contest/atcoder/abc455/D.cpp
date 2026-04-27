#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n + 1, 0);
    vector<int> ans(n + 1, 0), pre(n + 1, -1);
    map<int, int> mp;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (!mp[a]) {
            pre[b] = a;
            mp[a] = b;
        } else {
            pre[mp[a]] = -1;
            pre[b] = a;
            mp[a] = b;
        }
        d[a]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            int t = i;
            while (pre[t] != -1) {
                t = pre[t];
                ans[i]++;
            }
            ans[i]++;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
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