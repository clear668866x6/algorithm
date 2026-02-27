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
    int n, m;
    cin >> n >> m;
    V<array<int, 2>> w(n), q(m);
    FOR(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        w[i] = {y, x};
    }
    FOR(i, 0, m - 1) cin >> q[i][0] >> q[i][1];

    V<int> f(n + 2, 0), f2(n + 2, 0);

    sort(RALL(w));
    int r1 = 0, r2 = 0;
    int s1 = 0, s2 = 0;
    priority_queue<int, V<int>, greater<int>> qq1, qq2;

    V<int> pr(n + 2, 0);
    int fs = 0;
    FORD(i, 1, n) {
        while (r1 < n && w[r1][0] >= i - 1) {
            qq1.push(w[r1][1]);
            s1 += w[r1][1];
            r1++;
        }

        while (sz(qq1) > i) {
            s1 -= qq1.top();
            qq1.pop();
        }

        if (sz(qq1) == i) f[i] = s1;

        while (r2 < n && w[r2][0] >= i) {
            qq2.push(w[r2][1]);
            s2 += w[r2][1];
            r2++;
        }

        while (sz(qq2) > i) {
            s2 -= qq2.top();
            qq2.pop();
        }

        if (sz(qq2) == i) f2[i] = s2;
    }

    FOR(i, 1, n) fs = max(fs, f[i]);

    FOR(i, 1, n) pr[i] = max(pr[i - 1], f2[i]);

    FOR(i, 0, m - 1) {
        auto [x, y] = q[i];
        cout << max(fs, pr[y] + x) << ' ';
    }
    cout << endl;
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
