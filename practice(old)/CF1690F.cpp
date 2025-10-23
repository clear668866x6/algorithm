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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int ans = 1;

    V<int> vis(n + 1, 0);

    auto calc = [&](int x) {
        int t = w[x];
        int cnt = 1;
        string ss(1, s[x]);

        while (t != x) {
            ss += (s[t]);
            vis[t] = 1;
            t = w[t];
            cnt++;
        }

        int len = sz(ss);

        FOR(i, 1, len) {
            if (len % i == 0) {
                bool f = false;
                FOR(j, 0, len - 1) {
                    if (ss[j] != ss[j % i]) {
                        f = 1;
                        break;
                    }
                }
                if (!f) return i;
            }
        }
        return (int)1;
    };

    FOR(i, 1, n) {
        if (vis[i]) continue;
        int t = calc(i);
        ans = lcm(ans, t);
    }

    cout << ans << endl;
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
