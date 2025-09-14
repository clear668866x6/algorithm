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
    int n, q;
    cin >> n >> q;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    V<int> s1(n + 1, 0), s2(n + 1, 0), s3(n + 1, 0);

    FOR(i, 1, n) s1[i] = s1[i - 1] + w[i];
    FOR(i, 1, n) s2[i] = s2[i - 1] + i * w[i];
    FOR(i, 1, n) s3[i] = s3[i - 1] + i * i * w[i];

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        int t1 = s1[r] - s1[l - 1];
        int t2 = s2[r] - s2[l - 1];
        int t3 = s3[r] - s3[l - 1];

        ans = -t3 + (l + r) * t2 - (r + 1) * (l - 1) * t1;
        cout << ans << endl;
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