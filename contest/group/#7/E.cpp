#include <bits/stdc++.h>
#include <functional>
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
    int h, n;
    cin >> h >> n;

    V<int> d(n + 1, 0);

    FOR(i, 1, n) cin >> d[i];

    V<int> pre(n + 1, 0);

    int mx = 0;

    FOR(i, 1, n) {
        pre[i] = pre[i - 1] + d[i];
        if (pre[i] <= 0) {
            mx = max(mx, abs(pre[i]));
        }
    }

    if (h - mx > 0 && pre[n] >= 0) {
        cout << -1 << endl;
    } else {

        if (h - mx <= 0) {
            int ans = 0, tot = h;
            FOR(i, 1, n) {
                if (tot <= 0) break;
                ans++;
                tot += d[i];
            }
            cout << ans << endl;
            RE;
        }

        int l = -1, r = h / abs(pre[n]) + 10;

        function<int(int)> check = [&](int x) { return h + pre[n] * x - mx <= 0; };

        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid;
        }
        if (r == h / abs(pre[n]) + 10) r = 0;

        int tot = h + r * pre[n];
        int ans = r * n;
        FOR(i, 1, n) {
            if (tot <= 0) {
                break;
            }
            ans++;
            tot += d[i];
        }
        cout << ans;
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
