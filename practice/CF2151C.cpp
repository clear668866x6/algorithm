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
    V<int> w(n * 2 + 1, 0);
    FOR(i, 1, n * 2) cin >> w[i];

    V<int> pre(n * 2 + 1, 0), suf(n * 2 + 2, 0);
    FOR(i, 1, n) pre[i] = pre[i - 1] - w[i];
    FORD(i, n + 1, n * 2) suf[i] = suf[i + 1] + w[i];

    V<int> s1(n * 2 + 1, 0), s2(n * 2 + 1, 0);
    FOR(i, 1, n * 2) {
        if (i & 1) {
            s1[i] = s1[i - 1] + w[i];
            s2[i] = s2[i - 1] - w[i];
        } else {
            s1[i] = s1[i - 1] - w[i];
            s2[i] = s2[i - 1] + w[i];
        }
    }

    FOR(i, 1, n) {
        int l = i, r = 2 * n - i + 1;
        int t1 = pre[l] + suf[r];
        if (i & 1) {
            t1 += (s2[r - 1] - s2[l]);
        } else {
            t1 += (s1[r - 1] - s1[l]);
        }
        cout << t1 << " \n"[i == n];
    }
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
