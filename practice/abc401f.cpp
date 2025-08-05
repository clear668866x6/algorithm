#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve() {
    int n1, n2;
    cin >> n1;
    V<V<int>> g1(n1 + 1);

    FOR(i, 2, n1) {
        int a, b;
        cin >> a >> b;
        g1[a].eb(b);
        g1[b].eb(a);
    }
    cin >> n2;

    V<V<int>> g2(n2 + 1);

    FOR(i, 2, n2) {
        int a, b;
        cin >> a >> b;
        g2[a].eb(b);
        g2[b].eb(a);
    }

    V<int> dep1(n1 + 1, 0), dep2(n2 + 1, 0);

    function<void(int, int)> dfs1 = [&](int u, int fa) {
        for (auto j : g1[u]) {
            if (j == fa)
                continue;
            dep1[j] = dep1[u] + 1;
            dfs1(j, u);
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int fa) {
        for (auto j : g2[u]) {
            if (j == fa)
                continue;
            dep2[j] = dep2[u] + 1;
            dfs2(j, u);
        }
    };

    // d1

    V<int> d1, d2;
    int u = 1, v = 1, D = 0;
    dfs1(1, 0);

    FOR(i, 2, n1) {
        if (dep1[i] > dep1[u]) {
            u = i;
        }
    }
    dep1[u] = 0;
    dfs1(u, 0);

    FOR(i, 1, n1) {
        if (dep1[i] > dep1[v]) {
            v = i;
        }
    }
    D = max(D, dep1[v]);
    d1 = dep1;
    dep1[v] = 0;
    dfs1(v, 0);
    FOR(i, 1, n1) { d1[i] = max(d1[i], dep1[i]); }

    // d2
    dfs2(1, 0);

    u = 1, v = 1;

    FOR(i, 2, n2) {
        if (dep2[i] > dep2[u]) {
            u = i;
        }
    }
    dep2[u] = 0;
    dfs2(u, 0);

    FOR(i, 1, n2) {
        if (dep2[i] > dep2[v]) {
            v = i;
        }
    }
    D = max(D, dep2[v]);
    d2 = dep2;
    dep2[v] = 0;
    dfs2(v, 0);
    FOR(i, 1, n2) { d2[i] = max(d2[i], dep2[i]); }

    map<int, int> mp, mp2;

    FOR(i, 1, n2) {
        mp[d2[i]]++;
        mp2[d2[i]] += d2[i];
    }

    FORD(j, 0, D - 1) {
        mp[j] += mp[j + 1];
        mp2[j] += mp2[j + 1];
    }

    int ans = 0;

    FOR(i, 1, n1) {
        int c = mp[D - d1[i]];
        int s = mp2[D - d1[i]];
        ans += d1[i] * c + s + c + (n2 - c) * D;
    }
    cout << ans << endl;
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