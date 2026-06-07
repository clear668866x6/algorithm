#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> f(1e6 + 10, 0);
    vector<int> pre(1e6 + 10, -1);

    for (int i = 1; i <= n; i++) {
        int t = a[i], v = a[i];
        if (t == 1) {
            f[1] = 1;
        } else {
            for (int j = 2; j <= t / j; j++) {
                if (t % j == 0) {
                    if (f[v] < f[v / j] + 1) {
                        pre[v] = v / j;
                        f[v] = f[v / j] + 1;
                    }
                    while (t % j == 0) t /= j;
                }
            }

            if (t > 1) {
                if (f[v] < f[v / t] + 1) {
                    pre[v] = v / t;
                    f[v] = f[v / t] + 1;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= 1e6; i++) {
        ans = max(ans, f[i]);
    }

    vector<int> res;

    for (int i = 1e6; i >= 1; i--) {
        if (f[i] == ans) {
            int t = i;
            while (pre[t] != -1) {
                res.push_back(t);
                t = pre[t];
            }
            if (res.size() != f[i]) res.push_back(1);
            break;
        }
    }

    cout << ans << '\n';
    reverse(res.begin(), res.end());

    for (auto x : res) cout << x << ' ';
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