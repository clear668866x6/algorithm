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

    struct E {
        int l, r, v;
        bool operator<(const E& t)const {
            return l < t.l;
        }
    };

    V<E>w (n);

    FOR (i, 0, n - 1)cin >> w[i].l >> w[i].r >> w[i].v;

    sort (ALL (w));
    V<int>vis (n, 0);

    while (1) {
        int l = upper_bound (ALL (w), E{ -1,k,-1 }) - w.begin () - 1;
        int r = lower_bound (ALL (w), E{ k + 1,-1,-1 }) - w.begin ();
        int t = 0, idx = -1;
        FOR (i, 0, r) {
            if (i < n && i >= 0 && k >= w[i].l && k <= w[i].r && !vis[i]) {
                if (w[i].v > t) {
                    t = w[i].v;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            cout << k << endl;
            RE;
        }
        vis[idx] = 1;
        // cout << l << ' ' << r << ' ' << t << endl;
        if (t > k) {
            k = t;
        } else {
            cout << k << endl;
            RE;
        }
        // cout << l << ' ' << r << endl;
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