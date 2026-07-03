#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            cout << "0\n";
            return;
        }
    }

    i64 tot = 0;

    for (int i = 1; i <= n; i++) {
        int t = a[i];
        while (t % 3 == 0) tot++, t /= 3;
    }

    if (tot >= 2) {
        cout << "0\n";
        return;
    } else if (tot == 1) {
        i64 ans = 1e18;

        for (int i = 1; i <= n; i++) {
            if (a[i] % 3 == 0) continue;
            i64 t = ((a[i] + 2) / 3) * 3;
            ans = min(ans, abs(t - a[i]));
        }
        for (int i = 1; i <= n; i++) {
            i64 t = ((a[i] + 8) / 9) * 9;
            ans = min(ans, abs(t - a[i]));
        }

        cout << ans << '\n';
    } else {

        i64 ans = 1e18;

        for (int i = 1; i <= n; i++) {
            i64 t = ((a[i] + 8) / 9) * 9;
            ans = min(ans, abs(t - a[i]));
        }

        if (n >= 2) {
            vector<i64> c;

            for (int i = 1; i <= n; i++) {
                i64 t = ((a[i] + 2) / 3) * 3;
                c.push_back(abs(t - a[i]));
            }

            sort(c.begin(), c.end());

            ans = min(ans, c[0] + c[1]);
        }

        cout << ans << '\n';
    }
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