#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            c.push_back(x);
        }
    }

    int X = n, Y = m;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            X = x, Y = y;
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            vector<int> d;
            for (int i = 1; i <= Y; i++) {
                for (int j = i; j <= X * Y; j += Y) {
                    d.push_back(c[j - 1]);
                }
            }
            swap(X, Y);
            c = d;
        } else {
            int x, y;
            cin >> x >> y;
            int t = x * Y + y;
            cout << c[t] << '\n';
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