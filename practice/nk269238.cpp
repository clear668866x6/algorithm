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

    V<int>w (n + 1, 0);

    map<int, V<int>>mp;

    int mx = 0;

    FOR (i, 1, n) {
        cin >> w[i];
        mx = max (mx, w[i]);
        mp[w[i]].eb (i);
    }

    FOR (i, 1, mx) {
        if (!mp[i].sz) {
            cout << -1 << endl;
            RE;
        }
    }

    V<PII>ans;

    FOR (i, 0, mx - 1) {
        FOR (j, 0, mp[i + 1].sz - 1) {
            ans.pb ({ mp[i].back (),mp[i + 1][j] });
        }
    }

    if (ans.sz > m) {
        cout << -1 << endl;
        RE;
    }

    m -= (ans.sz);

    int idx = 1;
    while (m) {
        if (idx > mx) {
            break;
        }
        int t = mp[idx].sz;
        if (m >= t * (t - 1) / 2) {
            m -= t * (t - 1) / 2;
            FOR (i, 0, t - 1) {
                FOR (j, i + 1, t - 1) {
                    ans.pb ({ mp[idx][i],mp[idx][j] });
                }
            }
        } else {
            FOR (i, 0, t - 1) {
                FOR (j, i + 1, t - 1) {
                    if (!m) {
                        for (auto [x, y] : ans) {
                            cout << x << ' ' << y << endl;
                        }
                        RE;
                    }
                    m--;
                    ans.pb ({ mp[idx][i],mp[idx][j] });
                }
            }
        }
        idx++;
    }

    idx = 1;

    while (m) {
        if (idx >= mx)break;

        FOR (i, 0, mp[idx].sz - 2) {
            FOR (j, 0, mp[idx + 1].sz - 1) {
                if (!m) {
                    for (auto [x, y] : ans) {
                        cout << x << ' ' << y << endl;
                    }
                    RE;
                }
                m--;
                ans.pb ({ mp[idx][i],mp[idx + 1][j] });
            }
        }
        idx++;
    }

    if (m > 0) {
        cout << -1 << endl;
        RE;
    }
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
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