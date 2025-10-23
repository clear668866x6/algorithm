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
    int n, m, L;
    cin >> n >> m >> L;

    V<PII>w (n + 1);

    FOR (i, 1, n) {
        cin >> w[i].fi >> w[i].se;
    }

    V<int>a (m + 1, 0), b (m + 1, 0);

    FOR (i, 1, m)cin >> a[i] >> b[i];

    priority_queue<int>q;

    int ans = 0, lst = 0, tot = 0;

    FOR (i, 1, n) {
        auto [L, R] = w[i];
        int del = R - L + 1;
        int l = upper_bound (a.begin () + 1, a.end (), lst) - a.begin ();
        int r = upper_bound (a.begin () + 1, a.end (), L) - a.begin () - 1;
        FOR (j, l, r) {
            q.push (b[j]);
        }
        while (tot < del) {
            if (!q.sz) {
                cout << -1 << endl;
                RE;
            }
            tot += q.top ();
            q.pop ();
            ans++;
        }
        lst = R;
    }
    cout << ans << endl;

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