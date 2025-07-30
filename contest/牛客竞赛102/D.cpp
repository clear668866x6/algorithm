#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve () {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    V<V<V<int>>>f (n + 2, V<V<int>> (4, V<int> (2, 1e18)));

    f[1][0][0] = (s[1] == '1');
    f[1][0][1] = (s[1] == '0');

    FOR (i, 2, n) {
        FOR (j, 0, 3) {
            FOR (k, 0, 1) {
                FOR (kk, 0, 1) {
                    int t = j;
                    if (k != kk) {
                        t--;
                        if (t < 0 || f[i - 1][t][k] == 1e18)continue;
                    }
                    int cost = ((s[i] - '0') != kk);

                    f[i][j][kk] = min (f[i - 1][t][k] + cost, f[i][j][kk]);
                }
            }
        }
    }

    cout << min (f[n][3][0], f[n][3][1]);


}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}