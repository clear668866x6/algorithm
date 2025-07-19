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
    int n, m;
    cin >> n >> m;

    if (m<n || m>n * (n + 1) / 2) {
        cout << -1 << endl;
        RE;
    }

    V<int>vis (n + 1, 0), d (n + 1, 0);

    m -= n;

    FOR (i, 1, n) {
        if (m > n - i) {
            d[i] = n - i + 1;
            m -= (n - i);
        } else {
            d[i] = m + 1;
            m = 0;
            FOR (j, 1, i)vis[d[j]] = 1;
            int p = 1;
            FOR (j, i + 1, n) {
                while (vis[p])p++;
                d[j] = p;
                vis[p] = 1;
            }
            cout << d[1] << endl;
            FOR (i, 1, n - 1)cout << d[i] << ' ' << d[i + 1] << endl;
            break;
        }
    }



}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}