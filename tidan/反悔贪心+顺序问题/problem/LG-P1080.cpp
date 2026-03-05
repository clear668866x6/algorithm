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

    struct E {
        int a, b;
        bool operator<(const E &t) const {
            return a * b < t.a * t.b;
        }
    };

    V<E> w(n + 1);

    FOR(i, 0, n) cin >> w[i].a >> w[i].b;

    sort(w.begin() + 1, w.end());

    V<int> ans(1, 0);

    V<int> l;

    int p = w[0].a;
    while (p) {
        l.eb(p % 10);
        p /= 10;
    }

    auto mul = [&](V<int> a, int b) {
        int t = 0;
        V<int> c;
        for (int i = 0; i < sz(a) || t; i++) {
            if (i < sz(a)) t += a[i] * b;
            c.eb(t % 10);
            t /= 10;
        }
        while (sz(c) > 1 && c.back() == 0) c.pop_back();
        return c;
    };

    auto div = [&](V<int> a, int b) {
        V<int> c;
        int r = 0;
        for (int i = sz(a) - 1; i >= 0; i--) {
            r = r * 10 + a[i];
            c.eb(r / b);
            r %= b;
        }
        reverse(ALL(c));
        while (sz(c) > 1 && c.back() == 0) c.pop_back();
        return c;
    };

    auto max = [&](V<int> a, V<int> b) {
        if (sz(a) > sz(b)) {
            return a;
        } else if (sz(a) == sz(b)) {
            FOR(i, 0, sz(a) - 1) {
                if (a[i] > b[i]) {
                    return a;
                } else if (a[i] < b[i]) {
                    return b;
                }
            }
            return a;
        } else {
            return b;
        }
    };

    FOR(i, 1, n) {
        V<int> t = div(l, w[i].b);
        reverse(ALL(t));
        ans = max(ans, t);
        reverse(ALL(t));
        l = mul(l, w[i].a);
    }

    for (auto x : ans) cout << x;
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