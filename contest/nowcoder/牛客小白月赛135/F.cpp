#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct BITTree {

    vector<int> tr;
    int n;

    BITTree() {}
    BITTree(int _n) {
        n = _n;
        tr.resize(n + 10);
    }

    void add(int x, int c) {
        for (int i = x; i <= n; i += i & -i) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & -i) ans += tr[i];
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    BITTree a1(n), a4(n), a7(n);

    vector<i64> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto get = [&](int op, int idx, int val) {
        if (op == 1) {
            a1.add(idx, val);
        } else if (op == 4) {
            a4.add(idx, val);
        } else if (op == 7) {
            a7.add(idx, val);
        }
    };

    for (int i = 1; i <= n; i++) {
        i64 t = a[i] * a[i] % 9;
        get(t, i, 1);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            i64 lst = a[i] * a[i] % 9;
            get(lst, i, -1);
            a[i] = x;
            i64 cur = a[i] * a[i] % 9;
            get(cur, i, 1);
        } else {
            int l, r;
            cin >> l >> r;

            if ((r - l + 1) % 3) {
                cout << "No\n";
            } else {
                i64 ans = 0;
                int c1 = a1.query(r) - a1.query(l - 1);
                int c4 = a4.query(r) - a4.query(l - 1);
                int c7 = a7.query(r) - a7.query(l - 1);

                int x = (c1 - 2 * c7 + 4 * c4);
                if (x % 9 != 0) {
                    cout << "No\n";
                    continue;
                }

                int y = (c4 - 2 * c1 + 4 * c7);
                if (y % 9 != 0) {
                    cout << "No\n";
                    continue;
                }

                int z = (c7 + 4 * c1 - 2 * c4);

                if (z % 9 != 0) {
                    cout << "No\n";
                    continue;
                }

                if (x >= 0 && y >= 0 && z >= 0) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
        }
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