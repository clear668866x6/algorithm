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
    V<array<int, 2>> w(n + 1);

    FOR(i, 1, n) cin >> w[i][0], w[i][1] = i;

    sort(ALL(w));

    V<int> f(n + 1, 1e18);
    V<int> pre(n + 1, 0), siz(n + 1, 0);
    deque<int> q;
    f[0] = 0;

    auto calc = [&](int x) { return f[x] - w[x + 1][0]; };
    V<int> ans(n + 1, 0);

    FOR(i, 3, n) {
        int lst = i - 3;
        if (lst != 1 && lst != 2) {
            while (!q.empty() && calc(q.back()) >= calc(lst)) q.pop_back();
            q.push_back(lst);
        }
        pre[i] = q.front();
        f[i] = calc(q.front()) + w[i][0];
        siz[i] = siz[q.front()] + 1;
    }

    for (int i = n; i; i = pre[i]) {
        FOR(j, pre[i] + 1, i) {
            ans[w[j][1]] = siz[i];
        }
    }

    cout << f[n] << ' ' << siz[n] << endl;
    FOR(i, 1, n) cout << ans[i] << " ";
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