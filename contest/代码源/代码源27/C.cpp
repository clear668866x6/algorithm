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
        int t, a, id;
        bool operator<(const E &c) const {
            if (t == c.t) return id < c.id;
            return t < c.t;
        }
    };

    V<E> w(n + 1);

    FOR(i, 1, n) cin >> w[i].t >> w[i].a, w[i].id = i;

    sort(w.begin() + 1, w.end());

    V<int> ans(n + 1, 0);

    int a = 0, b = 0;

    FOR(i, 1, n) {
        if (a <= w[i].t) {
            a = w[i].t + w[i].a;
            ans[w[i].id] = a;
        } else if (b <= w[i].t) {
            b = w[i].t + w[i].a;
            ans[w[i].id] = b;
        } else {
            if (a > b) {
                ans[w[i].id] = b + w[i].a;
                b += w[i].a;
            } else {
                ans[w[i].id] = a + w[i].a;
                a += w[i].a;
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << endl;
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