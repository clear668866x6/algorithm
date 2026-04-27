#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1, 0);
    map<i64, i64> mp;
    for (int i = 1; i <= n; i++) cin >> w[i], mp[w[i]]++;

    priority_queue<i64> q;

    for (auto [x, y] : mp) {
        q.push(x * y);
    }

    while (!q.empty() && k--) {
        q.pop();
    }

    i64 ans = 0;
    while (!q.empty()) {
        ans += q.top();
        q.pop();
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