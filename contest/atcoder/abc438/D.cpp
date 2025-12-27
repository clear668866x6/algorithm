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

struct ST {
    V<V<int>> f;
    int n;
    ST() {}
    ST(int x, V<int> w) {
        f.resize(x + 10, V<int>(22, -1e18));
        n = x;
        FOR(j, 0, 20) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                if (!j)
                    f[i][j] = w[i];
                else
                    f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = __lg(r - l + 1);

        return max(f[l][len], f[r - (1 << len) + 1][len]);
    }
};

void solve() {
    int n;
    cin >> n;

    V<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    V<int> sa(n + 1, 0), sb(n + 1, 0), sc(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n) cin >> c[i];

    FOR(i, 1, n) sa[i] = sa[i - 1] + a[i];
    FOR(i, 1, n) sb[i] = sb[i - 1] + b[i];
    FOR(i, 1, n) sc[i] = sc[i - 1] + c[i];

    V<int> mx(n + 1, -1e18);

    FORD(i, 2, n - 1) {
        mx[i] = max(mx[i + 1], sb[i] - sc[i]);
    }

    ST A(n, mx);

    int ans = 0;

    FOR(x, 1, n - 2) {
        int t1 = sa[x] - sb[x] + sc[n];
        int t2 = A.query(x + 1, n - 1);
        ans = max(ans, t1 + t2);
    }

    cout << ans;
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