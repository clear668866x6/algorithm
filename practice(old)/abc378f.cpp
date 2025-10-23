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
    V<V<int>>g (n + 1);
    V<int>d (n + 1, 0);

    FOR (i, 2, n){
        int a, b;
        cin >> a >> b;
        g[a].eb (b);
        g[b].eb (a);
        d[a]++, d[b]++;
    }

    V<int>vis (n + 1, 0);
    int cnt = 0;
    function<void (int, int)>dfs = [&] (int u, int fa){
        if (d[u] != 3){//之前那么写就是忘了度数不止1,2,3，还有4+
            if (d[u] == 2)cnt++;
            RE;
        }
        vis[u] = 1;

        for (auto& j : g[u]){
            if (j == fa && vis[j])continue;
            dfs (j, u);
        }
        };

    int ans = 0;

    FOR (i, 1, n){
        if (!vis[i] && d[i] == 3){
            cnt = 0;
            dfs (i, 0);
            ans += (cnt - 1) * cnt / 2;
        }
    }
    cout << ans << endl;

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