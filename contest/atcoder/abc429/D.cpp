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
    int n, m, c;
    cin >> n >> m >> c;
    V<int> w(n);
    map<int, int> mp;
    for (auto &x : w) cin >> x, mp[x]++;
    w.eb(m);
    w.eb(0);
    sort(ALL(w));
    w.erase(unique(ALL(w)), w.end());
    n = sz(w);
    V<int> pre(n + 1, 0);
    FOR(i, 1, n - 1) pre[i] = pre[i - 1] + mp[w[i - 1]];
    pre[n] = pre[n - 1];
    int ans = 0;

    FOR(i, 1, n - 1) {
        int cnt = w[i] - w[i - 1];
        int l = 0, r = 1e13;

        auto calc = [&](int x) {
            int round = x / n, re = x % n;
            int tot = (i128)pre[n] * round + pre[re] - pre[i];
            return tot;
        };

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (calc(mid) >= c)
                r = mid;
            else
                l = mid;
        }
        ans += cnt * calc(r);
    }

    cout << ans;
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