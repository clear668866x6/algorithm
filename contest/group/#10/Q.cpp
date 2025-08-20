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

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int c1 = 0, c2 = 0;
    V<int> a;

    FOR(i, 1, n) {
        c1 += (w[i] == -1);
        c2 += (w[i] == -2);
        if (w[i] >= 0) {
            a.eb(w[i]);
        }
    }

    sort(ALL(a));
    a.erase(unique(ALL(a)), a.end());

    map<int, int> mp;

    for (auto x : a) mp[x]++;

    int a3 = sz(a);

    V<int> pre(m + 1, 0);

    FOR(i, 1, m) {
        pre[i] = pre[i - 1] + mp[i];
    }

    int ans = 0;

    ans = max({ans, min(m, a3 + c1), min(m, a3 + c2)});

    FOR(i, 1, m) {
        if (mp[i]) {
            int l = pre[i - 1], r = a3 - l - 1;
            ans = max(ans, 1 + min(i - 1, l + c1) + min(m - i, r + c2));
        }
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
