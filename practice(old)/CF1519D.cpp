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
    V<int> a(n + 1, 0), b(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    V<int> pre(n + 1, 0), suf(n + 2, 0);
    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i] * b[i];
    FORD(i, 1, n) suf[i] = suf[i + 1] + a[i] * b[i];

    int ans = pre[n];

    FOR(i, 1, n) {
        int l = i - 1, r = i + 1;
        int tmp = a[i] * b[i];
        while (l >= 1 && r <= n) {
            tmp += (a[l] * b[r] + a[r] * b[l]);
            ans = max(ans, pre[l - 1] + tmp + suf[r + 1]);
            l--, r++;
        }

        l = i, r = i + 1;
        tmp = 0;
        while (l >= 1 && r <= n) {
            tmp += (a[l] * b[r] + a[r] * b[l]);
            ans = max(ans, pre[l - 1] + tmp + suf[r + 1]);
            l--, r++;
        }
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