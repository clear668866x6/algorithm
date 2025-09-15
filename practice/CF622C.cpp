#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
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

struct ST {
    static constexpr int N = 2e5 + 10;

    int f[N][22], g[N][22];

    void init(V<int> w, int n) {
        FOR(j, 0, 20) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                if (!j)
                    f[i][j] = g[i][j] = w[i];
                else {
                    f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                    g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
    }

    int query(int l, int r, int op) {
        int len = log2(r - l + 1);
        if (op == 1) {
            return min(f[l][len], f[r - (1 << len) + 1][len]);
        } else {
            return max(g[l][len], g[r - (1 << len) + 1][len]);
        }
    }

} A;

void solve() {
    int n, m;
    cin >> n >> m;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    A.init(w, n);

    map<int, V<int>> mp;

    FOR(i, 1, n) mp[w[i]].eb(i);

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        int mn = A.query(l, r, 1), mx = A.query(l, r, 0);
        int t = (upper_bound(ALL(mp[x]), r) - lower_bound(ALL(mp[x]), l));
        if (t == r - l + 1) {
            cout << -1 << endl;
        } else {
            if (mn == x) {
                cout << (*lower_bound(ALL(mp[mx]), l)) << endl;
            } else {
                cout << (*lower_bound(ALL(mp[mn]), l)) << endl;
            }
        }
    }
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