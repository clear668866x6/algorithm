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

void solve() {
    int n;
    cin >> n;
    V<int>w(n);
    for (auto& x : w)cin >> x;

    V<V<int>>g(n + 2);
    V<int>d(n + 2, 0);

    FOR(i, 1, n - 1){
        g[i].eb(i + 1);
        d[i + 1]++;
    }

    FOR(i, 0, n - 1){
        if (w[i] == 0){
            g[i + 1].eb(n + 1);
            d[n + 1]++;
        } else{
            g[n + 1].eb(i + 1);
            d[i + 1]++;
        }
    }

    V<int>vis(n + 2, 0), ans;
    int tot = 0;

    function<bool(int)>dfs = [&](int u)->bool{
        vis[u] = 1;
        tot--;
        if (!tot){
            ans.eb(u);
            return true;
        }
        for (auto& j : g[u]){
            if (vis[j])continue;
            if (dfs(j)){
                ans.eb(u);
                return true;
            }
        }
        tot++;
        vis[u] = 0;
        return false;
        };


    FOR(i, 1, n + 1){
        tot = n + 1;
        fill(ALL(vis), 0);
        if (dfs(i)){
            reverse(ALL(ans));
            for (auto x : ans)cout << x << ' ';
            cout << endl;
            RE;
        }
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    while (Task--) {
        solve();
    }

    return 0;
}