#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;

    int hl = -1e5, hr = 1e5, vl = -1e5, vr = 1e5;

    FOR(i, 1, n) {
        int x, y, a, b, c, d;
        cin >> x >> y >> a >> b >> c >> d;
        if (!a && c) {
            hl = max(hl, x);
        } else if (a && !c) {
            hr = min(hr, x);
        } else if (!a && !c) {
            hl = max(hl, x);
            hr = min(hr, x);
        }

        if (b && !d) {
            vl = max(vl, y);
        } else if (!b && d) {
            vr = min(vr, y);
        } else if (!b && !d) {
            vl = max(vl, y);
            vr = min(vr, y);
        }
    }

    if (hl > hr || vl > vr) {
        cout << 0 << endl;
    } else {
        cout << "1 ";
        cout << hl << ' ' << vl << endl;
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
