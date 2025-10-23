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

    V<V<int>>w (n + n, V<int> (n + n, 0));

    int t = 0, cnt = 1, idx = 0;

    int x = (n + 1) / 2, y = (n + 1) / 2;

    array<int, 4>dx = { 0,1,0,-1 }, dy = { 1,0,-1,0 };

    while (1) {
        if (w[x][y] || x<1 || y<1 || x>n || y>n)break;
        int p = cnt;
        bool f = false;
        while (p--) {
            if (w[x][y] || x<1 || y<1 || x>n || y>n) {
                f = 1;
                break;
            }
            w[x][y] = t++;
            x += dx[idx], y += dy[idx];
        }
        (idx += 1) %= 4;


        if (f)break;
        p = cnt;
        while (p--) {
            if (w[x][y] || x<1 || y<1 || x>n || y>n) {
                f = 1;
                break;
            }
            w[x][y] = t++;
            x += dx[idx], y += dy[idx];
        }
        if (f)break;
        (idx += 1) %= 4;
        cnt++;
    }

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            cout << w[i][j] << " ";
        }
        cout << endl;
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