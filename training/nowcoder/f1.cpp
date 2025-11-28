#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1, 0), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    sort(w.begin(), w.end());

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + w[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int t = upper_bound(pre.begin(), pre.end(), pre[i - 1] + m) - pre.begin() - 1;
        ans = max(ans, t - i + 1);
    }

    cout << ans;
}