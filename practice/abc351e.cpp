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

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {
    int n;
    cin >> n;

    V<array<int, 2>> w(n);

    for (auto& [a, b] : w)
        cin >> a >> b;

    V<V<int>> p(2), q(2);

    FOR(i, 0, n - 1) {
        if ((w[i][0] + w[i][1]) % 2) {
            p[1].push_back((w[i][0] + w[i][1] - 1) / 2);
            q[1].push_back((w[i][0] - w[i][1] - 1) / 2);
            continue;
        }
        p[0].push_back((w[i][0] + w[i][1]) / 2);
        q[0].push_back((w[i][0] - w[i][1]) / 2);
    }

    sort(ALL(p[0]));
    sort(ALL(p[1]));
    sort(ALL(q[0]));
    sort(ALL(q[1]));

    int ans = 0, sufx = 0, sufy = 0;

    FOR(i, 0, (int)p[0].size() - 1) {
        ans += i * p[0][i] - sufx + i * q[0][i] - sufy;
        sufx += p[0][i];
        sufy += q[0][i];
    }

    sufx = 0, sufy = 0;

    FOR(i, 0, (int)p[1].size() - 1) {
        ans += i * p[1][i] - sufx + i * q[1][i] - sufy;
        sufx += p[1][i];
        sufy += q[1][i];
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