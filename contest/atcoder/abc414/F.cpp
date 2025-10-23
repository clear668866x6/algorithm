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
    int n, k;
    cin >> n >> k;

    V<V<PII>>g (n + 1);
    V<V<int>>f (k, V<int> (2 * n + 2, -1)), cnt (k, V<int> (n + 1, 0));

    FOR (i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb (b, 2 * i);
        g[b].eb (a, 2 * i + 1);
    }

    queue<array<int, 3>>q;

    q.push ({ 1,0 ,-1 });

    V<int> ac (n + 1, -1);

    while (q.sz) {
        auto [ver, d, e] = q.front ();
        q.pop ();

        if (d % k == 0 && ac[ver] == -1) {
            ac[ver] = d / k;
        }

        if (cnt[d % k][ver] == 2)continue;
        cnt[d % k][ver]++;

        for (auto [j, e2] : g[ver]) {
            if ((e ^ e2) == 1 && d % k != 0)continue;
            if (f[(d + 1) % k][e2] == -1) {
                f[(d + 1) % k][e2] = d + 1;
                q.push ({ d + 1,j,e2 });
            }

        }
    }

    FOR (i, 2, n) {
        cout << ac[i] << " \n"[i == n];
    }

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