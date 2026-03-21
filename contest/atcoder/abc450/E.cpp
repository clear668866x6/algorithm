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
    string a, b;
    cin >> a >> b;
    int q;
    cin >> q;

    V<int> c1(30, 0), c2(30, 0);
    V<V<int>> cnt;
    for (auto x : a) c1[x - 'a']++;
    for (auto x : b) c2[x - 'a']++;
    cnt.eb(V<int>(30, 0));
    cnt.eb(c1);
    cnt.eb(c2);
    V<int> L(1, 0);
    L.eb(sz(a));
    L.eb(sz(b));
    int ct = 2;
    while (L[ct] <= (int)1e18) {
        L.eb(L[ct] + L[ct - 1]);
        ct++;
        V<int> cn(30, 0);
        FOR(j, 0, 29) {
            cn[j] = cnt[ct - 1][j] + cnt[ct - 2][j];
        }
        cnt.eb(cn);
    }

    auto dfs = [&](auto &&dfs, int n, int r, char c) -> int {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            int t = 0;
            FOR(i, 0, r - 1) t += (a[i] == c);
            return t;
        }
        if (n == 2) {
            int t = 0;
            FOR(i, 0, r - 1) t += (b[i] == c);
            return t;
        }

        if (r <= L[n - 1]) {
            return dfs(dfs, n - 1, r, c);
        } else {
            return dfs(dfs, n - 2, r - L[n - 1], c) + cnt[n - 1][c - 'a'];
        }
    };

    while (q--) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        cout << dfs(dfs, ct, r, c) - dfs(dfs, ct, l - 1, c) << endl;
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