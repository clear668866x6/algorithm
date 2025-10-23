#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

struct E {
    V<int> primes, vis;
    int cnt = 0;

    void init(int x) {
        primes.resize(x + 10), vis.resize(x + 10);

        FOR(i, 2, x) {
            if (!vis[i])
                primes[cnt++] = i;
            for (int j = 0; i * primes[j] <= x; j++) {
                vis[i * primes[j]] = 1;
                if (i % primes[j] == 0)
                    break;
            }
        }
    }
} A;

void solve() {
    int n;
    cin >> n;

    V<int> ans(n + n, 0);

    FOR(i, 1, n) {
        ans[i] = i;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                swap(ans[i], ans[i / j]);
                break;
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    A.init(1e5);

    while (Task--) {
        solve();
    }

    return 0;
}
