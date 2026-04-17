#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w((1 << n) + 1, 0);

    int tot = 1 << n;

    for (int r = 1; r <= n; r++) {
        int len = tot / (1 << r);

        vector<int> c(len + 1, 0);
        for (int j = 1; j <= len; j++) cin >> c[j];

        if (r == 1) {
            for (int j = 1, k = 1; j <= tot; j += (1 << r)) {
                w[j] = c[k++];
            }
        } else {
            for (int j = 1, t = 1; j <= tot; j += (1 << r)) {
                int mx = 0, idx = -1;
                for (int k = j; k < j + (1 << r); k += 2) {
                    if (!w[k + 1] && c[t] > w[k]) {
                        if (mx < w[k]) {
                            mx = w[k];
                            idx = k;
                        }
                    }
                }
                if (idx != -1) {
                    w[idx + 1] = c[t++];
                }
            }
        }
    }

    int x;
    cin >> x;
    for (int i = 1; i <= tot; i++) {
        if (!w[i]) {
            w[i] = x;
            break;
        }
    }

    for (int i = 1; i <= tot; i++) {
        if (!w[i]) {
            cout << "No Solution";
            return;
        }
    }

    vector<int> c = w;
    for (int r = 1; r <= n; r++) {
        vector<int> d(1, 0);
        for (int l = 1; l < c.size(); l += 2) {
            if (c[l + 1] > c[l]) {
                d.push_back(c[l + 1]);
            } else if (c[l + 1] < c[l]) {
                d.push_back(c[l]);
            } else {
                cout << "No Solution";
                return;
            }
        }
        c = d;
    }

    if (c.back() != x) {
        cout << "No Solution";
        return;
    }

    for (int i = 1; i <= tot; i++) cout << w[i] << " \n"[i == tot];
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