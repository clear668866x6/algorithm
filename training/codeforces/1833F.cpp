#include <algorithm>
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

constexpr int mod = 1e9 + 7;

struct SegmentTree {
    struct E {
        int l, r, s;
    };
    V<E> tr;
    V<int> w;

    SegmentTree() {}
    SegmentTree(int _n, V<int> _w) {
        tr.resize(_n * 4 + 10, {0, 0, 0});
        w = _w;
    }

    void pushup(int u) {
        tr[u].s = tr[u << 1].s * tr[u << 1 | 1].s % mod;
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, 1};
        if (l == r) {
            tr[u] = {l, r, w[l]};
            RE;
        }
        int mid = (l + r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return 1;
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s;
        }

        int ans = 1;
        ans *= query(u << 1, l, r);
        ans %= mod;
        ans *= query(u << 1 | 1, l, r);
        ans %= mod;
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> w(n + 1, 0);
    map<int, int> mp;
    V<int> c;
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++, c.eb(w[i]);

    sort(ALL(c));
    c.erase(unique(ALL(c)), c.end());

    auto get = [&](int x) { return lower_bound(ALL(c), x) - c.begin() + 1; };

    n = sz(c);

    V<int> p(n + 1, 0);

    for (auto [x, y] : mp) {
        p[get(x)] = y;
    }

    SegmentTree A(n * 2, p);
    A.build(1, 1, n);

    int ans = 0;

    FOR(i, 1, n) {
        int t = c[i - 1] + m - 1;
        int l = get(c[i - 1]), r = get(t);
        if (r > n) continue;
        if (r - l + 1 != m || c[r - 1] - c[i - 1] != m - 1) continue;
        ans += (A.query(1, l, r));
        ans %= mod;
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
