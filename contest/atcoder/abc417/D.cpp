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
    cin >> n;

    V<int>p (n + 1, 0), a (n + 1, 0), b (n + 1, 0);

    FOR (i, 1, n)cin >> p[i] >> a[i] >> b[i];

    int tot = 0;

    FOR (i, 1, n)tot += b[i];

    int q;
    cin >> q;
    map<int, int>mp;
    V<int>d;

    FOR (i, 1, q) {
        int x;
        cin >> x;
        mp[x] = 1;
        d.eb (x);
    }

    for (auto& [x, y] : mp) {
        if (x > tot * 3)y = x - tot;
        else {
            int t = x;
            FOR (i, 1, n) {
                if (p[i] >= t)t += a[i];
                else t = max<int> (0, t - b[i]);
            }
            y = t;
        }
    }

    FOR (i, 1, q) {
        cout << mp[d[i - 1]] << endl;
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