#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
    int n;
    cin >> n;

    V<int> w(n * 2, 0);

    for (auto& x : w)
        cin >> x;

    map<int, int> l, r;

    FOR(i, 0, n * 2 - 1) r[w[i]] = i;

    FORD(i, 0, n * 2 - 1) l[w[i]] = i;

    int ans = 0;

    FOR(i, 1, n) {
        if (r[i] - l[i] == 1)
            continue;

        if (r[i] - l[i] == 3) {
            if (w[l[i] + 1] == w[r[i] - 1])
                ans--;
        }

        int t = l[i];
        if (t - 1 >= 0) {
            if (l[w[t - 1]] == t - 1) {
                if (r[i] - 1 >= 0 && r[w[t - 1]] == r[i] - 1 ||
                    (r[i] + 1 < n * 2 && r[w[t - 1]] == r[i] + 1)) {
                    ans++;
                }
            }
        }

        if (t + 1 < n * 2) {
            if (l[w[t + 1]] == t + 1) {
                if (r[i] - 1 >= 0 && r[w[t + 1]] == r[i] - 1 ||
                    (r[i] + 1 < n * 2 && r[w[t + 1]] == r[i] + 1)) {
                    ans++;
                }
            }
        }
    }

    cout << ans / 2 << endl;
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
