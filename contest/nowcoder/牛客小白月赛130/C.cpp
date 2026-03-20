#include <algorithm>
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
    int n, m;
    cin >> n >> m;

    V<int> d(m + 1, 0);
    V<V<int>> g(n + 1), g2(m + 1);
    FOR(i, 1, n) {
        int a, b;
        cin >> a >> b;
        d[a]++, d[b]++;
        g[i].eb(a);
        g[i].eb(b);
        g2[a].eb(i);
        g2[b].eb(i);
    }

    V<array<int, 2>> e(m + 1);
    FOR(i, 1, m) {
        e[i] = {d[i], i};
    }
    sort(ALL(e));
    int cnt = 0;
    FORD(i, 1, m) {
        if (e[i][0] == e[m][0]) cnt++;
    }

    int ans = 0;

    if (cnt == 1) {
        int t = e[m][1], cmx = e[m - 1][0];
        V<int> vis(n + 1, 0), vis2(m + 1, 0);
        set<int> s;
        FORD(i, 1, m - 1) {
            if (e[i][0] == e[m - 1][0]) {
                s.insert(e[i][1]);
                vis2[e[i][1]] = cmx;
            } else {
                break;
            }
        }
        for (auto x : g2[t]) {
            vis[x] = 1;
        }

        FOR(i, 1, n) {
            if (vis[i]) {
                for (auto x : g[i]) {
                    if (x == t) continue;
                    vis2[x]--;
                }
            }
        }

        int ans = 0, base = e[m][0];

        FOR(i, 1, m) {
            ans = max(ans, base + vis2[i]);
        }

        cout << ans << endl;

    } else {

        int tt = cnt * (cnt - 1) / 2;

        int mx = e[m][0];
        if (tt > n) {
            cout << 2 * mx << endl;
            RE;
        }

        V<int> vis(m + 1, 0), vis2(m + 1, 0), vis3(n + 1, 0);
        set<int> s;
        FORD(i, 1, m) {
            if (e[i][0] == e[m][0]) {
                vis[e[i][1]] = 1;
                vis2[e[i][1]] = mx;
                s.insert(e[i][1]);
            } else {
                break;
            }
        }

        int ans = 0, base = mx;

        FORD(i, 1, m) {
            if (e[i][0] == e[m][0]) {
                for (auto x : g2[e[i][1]]) {
                    for (auto y : g[x]) {
                        vis2[y]--;
                    }
                }

                int mx2 = 0;
                for (auto x : s) {
                    if (x != e[i][1]) {
                        mx2 = max(mx2, vis2[x]);
                    }
                }

                ans = max(ans, base + mx2);

                for (auto x : g2[e[i][1]]) {
                    for (auto y : g[x]) {
                        vis2[y]++;
                    }
                }
            } else {
                break;
            }
        }

        cout << ans << endl;
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