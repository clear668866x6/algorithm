#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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
    int n, k;
    string s;
    cin >> n >> k >> s;

    s = ' ' + s;

    string p1 = "RGB", p2 = "GB", p3 = "B";

    FOR(i, 1, n) p1 += "RGB", p2 += "RGB", p3 += "RGB";

    V<int> pre1(n + 2, 0), pre2(n + 2, 0), pre3(n + 1, 0);

    FOR(i, 1, n) {
        pre1[i] = pre1[i - 1] + (s[i] != p1[i - 1]);
        pre2[i] = pre2[i - 1] + (s[i] != p2[i - 1]);
        pre3[i] = pre3[i - 1] + (s[i] != p3[i - 1]);
    }

    int ans = 1e18;

    FOR(i, 1, n) {
        if (i + k - 1 <= n) {
            ans = min(ans, pre1[i + k - 1] - pre1[i - 1]);
            ans = min(ans, pre2[i + k - 1] - pre2[i - 1]);
            ans = min(ans, pre3[i + k - 1] - pre3[i - 1]);
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
