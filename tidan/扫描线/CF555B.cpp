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
    V<array<int, 3>> w;
    V<int> l(n + 1, 0), r(n + 1, 0);
    FOR(i, 1, n) cin >> l[i] >> r[i];

    FOR(i, 1, n - 1) {
        int L = l[i + 1] - r[i], R = r[i + 1] - l[i];
        w.pb({L, R, i});
    }

    V<array<int, 2>> br(m + 1);
    FOR(i, 1, m) {
        int x;
        cin >> x;
        br[i] = {x, i};
    }

    sort(br.begin() + 1, br.end());

    sort(ALL(w));
    priority_queue<array<int, 2>, V<array<int, 2>>, greater<array<int, 2>>> q;

    int t = 0;
    V<int> ans(n + 1, 0);
    int cnt = 0;

    FOR(i, 1, m) {
        auto [a, idx] = br[i];
        while (t < n - 1 && w[t][0] <= a) {
            q.push({w[t][1], w[t][2]});
            t++;
        }

        if (!q.empty()) {
            int p = q.top()[0];
            if (p < a) {
                No;
                RE;
            }
            ans[q.top()[1]] = idx;
            q.pop();
            cnt++;
        }
    }

    if (!q.empty() || cnt != n - 1) {
        No;
    } else {
        Yes;
        FOR(i, 1, n - 1) cout << ans[i] << ' ';
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