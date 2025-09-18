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
    V<int> w(n + 1, 0);
    int mod = 998244353;
    FOR(i, 1, n) cin >> w[i];

    V<int> b;
    FOR(i, 1, n) {
        if (w[i] != -1) {
            b.eb(i);
        }
    }

    if (!sz(b)) {
        cout << (n - 1) * 200 % mod << endl;
        RE;
    } else if (sz(b) == 1) {
        int p = b[0], ans = 0;
        FOR(i, 1, n) {
            if (i < p) {
                (ans += w[p] + 1) %= mod;
            } else if (i > p) {
                if (i + 1 == n) {
                    (ans += (200 - w[p] + 1)) %= mod;
                    break;
                } else {

                    (ans += (200 - w[p] + 1)) %= mod;
                }
            }
        }
        cout << ans << endl;
    } else {
        int ans = 0;
        if (b[0] != 1) {
            (ans += (b[0] - 1) * (w[b[0]] + 1)) %= mod;
        }
        FOR(i, 1, sz(b) - 1) {
            int del = b[i] - b[i - 1] - 1;
            if (b[i] == n) {
                if (b[i - 1] < n - 1) {
                    (ans += 1) %= mod;
                }
            } else {
                (ans += (w[b[i]] - w[b[i - 1]] + 1) * del) %= mod;
            }
        }

        if (b.back() != n && b.back() != n - 1) {
            (ans += (n - b.back() - 1) * (200 - w[b.back()] + 1)) %= mod;
        } else {
            if (b.back() != n) ans++;
        }
        cout << ans << endl;
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