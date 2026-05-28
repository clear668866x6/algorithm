#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) cin >> w[i], mp[w[i]]++;

    int mx = *max_element(w.begin(), w.end());

    int ans = 0, t = 1e9;

    for (int i = 0; i < mx; i++) {
        if (!mp[i]) {
            cout << i + 1;
            return;
        }
        t = min(t, mp[i]);
    }

    for (int i = 0; i < mx; i++) {
        if (!(mp[i] - t)) {
            cout << t * (mx + 1) + i + 1;
            return;
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