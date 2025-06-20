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
    int n, k, q;
    string s, t;
    cin >> n >> k >> s >> q;

    V<V<int>>ne (n + 2, V<int> (k + 1, n + 1));
    s = ' ' + s;
    FORD (i, 0, n - 1) {
        ne[i] = ne[i + 1];
        ne[i][s[i + 1] - 'a'] = i + 1;
    }

    V<int>f (n + 2, n);
    f[n + 1] = 0;
    f[n] = 1;

    FORD (i, 0, n - 1) {
        FOR (j, 0, k - 1) {
            f[i] = min (f[i], f[ne[i][j]] + 1);
        }
    }

    while (q--) {
        cin >> t;
        int m = t.sz;
        t = ' ' + t;
        int cur = 0;
        FOR (j, 1, m) {
            if (cur > n)break;
            cur = ne[cur][t[j] - 'a'];
        }
        cout << f[cur] << endl;
    }

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