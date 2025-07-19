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
    V<int>w (n + 1, 0), l (n + 1, 0), r (n + 1, 0);

    FOR (i, 1, n)cin >> w[i];
    FOR (i, 1, n)cin >> l[i] >> r[i];

    V<int>hl (n + 1, 0), hr (n + 1, 0);

    int x = 0, y = 0;

    FOR (i, 1, n) {
        if (w[i] != -1) {
            x += w[i], y += w[i];
        } else {
            y++;
        }

        int L = max (x, l[i]), R = min (y, r[i]);
        if (L > R) {
            cout << -1 << endl;
            RE;
        }
        x = L, y = R;
        hl[i] = L, hr[i] = R;
    }

    int t = hl[n];

    FORD (i, 1, n) {
        if (w[i] == -1) {
            if (t >= hl[i - 1] && t <= hr[i - 1])w[i] = 0;
            else w[i] = 1;
            t -= w[i];
        } else {
            t -= w[i];
        }
    }

    FOR (i, 1, n)cout << w[i] << " \n"[i == n];

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