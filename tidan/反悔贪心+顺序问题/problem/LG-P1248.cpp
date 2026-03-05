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
        int a, b, idx;
        bool operator<(const E &t) const {
            return min(a, t.b) < min(b, t.a);
        }
    };
    V<E> w(n);
    FOR(i, 0, n - 1) cin >> w[i].a;
    FOR(i, 0, n - 1) cin >> w[i].b, w[i].idx = i + 1;

    sort(ALL(w));

    int ans = 0;

    int ta = w[0].a, tb = w[0].a + w[0].b;

    FOR(i, 1, n - 1) {
        tb = max(tb, ta + w[i].a) + w[i].b;
        ta += w[i].a;
    }

    cout << max(ta, tb) << endl;
    FOR(i, 0, n - 1) cout << w[i].idx << ' ';
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