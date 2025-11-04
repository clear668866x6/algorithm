#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
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

struct Prime {
    static constexpr int N = 2e5 + 10;
    int primes[N], vis[N];
    int cnt;
    int n;
    V<int> fac[N];
    void init() {
        n = N - 10;
        FOR(i, 2, n) {
            if (!vis[i]) primes[cnt++] = i;
            for (int j = 0; i * primes[j] <= n; j++) {
                vis[i * primes[j]] = 1;
                if (i % primes[j] == 0) break;
            }
        }
    }

    void fuck() {
        n = N - 10;
        FOR(i, 2, n) {
            if (!fac[i].empty()) continue;
            FOR2(j, i, n, i) {
                fac[j].eb(i);
            }
        }
    }
} A;

void solve() {
    int n;
    cin >> n;
    V<int> a(n + 1, 0), b(n + 1, 0);

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    map<int, int> mp;

    int ans = 2;

    FOR(i, 1, n) {
        for (auto j : A.fac[a[i]]) {
            if (mp[j]) {
                ans = 0;
            }
            mp[j]++;
        }
    }

    FOR(i, 1, n) {
        for (auto j : A.fac[a[i]]) {
            mp[j]--;
        }

        for (auto j : A.fac[a[i] + 1]) {
            if (mp[j]) {
                ans = min(ans, 1);
            }
        }

        for (auto j : A.fac[a[i]]) {
            mp[j]--;
        }
    }

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    // A.init();
    A.fuck();
    while (Task--) {
        solve();
    }

    return 0;
}
