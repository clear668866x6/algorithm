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

constexpr int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    V<array<int, 3>> q(m + 1);
    V<int> L(n + 1, 0), R(n + 1, 1e18);

    FOR(i, 1, m) {
        auto &[l, r, k] = q[i];
        cin >> l >> r >> k;
    }

    sort(q.begin() + 1, q.end(), [&](auto a, auto b) { return a[2] < b[2]; });

    V<int> p(n + 2, 0);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    V<int> b(n + 2, n), vis(n + 2, 0);

    FOR(id, 1, m) {
        auto [l, r, k] = q[id];
        for (int i = find(l); i <= r; i = find(i)) {
            b[i] = k;
            p[i] = find(i + 1);
        }
        vis[k] = 1;
        L[k] = max(L[k], l);
        R[k] = min(R[k], r);
    }
    int ans = 1, c = 0;

    V<V<int>> g(n + 1);

    FOR(i, 1, n) {
        g[b[i]].eb(i);
    }

    FORD(i, 1, n) {
        int t = sz(g[i]);
        if (vis[i]) {
            if (L[i] > R[i]) {
                cout << 0 << endl;
                RE;
            }
            int cnt = 0;

            for (auto x : g[i]) {
                if (x >= L[i] && x <= R[i]) cnt++;
            }

            if (!cnt) {
                cout << 0 << endl;
                RE;
            }

            ans *= cnt;
            ans %= mod;
            c += (t - 1);
        } else {
            c += t;
            if (c <= 0) {
                cout << 0 << endl;
                RE;
            }
            ans *= c;
            c--;
            ans %= mod;
        }
    }
    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
