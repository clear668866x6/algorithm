#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    vector<int> mx(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> w[i], mx[w[i]] = max(mx[w[i]], i);
    mx[n + 1] = n + 1;

    int l = 1, idx = 1;
    vector<int> p;
    i64 tot = 0, ans = 0;

    while (l <= n) {
        int r = l;
        while (mx[idx] < r) {
            idx++;
        }
        r = mx[idx];
        if (r > n) break;
        for (int i = l; i < r; i++) {
            if (w[i] >= w[r]) {
                tot += (w[i] - w[r]);
            }
        }

        int cnt = 0;
        for (int i = l; i < r; i++) {
            if (w[i] > w[r] - 1) {
                cnt++;
            }
        }
        p.push_back(cnt);

        idx++;
        l = r;
    }

    for (auto x : p) {
        ans = max(ans, tot + x);
    }

    cout << ans << '\n';
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