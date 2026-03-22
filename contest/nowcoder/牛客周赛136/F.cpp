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
    int n, k;
    cin >> n >> k;

    V<array<int, 2>> ans(1, {0, 0});

    int a = 1, b = 1;

    while (k > 0) {
        if (a == b) {
            if (k - 1 >= 0) {
                k--;
                ans.pb({a, 0});
            } else {
                break;
            }

            bool f = false;
            FOR(i, 1, b - 1) {
                if (!k) {
                    f = 1;
                    break;
                }
                if (k - 2 >= 0) {
                    ans.pb({a, i});
                    k -= 2;
                } else if (k == 1) {
                    ans.pb({a + 1, 0});
                    k--;
                    f = 1;
                    break;
                }
            }
            if (f) break;
            a++;
        } else {
            if (k - 1 >= 0) {
                k--;
                ans.pb({0, b});
            } else {
                break;
            }

            bool f = false;
            FOR(i, 1, a - 1) {
                if (!k) {
                    f = 1;
                    break;
                }
                if (k - 2 >= 0) {
                    ans.pb({i, b});
                    k -= 2;
                } else if (k == 1) {
                    ans.pb({0, b + 1});
                    k = 0;
                    f = 1;
                    break;
                }
            }
            if (f) break;
            b++;
        }
    }

    if (sz(ans) > n) {
        No;
    } else {
        int t = n - sz(ans);
        int c = -1e9;
        while (t--) {
            ans.pb({c, (int)1e9});
            c += 2;
        }
        Yes;
        for (auto [x, y] : ans) cout << x << ' ' << y << endl;
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