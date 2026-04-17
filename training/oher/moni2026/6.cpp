#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n = 9;
    vector<int> w(n + 1, 0), cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int i = 1; i < n; i++) {
        if (!(i & 1)) {
            int t = w[i] / 3 * 3;
            w[i + 1] += t / 3;
            w[i] -= t;
        } else {
            int t = w[i] / 2 * 2;
            w[i + 1] += t / 2;
            w[i] -= t;
        }
    }

    for (int i = 1; i <= n; i++) cout << w[i] << " \n"[i == n];
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