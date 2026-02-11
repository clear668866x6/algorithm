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

struct SegmentTree {
    static constexpr int N = 2e5 + 10;

    struct E {
        int l, r;
        int s, add;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    }

    void evel(int u, int add) {
        tr[u].add += add;
        tr[u].s += add * (tr[u].r - tr[u].l + 1);
    }

    void pushdown(int u) {
        if (tr[u].add) {
            evel(u << 1, tr[u].add);
            evel(u << 1 | 1, tr[u].add);
            tr[u].add = 0;
        }
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 0};
        if (l == r) RE;
        int mid = (l + r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, int val) {
        if (tr[u].l > r || tr[u].r < l) RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            evel(u, val);
            RE;
        }

        pushdown(u);
        modify(u << 1, l, r, val);
        modify(u << 1 | 1, l, r, val);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s;
        }
        pushdown(u);
        return query(u << 1, l, r) + query(u << 1 | 1, l, r);
    }

} A;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    int ans = 0;
    V<int> a(m + 1, 0), b(m + 1, 0);

    FOR(i, 1, m) cin >> a[i] >> b[i];

    int l = 0, r = m + 1;

    auto check = [&](int x) {
        V<int> dd(n + 3, 0), d(n + 3, 0);
        FOR(i, 1, x) {
            int p = a[i], f = b[i];
            auto get = [&](int l, int r, int k, int d) {
                r = min(r, n);
                if (l > r) RE;
                if (l < 1) {
                    k += (1 - l) * d;
                    l = 1;
                }
                if (l > r) RE;
                dd[l] += k, dd[l + 1] -= k;

                if (l + 1 <= r) {
                    dd[l + 1] += d, dd[r + 1] -= d;
                }
                if (r < n) {
                    dd[r + 1] -= (k + d * (r - l));
                    dd[r + 2] += (k + d * (r - l));
                }
            };
            get(p - f + 1, p, 1, 1);
            get(p + 1, p + f - 1, f - 1, -1);
        }

        int base = 0, cur = 0;

        FOR(i, 1, n) {
            base += dd[i];
            d[i] += base;
        }
        FOR(i, 1, n) d[i] += d[i - 1];
        FOR(i, 1, n) {
            if (d[i] > h) {
                return 1;
            }
        }
        return 0;
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    if (r <= m) {
        Yes;
        cout << r;
    } else {
        No;
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