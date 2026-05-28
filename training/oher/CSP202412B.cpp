#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2, 0), b(n + 2, 0);
    for (int i = 0; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> suf(n + 3, 0);
    for (int i = n; i >= 0; i--) {
        suf[i] = max(0, suf[i + 1] + a[i] - b[i]);
    }

    int tmp = 0, base = a[0];

    for (int i = 1; i <= n; i++) {
        int t = suf[i + 1] + a[i];
        int del = max(0, t - tmp);
        cout << base + del << ' ';
        tmp += b[i];
        if (tmp - a[i] < 0) {
            base += (a[i] - tmp);
            tmp = 0;
        } else {
            tmp -= a[i];
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