#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<i64> s(n + 1, 0);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    vector<int> f(n + 1, 0);
    map<i64, int> mp;
    for (int i = 1; i <= n; i++) mp[s[i]] = -1;
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i], f[i - 1]);
        if (mp[s[i]] != -1) {
            f[i] = max(f[i], f[mp[s[i]]] + 1);
        }
        mp[s[i]] = max(mp[s[i]], i);
    }

    cout << f[n] << '\n';
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