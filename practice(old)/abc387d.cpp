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

void solve() {
    int n, m;
    cin >> n >> m;
    V<V<char>>s(n + 1, V<char>(m + 1, 0));

    int sx = 0, sy = 0, ex = 0, ey = 0;

    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> s[i][j];
            if (s[i][j] == 'S'){
                sx = i, sy = j;
            }
        }
    }

    array<int, 4>dx = { 0,0,1,-1 }, dy = { -1,1,0,0 };

    struct E{
        int x, y, step, state;
        bool operator<(const E& t)const{
            return step > t.step;
        }
    };

    priority_queue<E>q;
    q.push({ sx,sy,0,0 });
    q.push({ sx,sy,0,1 });

    V<V<V<int>>>vis(n + 2, V<V<int>>(m + 2, V<int>(2, 0)));

    while (q.sz){
        auto [x, y, step, state] = q.top();
        q.pop();

        if (s[x][y] == 'G'){
            cout << step;
            RE;
        }

        int l = (state ? 0 : 2);
        int r = (state ? 1 : 3);

        FOR(i, l, r){
            int a = dx[i] + x, b = dy[i] + y;
            if (a<1 || b<1 || a>n || b>m || vis[a][b][state ^ 1] || s[a][b] == '#')continue;
            q.push({ a,b ,step + 1,state ^ 1 });
            vis[a][b][state ^ 1] = true;
        }
    }

    cout << -1 << endl;

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