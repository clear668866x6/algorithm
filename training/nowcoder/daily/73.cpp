#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;
    V<V<int>> w(n + 1, V<int>(n + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> w[i][j];
        }
    }

    if (n == 1) {
        YES;
        RE;
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    V<V<int>> vis(n + 1, V<int>(n + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            int cnt = 0, cnt2 = 0, cnt3 = 0;
            set<int> s;
            FOR(k, 0, 3) {
                int a = dx[k] + i, b = dy[k] + j;
                if (a < 1 || b < 1 || a > n || b > n) continue;
                if (w[i][j] < w[a][b]) {
                    cnt++;
                }
                if (w[i][j] > w[a][b]) cnt3++;
                s.insert(w[a][b]);
                cnt2++;
            }

            if (cnt == cnt2) {
                w[i][j] = *s.begin();
            }
            if (cnt3 == cnt2) {
                w[i][j] = *s.rbegin();
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            FOR(k, 0, 3) {
                int a = dx[k] + i, b = dy[k] + j;
                if (a < 1 || b < 1 || a > n || b > n) continue;
                if (w[a][b] == w[i][j]) {
                    vis[i][j] = vis[a][b] = 1;
                }
            }
        }
    }

    set<int> s;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (vis[i][j]) s.insert(w[i][j]);
        }
    }

    if (sz(s) == 1) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                if (w[i][j] != 0) {
                    NO;
                    RE;
                }
            }
        }
        YES;
    } else {
        NO;
    }
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