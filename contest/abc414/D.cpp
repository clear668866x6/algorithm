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
    V<int>w (n);
    for (auto& x : w)cin >> x;

    sort (ALL (w));
    w.erase (unique (ALL (w)), w.end ());

    n = w.sz;

    if (m >= n) {
        cout << 0 << endl;
    } else if (m == 1) {
        cout << (*max_element (ALL (w)) - *min_element (ALL (w)));
    } else {
        priority_queue<int, V<int>, greater<int>>q;
        FOR (i, 1, n - 1) {
            q.push (w[i] - w[i - 1]);
        }

        int del = n - m, ans = 0;

        while (del--) {
            ans += q.top ();
            q.pop ();
        }
        cout << ans;
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