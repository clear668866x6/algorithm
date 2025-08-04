#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = ' ' + s;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    V<int> pre(n + 1, 0), suf(n + 2, 0);

    bool ff = false;

    FOR(i, 1, n) {
        if (s[i] == '0')
            w[i] = -1e18, ff = 1;
    }

    int mx = 0, cur = 0;

    FOR(i, 1, n) {
        cur = max(cur + w[i], w[i]);
        mx = max(mx, cur);
    }

    if (mx > k || (mx != k && !ff)) {
        No;
        RE;
    }

    if (mx == k) {
        Yes;
        FOR(i, 1, n) cout << w[i] << " \n"[i == n];
        RE;
    }

    FOR(i, 1, n) { pre[i] = max({pre[i - 1] + w[i], w[i], pre[i]}); }

    FORD(i, 1, n) { suf[i] = max({suf[i + 1] + w[i], w[i], suf[i]}); }

    bool f = false;

    FOR(i, 1, n) {
        if (s[i] == '0') {
            int j = i;
            while (j <= n && s[j] == '0')
                j++;
            int t = pre[i - 1] + suf[j];
            FOR(x, i, j - 1) { w[x] = 0; }
            w[i] = k - t; // 憨了，这里很可能小但合起来大。
            break;
        }
    }

    Yes;
    FOR(i, 1, n) cout << w[i] << " \n"[i == n];
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