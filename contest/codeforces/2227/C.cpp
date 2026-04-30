#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);

    vector<vector<int>> c(7);
    for (int i = 1; i <= n; i++) cin >> w[i], c[w[i] % 6].push_back(w[i]);

    vector<int> ans;

    for (auto x : c[0]) ans.push_back(x);
    for (auto x : c[3]) ans.push_back(x);
    for (auto x : c[1]) ans.push_back(x);
    for (auto x : c[5]) ans.push_back(x);
    for (auto x : c[4]) ans.push_back(x);
    for (auto x : c[2]) ans.push_back(x);

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
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