#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    i64 ans = 1e18;

    vector<i64> pre(n + 1, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i - 1] == '1');
    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + (s[i - 1] == '0');
    i64 p1 = 1e12, p2 = 1e12 + 1;

    for (int i = 0; i <= n; i++) ans = min(ans, (pre[i] + suf[i + 1]) * p2);

    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '1' && s[i] == '0') {
            ans = min(ans, p1 + (pre[i] + suf[i + 1] - 2) * p2);
        }
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