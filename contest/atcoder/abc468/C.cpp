#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<int> c;
    for (int i = 0; i < n; i++) c.push_back(i + 1);

    int ans = 0;

    do {
        bool f1 = false, f2 = false;
        for (int i = 0; i < n; i++) {
            if (c[i] > a[i]) {
                f1 = 1;
                break;
            } else if (c[i] < a[i])
                break;
        }

        for (int i = 0; i < n; i++) {
            if (c[i] < b[i]) {
                f2 = 1;
                break;
            } else if (c[i] > b[i])
                break;
        }

        if (f1 && f2) {
            ans++;
        }

    } while (next_permutation(c.begin(), c.end()));

    cout << ans;
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