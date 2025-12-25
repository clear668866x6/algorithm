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

    V<int> c;

    auto dfs = [&](auto &&dfs, int u) -> void {
        if (u > 16) {
            int a = 0;
            int t = sz(c);
            FOR(i, 0, t - 1) {
                a = a * 4 + c[i];
            }

            int b = a - n;

            FOR(i, 0, 63) {
                if (!(i & 1)) {
                    if (b >> i & 1) {
                        RE;
                    }
                }
            }

            V<int> ans;

            FOR(i, 0, 63) {
                if (i & 1) {
                    ans.eb(b >> i & 1);
                } else {
                    ans.eb(a >> i & 1);
                }
            }

            while (sz(ans) > 1 && ans.back() == 0) ans.pop_back();

            reverse(ALL(ans));

            for (auto x : ans) cout << x;

            exit(0);
        }

        c.eb(0);
        dfs(dfs, u + 1);
        c.pop_back();
        c.eb(1);
        dfs(dfs, u + 1);
        c.pop_back();
    };

    dfs(dfs, 1);
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