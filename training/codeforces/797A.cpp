#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
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
    int n, k;
    cin >> n >> k;

    V<PII> ans;
    int tot = 0;

    FOR(i, 2, n) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) n /= i, c++;
            tot += c;
            ans.eb(i, c);
        }
    }

    if (n > 1) {
        tot++;
        ans.eb(n, 1);
    }

    sort(ALL(ans));

    if (tot < k) {
        cout << -1 << endl;
    } else {
        k--;
        FORD(i, 0, sz(ans) - 1) {
            if (ans[i].se <= k) {
                int t = ans[i].se;
                while (t--) cout << ans[i].fi << ' ';
                k -= ans[i].se;
                ans[i].se = 0;
            } else {
                int t = k;
                while (t--) cout << ans[i].fi << ' ', ans[i].se--;
                k = 0;
                break;
            }
        }
        int t = 1;
        FOR(i, 0, sz(ans) - 1) {
            while (ans[i].se--) t *= ans[i].fi;
        }
        cout << t;
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