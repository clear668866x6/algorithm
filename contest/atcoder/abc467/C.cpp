#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], c[i] = a[i];
    for (int i = 1; i <= n - 1; i++) cin >> b[i];

    int tot = 0;

    for (int i = 1; i <= n - 1; i++) {
        if (b[i] == 1) {
            if (c[i] == 0) {
                if (c[i + 1] == 0) {
                    c[i + 1] = 1;
                    tot++;
                }
            } else {
                if (c[i + 1] == 1) {
                    c[i + 1] = 0;
                    tot++;
                }
            }
        } else {
            if (c[i] == 0) {
                if (c[i + 1] == 1) {
                    c[i + 1] = 0;
                    tot++;
                }
            } else {
                if (c[i + 1] == 0) {
                    c[i + 1] = 1;
                    tot++;
                }
            }
        }
    }

    int tot2 = 1;
    for (int i = 1; i <= n; i++) c[i] = a[i];

    if (c[1] == 1)
        c[1] = 0;
    else
        c[1] = 1;

    for (int i = 1; i <= n - 1; i++) {
        if (b[i] == 1) {
            if (c[i] == 0) {
                if (c[i + 1] == 0) {
                    c[i + 1] = 1;
                    tot2++;
                }
            } else {
                if (c[i + 1] == 1) {
                    c[i + 1] = 0;
                    tot2++;
                }
            }
        } else {
            if (c[i] == 0) {
                if (c[i + 1] == 1) {
                    c[i + 1] = 0;
                    tot2++;
                }
            } else {
                if (c[i + 1] == 0) {
                    c[i + 1] = 1;
                    tot2++;
                }
            }
        }
    }

    cout << min(tot, tot2);
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