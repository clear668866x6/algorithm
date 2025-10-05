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
    V<V<char>> s(n + 1, V<char>(m + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
        }
    }

    string p = " narek";
    map<char, int> mp;

    FOR(i, 1, 5) mp[p[i]] = i;

    V<V<int>> f(n + 1, V<int>(6, -1e18));

    f[0][1] = 0;

    FOR(i, 1, n) {
        FOR(j, 1, 5) f[i][j] = f[i - 1][j];
        f[i][1] = max<int>(0, f[i][1]);
        FOR(j, 1, 5) {
            int t = j;
            int s1 = 0, s2 = 0;
            FOR(k, 1, m) {
                if (mp[s[i][k]]) {
                    if (mp[s[i][k]] == t) {
                        if (t == 5) {
                            s1 += 5;
                        }
                        if (t == 5) {
                            t = 1;
                        } else {
                            t++;
                        }
                    } else {
                        s2++;
                    }
                }
            }
            f[i][t] = max(f[i][t], f[i - 1][j] + (s1 - s2));
        }
    }

    int ans = 0;

    FOR(i, 1, 5) {
        ans = max(ans, f[n][i] - (i - 1));
    }

    cout << ans << endl;
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
