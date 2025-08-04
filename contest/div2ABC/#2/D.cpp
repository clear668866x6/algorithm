#include <bits/stdc++.h>
#include <functional>
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

void solve() {
    int n, m;
    cin >> n >> m;

    V<int> b(n + 1, 0);

    int tot = 0;

    FOR(i, 1, n) cin >> b[i], tot += b[i];

    V<V<PII>> g(n + 1);

    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(b, c);
    }

    function<int(int)> check = [&](int x) {
        queue<array<int, 2>> q;

        V<int> f(n + 1, -1);
        f[1] = min(x, b[1]);
        FOR(ver, 1, n) {
            for (auto [j, w] : g[ver]) {
                if (f[ver] >= w) {
                    f[j] = max(f[j], min(x, f[ver] + b[j]));
                }
            }
        }

        if (f[n] == -1)
            return 0;
        return 1;
    };

    int l = -1, r = tot + 1;

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    if (!check(r)) {
        cout << -1 << endl;
    } else {
        cout << r << endl;
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