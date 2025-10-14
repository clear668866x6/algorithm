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

struct P {
    static constexpr int N = 3e6 + 10;
    int primes[N], cnt;
    bool vis[N];

    void init() {
        int n = N - 10;
        vis[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) primes[cnt++] = i;
            for (int j = 0; i * primes[j] <= n; j++) {
                vis[i * primes[j]] = 1;
                if (i % primes[j] == 0) break;
            }
        }
    }

} A;

void solve() {
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    map<int, int> mp;
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;
    A.init();

    V<int> ans;

    if (mp[1]) {
        int t = mp[1];
        while (t--) {
            ans.eb(1);
        }
        FOR(i, 1, n) {
            if (w[i] != 1) {
                if (!A.vis[w[i] + 1]) {
                    ans.eb(w[i]);
                    break;
                }
            }
        }
    }
    if (sz(ans) < 2) {
        ans.clear();
        FOR(i, 1, n) {
            FOR(j, i + 1, n) {
                if (!A.vis[w[i] + w[j]]) {
                    ans.eb(w[i]);
                    ans.eb(w[j]);
                    break;
                }
            }
            if (sz(ans)) break;
        }
    }

    if (!sz(ans)) {
        ans.eb(w[1]);
    }

    cout << sz(ans) << endl;
    for (auto x : ans) cout << x << ' ';
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