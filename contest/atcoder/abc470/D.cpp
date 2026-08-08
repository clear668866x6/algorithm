#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1, 0);
    vector<int> c1(n + 1, 0), c2(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], c1[i] = a[i], c2[a[i]] = i;

    int cnt = 0;

    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            if (cnt & 1) {
                swap(c1[c2[x]], c1[c2[y]]);
                swap(c2[x], c2[y]);
            } else {
                swap(c2[c1[x]], c2[c1[y]]);
                swap(c1[x], c1[y]);
            }
        } else {
            cnt++;
        }
    }

    if (cnt & 1) {
        for (int i = 1; i <= n; i++) {
            cout << c2[i] << ' ';
        }
    } else {
        for (int i = 1; i <= n; i++) cout << c1[i] << ' ';
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