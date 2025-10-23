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
/*
1
7
1 2 3 4 5 6 7
7 4 3 2 6 5 1

*/
void solve() {
    int n;
    cin >> n;
    V<int>a(n), b(n), c(n, 0);
    for (auto& x : a)cin >> x;
    for (auto& x : b)cin >> x;

    if (a == b){
        cout << -1 << endl;
        RE;
    }

    set<PII>s;

    FOR(i, 0, n - 1){
        s.insert({ a[i],b[i] });
    }

    FOR(i, 0, n - 1){
        if (!s.count({ a[i],b[i] })){
            cout << -1 << endl;
            RE;
        }
    }

    V<V<int>>g(n + 1);
    V<PII>ans, res;

    FOR(i, 1, n){
        if (b[i - 1] == a[i - 1]){
            int x = i - 1, y = (n + 1) / 2 - 1;
            if (x == y)continue;
            if (x > y)swap(x, y);
            swap(a[x], a[y]);
            swap(b[x], b[y]);
            res.pb({ x + 1,y + 1 });
        }
    }

    map<int, int>mp;
    FOR(i, 0, n - 1) c[i] = a[n - 1 - i];
    FOR(i, 1, n){
        mp[c[i - 1]] = i;
    }

    FOR(i, 1, n){
        if (mp[b[i - 1]] == i){
            continue;
        }
        g[i].eb(mp[b[i - 1]]);
        g[mp[b[i - 1]]].eb(i);
    }

    V<int>vis(n + 1, 0);

    function<void(int, int)>dfs = [&](int u, int fa){
        if (vis[u])RE;
        vis[u] = 1;
        vis[n - u + 1] = 1;
        for (auto& j : g[u]){
            if (!vis[j] && !vis[n - j + 1] && j != fa){
                ans.pb({ u,j });
                dfs(j, u);
            }
        }
        };

    FOR(i, 1, n){
        if (!vis[i] && g[i].sz){
            dfs(i, 0);
        }
    }

    V<int>a1 = a, b1 = b;

    for (auto [x, y] : ans){
        swap(a1[x - 1], a1[y - 1]);
        swap(b1[x - 1], b1[y - 1]);
    }

    bool f = false;

    FOR(i, 0, n - 1){
        if (a1[i] != b1[n - 1 - i]){
            f = 1;
            break;
        }
    }

    if (f){
        fill(ALL(vis), 0);
        ans.clear();
        FORD(i, 1, n){
            if (!vis[i] && g[i].sz){
                dfs(i, 0);
            }
        }
        V<int>a2 = a, b2 = b;

        for (auto [x, y] : ans){
            swap(a2[x - 1], a2[y - 1]);
            swap(b2[x - 1], b2[y - 1]);
        }

        FOR(i, 0, n - 1){
            if (a2[i] != b2[n - 1 - i]){
                cout << -1 << endl;
                RE;
            }
        }
    }

    cout << ans.sz + res.sz << endl;
    for (auto [x, y] : res){
        cout << x << ' ' << y << endl;
    }
    for (auto [x, y] : ans){
        cout << x << ' ' << y << endl;
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