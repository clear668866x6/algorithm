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

    int tot = 0;
    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> w[i][j];
            tot += (w[i][j] == '.');
        }
    }

    array<int, 4>dx = { -1,0,1,0 }, dy = { 0,1,0,-1 };

    int mod = 998244353;

    map<PII, set<int>>s;

    V<V<int>>vis (n + 1, V<int> (m + 1, 0));

    function<void (int, int, int)>bfs = [&] (int x1, int y1, int idx) {
        queue<PII>q;
        q.push ({ x1,y1 });

        while (q.sz) {
            auto [x, y] = q.front ();
            q.pop ();

            FOR (i, 0, 3) {
                int a = dx[i] + x, b = dy[i] + y;
                if (a<1 || b<1 || a>n || b>m || vis[a][b])continue;
                if (w[a][b] == '.') {
                    s[{a, b}].insert (idx);
                    continue;
                }
                q.push ({ a,b });
                vis[a][b] = 1;
            }
        }
        };

    int cnt = 0, ans = 0;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            if (w[i][j] == '#' && !vis[i][j]) {
                vis[i][j] = 1;
                bfs (i, j, ++cnt);
            }
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            if (w[i][j] == '.') {
                (ans += (cnt - (int)s[{i, j}].sz + 1)) %= mod;
            }
        }
    }

    function<int (int, int)>qmi = [&] (int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1)res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
        };

    cout << ans * qmi (tot, mod - 2) % mod;

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