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

int mod = 998244353;

void solve() {
    int n;
    cin >> n;

    V<V<int>> A(n, V<int>(4, 0));

    FOR(i, 0, n - 1) {
        FOR(j, 0, 3) {
            cin >> A[i][j];
        }
    }

    auto calc = [&](int x, int k) {
        int T = (1LL << k);
        return x / (1LL << (k + 1)) * T + max<int>(0, x % (1LL << (k + 1)) - T);
    };

    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int k, c, v;
            cin >> k >> c >> v;
            A[k][c] = v % mod;
        } else {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;

            int ans = 0;

            FOR(k, 0, n - 1) {
                int r1_cnt = calc(r2 + 1, k) - calc(r1, k);
                int r0_cnt = (r2 - r1 + 1) - r1_cnt;
                int c1_cnt = calc(c2 + 1, k) - calc(c1, k);
                int c0_cnt = (c2 - c1 + 1) - c1_cnt;

                ans = (ans + (i128)A[k][0] * r0_cnt % mod * c0_cnt % mod) % mod;
                ans = (ans + (i128)A[k][1] * r0_cnt % mod * c1_cnt % mod) % mod;
                ans = (ans + (i128)A[k][2] * r1_cnt % mod * c0_cnt % mod) % mod;
                ans = (ans + (i128)A[k][3] * r1_cnt % mod * c1_cnt % mod) % mod;
            }
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