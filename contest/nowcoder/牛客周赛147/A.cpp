#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;

    map<char, int> mp;

    for (auto x : s) mp[x]++;

    int ans = 0;

    for (auto [x, y] : mp) {
        if (y == 1) ans++;
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