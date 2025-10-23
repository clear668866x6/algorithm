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
    cin >> n >> m;

    V<array<int, 2>> w(m);
    V<int> ans(n + 1, -1);

    FOR(i, 0, m - 1) cin >> w[i][0] >> w[i][1];

    sort(ALL(w));

    if (n == 1) {
        if (!m) {
            cout << 0 << endl;
        } else {
            cout << w[0][1] << endl;
        }
        RE;
    }

    if (m == 1) {
        if (w[0][0] == 1) {
            int t = w[0][1];
            FOR(i, 1, n) {
                ans[i] = t;
                if (t > 0) t--;
            }
        } else {
            int t = w[0][1];
            FORD(i, 1, w[0][0]) {
                ans[i] = t;
                if (t > 0) t--;
            }
            t = w[0][1];
            FOR(i, w[0][0], n) {
                ans[i] = t;
                if (t > 0) t--;
            }
        }
        if (ans[1] == 0) ans[1] = 1;
        FOR(i, 1, n) cout << ans[i];
        RE;
    }

    if (w[0][0] == 1 && w[0][1] == 0) {
        cout << -1 << endl;
        RE;
    }

    FOR(i, 1, m - 1) {
        if (w[i][1] - w[i - 1][1] > w[i][0] - w[i - 1][0]) {
            cout << -1 << endl;
            RE;
        }
    }

    if (w[0][0] != 1) {
        int t = w[0][1];
        FORD(i, 1, w[0][0]) {
            ans[i] = t;
            if (t > 0) t--;
        }

        FOR(i, 1, m - 1) {
            int l = w[i - 1][0], r = w[i][0];
            int L = w[i - 1][1] - 1, R = w[i][1];
            FORD(j, l, r) {
                if (ans[j] == -1) {
                    ans[j] = R;
                    if (R > 0) R--;
                }
            }
            FOR(j, l, r) {
                if (ans[j] == -1) {
                    ans[j] = L;
                    if (L > 0) L--;
                } else {
                    if (abs(ans[j - 1] - ans[j]) > 1) {
                        ans[j] = L;
                        if (L > 0) L--;
                    }
                }
            }
            // cout << "func " << i << endl;
            // FOR(i, 1, n) cout << ans[i];
            // cout << endl;
        }

        int p = w[m - 1][1];
        if (w[m - 1][0] != n) {
            FOR(i, w[m - 1][0], n) {
                ans[i] = p;
                if (p > 0) p--;
            }
        }

        if (ans[1] == 0) ans[1] = 1;
        FOR(i, 1, n) cout << ans[i];

    } else {
        FOR(i, 1, m - 1) {
            int l = w[i - 1][0], r = w[i][0];
            int L = w[i - 1][1], R = w[i][1];
            FORD(j, l, r) {
                if (ans[j] == -1) {
                    ans[j] = R;
                    if (R > 0) R--;
                }
            }
            ans[l] = L--;
            FOR(j, l + 1, r) {
                if (ans[j] == -1) {
                    ans[j] = L;
                    if (L > 0) L--;
                } else {
                    if (abs(ans[j - 1] - ans[j]) > 1) {
                        ans[j] = L;
                        if (L > 0) L--;
                    }
                }
            }
        }
        int p = w[m - 1][1];
        if (w[m - 1][0] != n) {
            FOR(i, w[m - 1][0], n) {
                ans[i] = p;
                if (p > 0) p--;
            }
        }

        if (ans[1] == 0) ans[1] = 1;
        FOR(i, 1, n) cout << ans[i];
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