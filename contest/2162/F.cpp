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
    V<array<int, 2>> w(m + 1);

    FOR(i, 1, m) cin >> w[i][0] >> w[i][1];

    int l = 1, r = n;
    FOR(i, 1, m) {
        l = max(l, w[i][0]);
        r = min(r, w[i][1]);
    }

    V<int> ans(n + 1, -1);
    int num = 1;

    if (l <= r) {
        ans[l] = 0;
        FOR(i, 1, n) {
            if (ans[i] == -1) {
                ans[i] = num++;
            }
        }
    } else {
        bool f = false;
        FOR(i, 1, n) {
            if (f) break;
            for (auto j : {i - 1, i + 1}) {
                if (j < 1 || j > n) continue;
                bool ff = false;
                FOR(k, 1, m) {
                    if (i >= w[k][0] && i <= w[k][1]) {
                        if (!(j >= w[k][0] && j <= w[k][1])) {
                            ff = 1;
                            break;
                        }
                    }
                }
                if (!ff) {
                    ans[i] = 0;
                    ans[j] = 1;
                    int num = 2;
                    FOR(k, 1, n) {
                        if (ans[k] == -1) {
                            ans[k] = num++;
                        }
                    }
                    f = 1;
                    break;
                }
            }
        }

        if (!f) {
            ans[1] = 0;
            ans[n] = 1;
            int num = 2;
            FOR(k, 1, n) {
                if (ans[k] == -1) {
                    ans[k] = num++;
                }
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
