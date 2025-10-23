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

    V<V<int>>w (n + 1, V<int> (m + 1, 0));

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> w[i][j];
        }
    }

    int N, M;
    cin >> N >> M;

    V<V<int>>c (N + 1, V<int> (M + 1, 0));

    FOR (i, 1, N) {
        FOR (j, 1, M) {
            cin >> c[i][j];
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            if (w[i][j] == c[1][1]) {
                if (i + N - 1 <= n && j + M - 1 <= m) {
                    bool f = false;
                    FOR (a, i, i + N - 1) {
                        FOR (b, j, j + M - 1) {
                            if (w[a][b] != c[a - i + 1][b - j + 1]) {
                                f = 1;
                                break;
                            }
                        }
                        if (f)break;
                    }
                    if (!f) {
                        Yes;
                        RE;
                    }
                }
            }
        }
    }

    No;

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