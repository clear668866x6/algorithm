#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> mp(m + 1, 0), mp2(m + 1, 0);
    vector<string> s1(n + 1), s2(n + 1);
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i] >> a[i] >> b[i];
        mp[a[i]] = max(mp[a[i]], b[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (mp[a[i]] == b[i] && !mp2[a[i]]) {
            cout << s1[i] << ' ' << s2[i] << ' ' << a[i] << ' ' << b[i] << "\n";
            mp2[a[i]] = 1;
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