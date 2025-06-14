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
    V<V<char>>w (n + 1, V<char> (m + 1, 0));

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> w[i][j];
        }
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    priority_queue < array<int, 3>, V < array<int, 3>>, greater<array<int, 3>>>q;

    q.push ({ 0,a,b });

    V<V<int>>vis (n + 1, V<int> (m + 1, 0));
    vis[a][b] = 1;

    array<int, 4>dx = { 0,1,0,-1 }, dy = { 1,0,-1,0 };
    array<int, 4>dx2 = { 0,2,0,-2 }, dy2 = { 2,0,-2,0 };

    int ans = 1e18;

    while (q.sz) {
        auto [step, x, y] = q.top ();
        q.pop ();

        if (x == c && y == d) {
            ans = min (ans, step);
            break;
        }

        FOR (i, 0, 3) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a<1 || b<1 || a>n || b>m || vis[a][b])continue;
            if (w[a][b] == '#') {
                vis[a][b] = 1;
                q.push ({ step + 1 ,a,b });
            }
            else {
                vis[a][b] = 1;
                q.push ({ step ,a,b });
            }
        }
        FOR (i, 0, 3) {
            int a = dx2[i] + x, b = dy2[i] + y;
            if (a<1 || b<1 || a>n || b>m || vis[a][b])continue;
            if (w[a][b] == '#') {
                vis[a][b] = 1;
                q.push ({ step + 1,a,b });
            }
        }
    }

    cout << ans;

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