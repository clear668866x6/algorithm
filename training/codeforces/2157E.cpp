#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) cin >> w[i], mp[w[i]]++;

    sort(w.begin(), w.end());

    int ans = 0, tot = 0, cnt = 0;

    for (int i = 1; i <= n * 4; i++) {
        tot += mp[i] - 1;
        cnt++;
        if (tot < k) cnt = 0, tot = 0;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
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