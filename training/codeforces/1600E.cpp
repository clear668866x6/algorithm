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

    int idx1 = 1, idx2 = n;

    for (int i = 2; i <= n; i++) {
        if (w[i] > w[i - 1]) {
            idx1 = i;
        } else {
            break;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        if (w[i + 1] < w[i]) {
            idx2 = i;
        } else {
            break;
        }
    }

    int l = 1, r = n, cnt = 0, lst = -1;

    while (l <= r) {
        bool okl = (w[l] > lst);
        bool okr = (w[r] > lst);

        if (!okl && !okr) break;

        if (okl && !okr) {
            lst = w[l++];
            cnt++;
        } else if (!okl && okr) {
            lst = w[r--];
            cnt++;
        } else {
            if (w[l] > w[r]) {
                if ((max(1, idx1 - l + 1)) & 1) {
                    if (cnt & 1) {
                        cout << "Bob";
                    } else {
                        cout << "Alice";
                    }
                    return;
                }
                cnt++;
                lst = w[r--];
            } else if (w[l] < w[r]) {
                if (max(1, r - idx2 + 1) & 1) {
                    if (cnt & 1) {
                        cout << "Bob";
                    } else {
                        cout << "Alice";
                    }
                    return;
                }
                cnt++;
                lst = w[l++];
            } else {
                if ((max(1, idx1 - l + 1)) & 1 || max(1, r - idx2 + 1) & 1) {
                    if (cnt & 1) {
                        cout << "Bob";
                    } else {
                        cout << "Alice";
                    }
                } else {
                    if (cnt & 1) {
                        cout << "Alice";
                    } else {
                        cout << "Bob";
                    }
                }
                return;
            }
        }
    }

    if (cnt & 1) {
        cout << "Alice";
    } else {
        cout << "Bob";
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