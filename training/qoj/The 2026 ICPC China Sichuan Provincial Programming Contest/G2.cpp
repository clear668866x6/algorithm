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

    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            vector<int> c;
            for (int i = 1; i <= l - 1; i++) {
                c.push_back(w[i]);
            }
            for (int i = r + 1; i <= n; i++) {
                c.push_back(w[i]);
            }

            int ans = 0;

            for (int i = 0; i < c.size(); i++) {
                if (i & 1) {
                    ans -= c[i];
                } else {
                    ans += c[i];
                }
            }
            if (ans == 0) {
                cout << l << ' ' << r << ' ' << ans << endl;
            }
        }
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