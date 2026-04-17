#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> suf(n + 1, 0), mid(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> suf[i];
    for (int i = 1; i <= n; i++) cin >> mid[i];

    vector<vector<int>> g(121);

    // auto dfs = [&](auto &&dfs, string a, string b, int u) {
    //     if (a.empty()) return;
    //     int t=
    //     cout << b[b.size() - 1];
    //     int t=a.find(b[b.size()-1]);
    //     dfs(dfs, a.substr(0, t), b.substr(0, t));
    //     dfs(dfs,a.substr(t+1),b.substr(t,a.size()-t-1));
    // };

    auto dfs = [&](auto &&dfs, vector<int> a, vector<int> b, int fa) {
        if (a.size() == 1) return;
        int p = b[b.size() - 1];
        int t = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == p) {
                t = i;
            }
        }
        g[p].push_back(fa);
        g[fa].push_back(p);
        vector<int> c(1, 0), d(1, 0);
        for (int i = 1; i < t; i++) {
            c.push_back(a[i]);
            d.push_back(b[i]);
        }

        dfs(dfs, c, d, p);
        vector<int> e(1, 0), f(1, 0);
        for (int i = t + 1; i < a.size(); i++) {
            e.push_back(a[i]);
        }
        for (int i = t; i < (int)b.size() - 1; i++) {
            f.push_back(b[i]);
        }
        dfs(dfs, e, f, p);
    };

    dfs(dfs, mid, suf, 0);

    int rt = suf.back();

    vector<int> dep(121 + 1, 0);

    auto dfs2 = [&](auto &&dfs2, int u, int fa) -> void {
        dep[u] = dep[fa] + 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs2(dfs2, v, u);
        }
    };

    dfs2(dfs2, rt, 0);

    int mx = *max_element(dep.begin(), dep.end());

    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= 120; j++) {
            if (dep[j] == i && j % i != 0) {
                cout << "0\n";
                return;
            }
        }
    }

    cout << "1\n";
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