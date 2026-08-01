#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<int> so(n + 1, 0), sx(n + 1, 0);

    for (int i = 1; i <= n; i++) so[i] = so[i - 1] + (s[i] == 'o');
    for (int i = 1; i <= n; i++) sx[i] = sx[i - 1] + (s[i] == 'x');
    vector<int> ans(n + 1, 0);

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'x') {
            mx = max(mx, sx[i]);
            ans[sx[i]] = i;
        }
    }

    for (int i = mx + 1; i <= n; i++) ans[i] = n;

    for (int k = 1; k <= n; k++) {
        cout << ans[k] << '\n';
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