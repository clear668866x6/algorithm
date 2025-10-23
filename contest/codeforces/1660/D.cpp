#include <algorithm>
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

    V<int> w(n + 2, 0);

    FOR(i, 1, n) cin >> w[i];

    V<int> pre(n + 3, 0), c2(n + 3, 0);

    FOR(i, 1, n) pre[i] = pre[i - 1] + (w[i] < 0), c2[i] = c2[i - 1] + (abs(w[i]) > 1);

    if (n == 1) {
        if (w[1] <= 0) {
            cout << "1 0" << endl;
        } else {
            cout << "0 0" << endl;
        }
        RE;
    }

    int l = 0, ans = 0, ansl = 0, ansr = n;

    function<void(int, int)> calc = [&](int l, int r) {
        if ((pre[r] - pre[l - 1]) % 2 == 0 && (c2[r] - c2[l - 1]) > ans) {
            ans = c2[r] - c2[l - 1];
            ansl = l - 1, ansr = n - r;
        }
    };

    FOR(i, 1, n + 1) {
        if (w[i] == 0) {
            FOR(j, l + 1, i - 1) {
                calc(l + 1, j), calc(j, i - 1);
            }
            l = i;
        }
    }

    cout << ansl << ' ' << ansr << endl;
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
