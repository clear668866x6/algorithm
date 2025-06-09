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
    V<V<PII>>g (n + 1);

    FOR (i, 2, n){
        int fa, w;
        cin >> fa >> w;
        g[i].eb (fa, w);
        g[fa].eb (i, w);
    }

    V<V<int>>f (n + 1, V<int> (3, 0));

    FOR (i, 1, n){
        for (auto& [j, w] : g[i]){
            if (w <= 2){
                f[i][w]++;
            }
        }
    }

    FOR (i, 1, n){
        int ans = 1 + f[i][1] + f[i][2];
        for (auto [j, w] : g[i]){
            if (w == 1){
                ans += f[j][w] - 1;
            }
        }
        cout << ans << endl;
    }

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}