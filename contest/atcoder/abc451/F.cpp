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
    int n, q;
    cin >> n >> q;

    V<int> p(n + 1, 0);
    V<array<int, 2>> s(n + 1);
    V<int> c(n + 1, 0);
    iota(ALL(p), 0ll);
    FOR(i, 1, n) {
        s[i][0] = 1;
        s[i][1] = 0;
    }

    function<int(int)> find = [&](int x) {
        if (x != p[x]) {
            int rt = find(p[x]);
            c[x] ^= c[p[x]];
            return p[x] = rt;
        }
        return p[x];
    };

    bool f = false;
    int ans = 0;

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (f) {
            cout << -1 << endl;
            continue;
        }
        int a = find(x), b = find(y);
        if (a == b) {
            if (c[x] == c[y]) {
                cout << -1 << endl;
                f = 1;
            } else {
                cout << ans << endl;
            }
        } else {
            ans -= (min(s[a][0], s[a][1]) + min(s[b][0], s[b][1]));

            p[b] = a;
            c[b] = c[x] ^ c[y] ^ 1;

            if (!c[b]) {
                s[a][0] += s[b][0];
                s[a][1] += s[b][1];
            } else {
                s[a][0] += s[b][1];
                s[a][1] += s[b][0];
            }

            ans += min(s[a][0], s[a][1]);

            cout << ans << endl;
        }
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