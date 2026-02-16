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
    int n, x, y, t;
    cin >> n >> x >> y >> t;
    struct E {
        int a, b, idx;
        bool operator<(const E &t) const {
            if (b == t.b) return a > t.a;
            return b > t.b;
        }
    };

    V<E> w(n);

    FOR(i, 0, n - 1) cin >> w[i].a;
    FOR(i, 0, n - 1) cin >> w[i].b, w[i].idx = i + 1;

    sort(ALL(w));

    int tot = 0;
    V<int> ans(n + 1, 0);

    FOR(i, 0, n - 1) {
        if (tot + x <= t) {
            tot += x;
            int p = w[i].a;
            if (tot + p * y <= t) {
                tot += p * y;
                ans[w[i].idx] = p;
            } else {
                int del = (t - tot) / y;
                ans[w[i].idx] = del;
                break;
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << ' ';
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