#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;

    V<V<int>> g(n + 1);
    V<int> x(n + 1, 0), y(n + 1, 0);
    V<int> pos(n + 1, 0);
    map<int, set<int>> mp;
    map<int, V<int>> mp2;
    V<map<int, int>> mp3(n + 1);

    FOR(i, 1, n) {
        cin >> x[i] >> y[i];
    }

    FOR(i, 1, n) {
        int t = pos[x[i]];
        if (!mp3[t][y[i]]) {
            mp3[t][y[i]] = i;
            pos[i] = i;
            g[t].eb(i);
        } else {
            pos[i] = mp3[t][y[i]];
            mp2[pos[i]].eb(i);
        }
    }
    V<int> ans;

    FOR(i, 0, n) {
        sort(ALL(g[i]), [&](int a, int b) { return y[a] < y[b]; });
    }

    // cout << "-----------------" << endl;
    // FOR(i, 0, n) {
    //     cout << i << endl;
    //     for (auto v : g[i]) cout << v << ' ';
    //     cout << endl;
    // }
    // cout << "-----------------" << endl;

    auto dfs = [&](auto &&dfs, int u) -> void {
        if (u != 0) {
            ans.eb(u);
            if (sz(mp2[u])) {
                for (auto x : mp2[u]) {
                    ans.eb(x);
                }
            }
        }
        for (auto v : g[u]) {
            dfs(dfs, v);
        }
    };

    dfs(dfs, 0);

    for (auto x : ans) cout << x << ' ';
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}