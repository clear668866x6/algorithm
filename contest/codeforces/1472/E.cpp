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
        int l, r, id;
        bool operator<(const E &t) const {
            if (l == t.l) return r > t.r;
            return l < t.l;
        }
    };

    V<E> w(n);

    FOR(i, 0, n - 1) {
        cin >> w[i].l >> w[i].r;
        if (w[i].l > w[i].r) swap(w[i].l, w[i].r);
        w[i].id = i + 1;
    }

    sort(ALL(w));

    V<int> ans(n + 1, 0);

    int m1 = w[0].l, m2 = w[0].r, idx = w[0].id;

    FOR(i, 0, n - 1) {
        if (w[i].l == m1) {
            ans[w[i].id] = -1;
            m1 = w[i].l, m2 = w[i].r, idx = w[i].id;
        } else {
            if (w[i].r > m2) {
                ans[w[i].id] = idx;
            } else {
                m1 = w[i].l, m2 = w[i].r, idx = w[i].id;
                ans[w[i].id] = -1;
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
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
