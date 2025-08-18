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

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    V<int> pre(n + 1, 0);

    FOR(i, 1, n) {
        pre[i] = pre[i - 1] + (w[i] * i);
    }

    V<int> p(n + 2, 0), spre(n + 2, 0), sp(n + 2, 0);

    FOR(i, 2, n) {
        spre[i] = spre[i - 1] + ((i - 1) * w[i] + w[i - 1]);
    }
    int ans = 0;
    int j = 1;

    cout << spre[2] << ' ' << pre[3] - spre[2] << endl;

    FOR(i, 1, n) {
        int s = spre[i] - spre[j];
        cout << j << ' ' << i << ' ' << s << endl;
        while (j + 1 <= i && spre[i] - spre[j + 1] > s) {
            s = spre[i] - spre[j + 1];
            j++;
        }
        ans = max(ans, s);
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