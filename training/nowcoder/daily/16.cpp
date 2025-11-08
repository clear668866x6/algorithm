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
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = ' ' + s;
    V<V<int>> g(n + 1);
    V<int> p(n + 1, 0);
    iota(ALL(p), 0ll);

    V<int> siz(n + 1, 1);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
        if (s[a] == '1' && s[b] == '1') {
            a = find(a), b = find(b);
            if (a != b) {
                p[a] = b;
                siz[b] += siz[a];
            }
        }
    }

    int base = 0, idx = 0;
    FOR(i, 1, n) {
        if (i == find(i)) {
            base += (siz[i] - 1) * siz[i] / 2;
        }
    }

    int ans = base;

    FOR(i, 1, n) {
        if (s[i] == '0') {
            int tot = base, t2 = 1;
            set<int> p;
            for (auto j : g[i]) {
                if (s[j] == '1') {
                    int t = find(j);
                    p.insert(t);
                }
            }

            for (auto x : p) {
                tot -= (siz[x] - 1) * siz[x] / 2;
                t2 += siz[x];
            }

            tot += (t2 - 1) * t2 / 2;
            if (tot > ans) {
                ans = tot;
                idx = i;
            }
        }
    }

    cout << idx << ' ' << ans << endl;
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