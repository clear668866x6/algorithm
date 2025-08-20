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

template<class T> struct LiChaoSegmentTree {
    V<int> t;
    T x;
    LiChaoSegmentTree() {}
    LiChaoSegmentTree(int x, T y) {
        y = x;
        t.resize(x + 10);
    }

    void update(int u, int l, int r, int k) {
        if (!k) RE;
        if (l == r) {
            if (x.fun(t[u], l) < x.fun(k, l)) swap(t[u], k);
            RE;
        }
        int mid = (l + r) >> 1;
        if (x.fun(t[u], mid) < x.fun(k, mid)) swap(t[u], k);
        if (x.fun(t[u], l) < x.fun(k, l)) update(u << 1, l, mid, k);
        if (x.fun(t[u], r) < x.fun(k, r)) update(u << 1 | 1, mid + 1, r, k);
    }

    int query(int u, int l, int r, int k) {
        if (l > k || r < k || !t[u]) return -1e18;
        if (l == r) {
            return x.fun(t[u], k);
        }
        int mid = (l + r) >> 1;
        return max({x.fun(t[u], k), query(u << 1, l, mid, k), query(u << 1 | 1, mid + 1, r, k)});
    }
};

void solve() {
    int n;
    cin >> n;

    V<int> w(n + 1, 0), a(n + 1, 0), b(n + 1, 0), s(n + 1, 0);

    FOR(i, 1, n) {
        cin >> w[i];
        s[i] = b[i] = s[i - 1] + w[i];
        a[i] = a[i - 1] + w[i] * i;
    }

    sort(s.begin() + 1, s.end());
    s.erase(unique(s.begin() + 1, s.end()), s.end());

    int t = sz(s);

    int ans = 0;

    V<array<int, 2>> p(n + 1);

    struct E {

        int fun(int pos, int x) {
            if (!pos) return -1e18;
            return p[pos][0] * s[x] + p[pos][1];
        }
    };

    LiChaoSegmentTree<E> A(2e5 + 10);

    FOR(i, 1, n) {
        int pos = lower_bound(s.begin() + 1, s.end(), b[i]) - s.begin();
        p[i] = {1 - i, -a[i - 1] + (i - 1) * b[i - 1]};
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