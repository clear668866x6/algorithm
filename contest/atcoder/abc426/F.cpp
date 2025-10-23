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

constexpr int N = 3e5 + 10;

struct E {
    int l, r, s, mn, mx, tag;
} tr[N << 2];
int w[N];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void evel(int u, int tag) {
    tr[u].tag += tag;
    tr[u].s -= tag * (tr[u].r - tr[u].l + 1);
    tr[u].mx -= tag;
    tr[u].mn -= tag;
}

void pushdown(int u) {
    if (tr[u].tag) {
        evel(u << 1, tr[u].tag);
        evel(u << 1 | 1, tr[u].tag);

        tr[u].tag = 0;
    }
}

int update(int u, int l, int r, int k) {
    if (tr[u].l > r || tr[u].r < l) return (int)0;
    if (tr[u].l >= l && tr[u].r <= r) {
        if (tr[u].mx == 0) {
            return (int)0;
        }
        if (tr[u].mx <= k) {
            int t = tr[u].s;
            tr[u].s = tr[u].mx = tr[u].mn = 0;
            return t;
        }
        if (tr[u].mn >= k) {
            int t = k * (tr[u].r - tr[u].l + 1);
            tr[u].s -= k;
            tr[u].mx -= k;
            tr[u].mn -= k;
            tr[u].tag += k;
            return t;
        }
    }
    pushdown(u);
    int ans = 0;
    ans += update(u << 1, l, r, k);
    ans += update(u << 1 | 1, l, r, k);
    pushup(u);
    return ans;
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u] = {l, r, w[l], w[l], w[l], 0};
        RE;
    }

    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void solve() {
    int n;
    cin >> n;
    FOR(i, 1, n) cin >> w[i];

    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << update(1, l, r, x) << endl;
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