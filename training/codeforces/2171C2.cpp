#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);

    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], s1 ^= a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], s2 ^= b[i];

    for (int i = 1; i <= n; i++) {
        int t = a[i] ^ b[i];
        if (i & 1) {
            if ((s1 ^ t) > (s2 ^ t)) {
                s1 ^= t, s2 ^= t;
            }
        } else {
            if ((s1 ^ t) < (s2 ^ t)) {
                s1 ^= t, s2 ^= t;
            }
        }
    }

    if (s1 > s2) {
        cout << "Ajisai" << endl;
    } else if (s1 == s2) {
        cout << "Tie" << endl;
    } else {
        cout << "Mai" << endl;
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Task;

    while (Task--) {
        solve();
    }

    return 0;
}