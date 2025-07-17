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

    V<V<char>>s (n + 1, V<char> (m + 1, 0));
    V<V<int>>d (n + 1, V<int> (m + 1, 1e18));
    queue<PII>q;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> s[i][j];
            if (s[i][j] == 'E') {
                q.push ({ i,j });
                d[i][j] = 0;
            }
        }
    }

    array<int, 4>dx = { -1,0,1,0 }, dy = { 0,1,0,-1 };

    while (q.sz) {
        auto [x, y] = q.front ();
        q.pop ();

        FOR (i, 0, 3) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a<1 || b<1 || a>n || b>m || s[a][b] == '#')continue;
            if (d[a][b] > d[x][y] + 1) {
                d[a][b] = d[x][y] + 1;
                q.push ({ a,b });
            }
        }
    }

    function<char (int)>calc = [&] (int x) {
        if (x == 0)return '^';
        if (x == 1)return '>';
        if (x == 2)return 'v';
        return '<';
        };

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            if (s[i][j] == '.') {
                int t = 1e18, idx = 0;
                FOR (k, 0, 3) {
                    int a = dx[k] + i, b = dy[k] + j;
                    if (a<1 || b<1 || a>n || b>m || s[a][b] == '#')continue;
                    if (t > d[a][b]) {
                        t = d[a][b];
                        idx = k;
                    }
                }
                cout << calc (idx);
            } else {
                cout << s[i][j];
            }
        }
        cout << endl;
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