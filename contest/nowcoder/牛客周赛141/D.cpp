#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    map<i64, int> mp;
    for (int i = 1; i <= n; i++) cin >> w[i], mp[w[i]]++;

    for (int i = 1; i <= n; i++) {
        i64 t = w[i];
        for (int j = 1; j <= 32; j++) {
            if (t > 1e9) break;
            if (j == w[i] && w[i] == t) {
                if (mp[j] >= 2) {
                    cout << "YES\n";
                    return;
                }
            } else if (j == w[i]) {
                if (mp[j] && mp[t]) {
                    cout << "YES\n";
                    return;
                }
            } else if (w[i] == t) {
                if (mp[j] && mp[t] >= 2) {
                    cout << "YES\n";
                    return;
                }
            } else if (j == t) {
                if (mp[j] >= 2) {
                    cout << "YES\n";
                    return;
                }
            } else {
                if (mp[j] && mp[t]) {
                    cout << "YES\n";
                    return;
                }
            }
            t = t * w[i];
        }
    }
    cout << "NO\n";
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