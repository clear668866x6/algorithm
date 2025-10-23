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
    string s;
    cin >> s;
    s = ' ' + s;

    V<int> pre1(n + 1, 0), pre2(n + 1, 0), suf1(n + 2, 0), suf2(n + 2, 0);

    FOR(i, 1, n) {
        if (s[i] == 'A') {
            pre1[i] = pre1[i - 1] + w[i];
            pre2[i] = pre2[i - 1];
        } else {
            pre1[i] = pre1[i - 1];
            pre2[i] = pre2[i - 1] + w[i];
        }
    }

    FORD(i, 1, n) {
        if (s[i] == 'A') {
            suf1[i] = suf1[i + 1] + w[i];
            suf2[i] = suf2[i + 1];
        } else {
            suf1[i] = suf1[i + 1];
            suf2[i] = suf2[i + 1] + w[i];
        }
    }

    int ans = pre2[n];

    FOR(i, 1, n) {
        ans = max(ans, suf2[i] + pre1[i - 1]);
        ans = max(ans, pre2[i - 1] + suf1[i]);
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