#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n + m + 1, 0);
    iota(p.begin(), p.end(), 0ll);
    vector<int> d(n + m + 1, 0);

    auto find = [&](this auto &find, int u) -> int {
        if (u != p[u]) {
            int rt = find(p[u]);
            d[u] ^= d[p[u]];
            p[u] = rt;
        }
        return p[u];
    };

    auto getn = [&](int x) { return x; };
    auto getm = [&](int x) { return x + n; };

    bool f = false;

    for (int i = 1; i <= k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (f) continue;
        if (x2 == x1 + 1 && y2 == y1 + 1) {
            int a = getn(x1), b = getm(y1);
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                d[pa] = d[a] ^ d[b] ^ 1;
                p[pa] = pb;
            } else {
                if (d[a] == d[b]) {
                    f = 1;
                }
            }
        } else {
            int a = getn(x1), b = getm(y2);
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                d[pa] = d[a] ^ d[b];
                p[pa] = pb;
            } else {
                if (d[a] != d[b]) {
                    f = 1;
                }
            }
        }
    }

    if (f)
        cout << "NO\n";
    else
        cout << "YES\n";
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