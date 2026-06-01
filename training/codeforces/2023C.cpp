#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    int m1, m2;
    cin >> n >> k;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    vector<vector<int>> g1(n + 1), g2(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m1;
    for (int i = 1; i <= m1; i++) {
        int a, b;
        cin >> a >> b;
        g1[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) cin >> b[i];
    cin >> m2;
    for (int i = 1; i <= m2; i++) {
        int a, b;
        cin >> a >> b;
        g2[a].push_back(b);
    }

    vector<int> o1(k, 0), i1(k, 0), o2(k, 0), i2(k, 0);
    vector<int> d1(n + 1, -1), d2(n + 1, -1);
    int so1 = 0, si1 = 0, so2 = 0, si2 = 0;

    auto bfs = [&](auto g, auto &d) {
        queue<int> q;
        q.push(1);
        d[1] = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (auto v : g[t]) {
                if (d[v] == -1) {
                    d[v] = d[t] + 1;
                    d[v] %= k;
                    q.push(v);
                }
            }
        }
    };

    bfs(g1, d1), bfs(g2, d2);

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            o1[d1[i]]++;
            so1++;
        } else {
            i1[d1[i]]++;
            si1++;
        }

        if (b[i] == 1) {
            o2[d2[i]]++;
            so2++;
        } else {
            i2[d2[i]]++;
            si2++;
        }
    }

    if (so1 != si2 || so2 != si1) {
        cout << "NO\n";
        return;
    }

    if (!so1 || !so2) {
        cout << "YES\n";
        return;
    }

    auto KMP = [&](vector<int> a, vector<int> b) {
        vector<int> c = b;
        for (auto x : b) c.push_back(x);

        int n = a.size(), m = c.size();

        vector<int> nxt(n + 1, 0);

        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && a[i] != a[j]) j = nxt[j - 1];
            if (a[i] == a[j]) j++;
            nxt[i] = j;
        }

        vector<int> ok(n + 1, 0);

        for (int i = 0, j = 0; i < m; i++) {
            while (j > 0 && c[i] != a[j]) j = nxt[j - 1];
            if (c[i] == a[j]) j++;
            if (j == n) {
                ok[i - n + 1] = 1;
                j = nxt[j - 1];
            }
        }

        return ok;
    };

    auto v1 = KMP(i1, o2);
    auto v2 = KMP(o1, i2);

    for (int c1 = 0; c1 < k; c1++) {
        if (v1[c1]) {
            int c2 = (c1 + 2) % k;

            if (v2[c2]) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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