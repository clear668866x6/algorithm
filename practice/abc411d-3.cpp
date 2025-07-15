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

    V<pair<int, string>>w (6e5 + 10);

    V<int>pc (n + 1, 0);
    int cnt = 1;

    FOR (i, 1, m) {
        int op, p;
        cin >> op >> p;
        if (op == 1)pc[p] = pc[0];
        else if (op == 3)pc[0] = pc[p];
        else {
            string s;
            cin >> s;
            w[cnt + 1] = { pc[p],s };
            pc[p] = ++cnt;
        }
    }

    function<void (int)>dfs = [&] (int x) {
        if (!x)RE;
        dfs (w[x].fi);
        cout << w[x].se;
        };

    dfs (pc[0]);
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