#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;

    int mx = 0;

    for (auto [x, y] : mp) {
        mx = max(mx, y);
    }

    cout << n - mx;
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