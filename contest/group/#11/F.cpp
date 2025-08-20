#include <bits/stdc++.h>
#include <cerrno>
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
    int n, k;
    cin >> n >> k;

    struct E {
        int l, r, len, id;
        bool operator<(const E &t) const {
            if (r == t.r) return l < t.l;
            return r < t.r;
        }
    };

    V<E> w(n + 1);
    V<int> vis(n + 1, 0), ans;

    FOR(i, 1, n) cin >> w[i].l >> w[i].r, w[i].len = w[i].r - w[i].l + 1, w[i].id = i;

    sort(w.begin() + 1, w.end());

    map<int, int> mp;
    FOR(i, 1, n) {
        FOR(j, w[i].l, w[i].r) {
            mp[j]++;
            if (mp[j] > k) {
                ans.eb(w[i].id);
                break;
            }
        }
    }

    cout << sz(ans) << endl;
    for (auto x : ans) cout << x << ' ';
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