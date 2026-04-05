#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    vector<i64> f(n + 1, 0);
    vector<i64> preji(n + 1, -1e18), preou(n + 1, -1e18);
    vector<i64> pre(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (abs(w[i]) & 1) {
            f[i] = max(f[i], preji[i - 1] + w[i]);
            preji[i] = max(preji[i - 1], pre[i - 1] + w[i]);
        } else {
            f[i] = max(f[i], preou[i - 1] + w[i]);
            preou[i] = max(preou[i - 1], pre[i - 1] + w[i]);
        }
        preji[i] = max(preji[i], preji[i - 1]);
        preou[i] = max(preou[i], preou[i - 1]);
        pre[i] = max(pre[i - 1], f[i]);
    }
    cout << *max_element(f.begin(), f.end()) << '\n';
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