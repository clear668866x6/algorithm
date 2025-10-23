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
    int n, q;
    cin >> n >> q;

    V<int>w (n + 1, 0);
    V<V<PII>>g (n + 1);

    FOR (i, 1, n)cin >> w[i];

    FOR (i, 1, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb (b, c);
        g[b].eb (a, c);
    }

    int ans = 0;

    V<unordered_map<int, int>>cc (n + 1);

    FOR (u, 1, n) {
        for (auto [j, c] : g[u]) {
            cc[u][w[j]] += c;
        }
    }

    FOR (u, 1, n) {
        for (auto [j, c] : g[u]) {
            if (u < j) {
                if (w[u] != w[j]) {
                    ans += c;
                }
            }
        }
    }

    while (q--) {
        int v, x;
        cin >> v >> x;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        if (w[v] == x) {
            cout << ans << endl;
            continue;
        }
        for (auto [j, c] : g[v]) {
            if (w[j] != w[v] && w[j] == x) {
                ans -= c;
            } else if (w[j] == w[v] && w[j] != x) {
                ans += c;
            }
        }
        cout << ans << endl;
        w[v] = x;
    }

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}