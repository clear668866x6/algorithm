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
    int h, w;
    cin >> h >> w;

    V<V<int>>a (h, V<int> (w, 0));

    FOR (i, 0, h - 1) {
        FOR (j, 0, w - 1) {
            cin >> a[i][j];
        }
    }

    V<int>p (h + w - 1, 0);

    FOR (i, 0, h + w - 2)cin >> p[i];

    int l = -1, r = 4e15;

    function<int (int)>check = [&] (int x) {
        V<V<int>>f (h, V<int> (w, -1));
        int d = 0;

        if (x + a[0][0] >= p[d]) {
            f[0][0] = x + a[0][0] - p[d];
        }

        FOR (i, 0, h - 1) {
            FOR (j, 0, w - 1) {
                if (!i && !j)continue;
                d = i + j;
                if (i > 0 && f[i - 1][j] != -1) {
                    int t = f[i - 1][j];
                    if (f[i - 1][j] + a[i][j] >= p[d]) {
                        f[i][j] = max (f[i][j], f[i - 1][j] + a[i][j] - p[d]);
                    }
                }
                if (j > 0 && f[i][j - 1] != -1) {
                    int t = f[i][j - 1];
                    if (f[i][j - 1] + a[i][j] >= p[d]) {
                        f[i][j] = max (f[i][j], f[i][j - 1] + a[i][j] - p[d]);
                    }
                }
            }
        }
        return f[h - 1][w - 1] != -1;

        };

    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (check (mid))r = mid;
        else l = mid;
    }
    cout << r << endl;

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