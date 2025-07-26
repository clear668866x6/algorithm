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

    V<V<int>>d (n + 1, V<int> (n + 1, 1e17));

    FOR (i, 1, n)d[i][i] = 0;

    FOR (i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min (d[a][b], c);
        d[b][a] = min (d[b][a], c);
    }

    int k, T, q;
    cin >> k >> T;

    V<int>fj, isfj (n + 1, 0), air (n + 1, 1e18);

    FOR (i, 0, k - 1) {
        int x;
        cin >> x;
        if (!isfj[x]) {
            isfj[x] = 1;
            fj.eb (x);
        }
    }

    FOR (k, 1, n) {
        FOR (i, 1, n) {
            FOR (j, 1, n) {
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            if (isfj[j]) {
                air[i] = min (air[i], d[i][j]);
            }
        }
    }
    cin >> q;

    while (q--) {
        int op, x, y, t;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> t;
            d[x][y] = d[y][x] = min (d[x][y], t);
            FOR (i, 1, n) {
                FOR (j, 1, n) {
                    d[i][j] = min (d[i][j], d[i][x] + t + d[y][j]);
                    d[i][j] = min (d[i][j], d[i][y] + t + d[x][j]);
                }
            }
            FOR (i, 1, n) {
                FOR (j, 1, n) {
                    if (isfj[j]) {
                        air[i] = min (air[i], d[i][j]);
                    }
                }
            }


        } else if (op == 2) {
            cin >> x;
            if (!isfj[x]) {
                isfj[x] = 1;

                FOR (i, 1, n) {
                    air[i] = min (air[i], d[i][x]);
                }
                fj.eb (x);
            }
        } else {
            int ans = 0;

            FOR (i, 1, n) {
                FOR (j, 1, n) {
                    if (min (d[i][j], air[i] + air[j] + T) < 1e17) {
                        ans += min (d[i][j], air[i] + air[j] + T);
                    }
                }
            }
            cout << ans << endl;
        }
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