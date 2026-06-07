#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<i64> a(n + 1, 0);
    i64 tot = 0;
    vector<i64> b(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) {
        b[i] = ((a[i] - a[i - 1]) % 5 + 5) % 5;
        tot += b[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l != 1) {
            tot -= b[l];
        }
        if (r + 1 <= n) {
            tot -= b[r + 1];
        }

        b[l] = (b[l] + 1) % 5, b[r + 1] = ((b[r + 1] - 1) % 5 + 5) % 5;

        if (l != 1) {
            tot += b[l];
        }
        if (r + 1 <= n) {
            tot += b[r + 1];
        }

        cout << tot << '\n';
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