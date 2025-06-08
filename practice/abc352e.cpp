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
    int n, m, k;

    cin >> n >> m;

    struct E{
        int x, y, w;
        bool operator<(const E& t)const{
            return w < t.w;
        }
    };

    V<int>p(n + 1, 0);

    FOR(i, 1, n)p[i] = i;

    function<int(int)>find = [&](int x){
        if (x != p[x])p[x] = find(p[x]);
        return p[x];
        };

    V<E>edg;
    V<V<int>>t(m + 1);
    V<int>c(m + 1, 0);

    FOR(i, 1, m){
        cin >> k >> c[i];
        FOR(j, 1, k){
            int x;
            cin >> x;
            t[i].eb(x);
        }
    }

    FOR(i, 1, m){
        FOR(j, 1, t[i].sz - 1){
            edg.pb({ t[i][0], t[i][j], c[i] });
            edg.pb({ t[i][j], t[i][0], c[i] });
        }
    }

    sort(ALL(edg));

    int tot = 0, ans = 0;

    FOR(i, 0, edg.sz - 1){
        int a = find(edg[i].x), b = find(edg[i].y);
        if (a != b){
            p[a] = b;
            tot++;
            ans += edg[i].w;
        }
    }

    if (tot != n - 1){
        cout << -1 << endl;
    } else{
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