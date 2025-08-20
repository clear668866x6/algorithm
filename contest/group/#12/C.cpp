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
    int k, n, m;
    cin >> k >> n >> m;

    V<int> a(n), b(m);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int l = 0, r = 0;

    V<int> ans;

    while (1) {
        if (l == n && r == m) break;
        int x = -1, y = -1;
        if (l < n) {
            if (a[l] == 0) {
                ans.eb(a[l++]);
                k++;
                continue;
            } else {
                x = a[l];
            }
        }
        if (r < m) {
            if (b[r] == 0) {
                ans.eb(b[r++]);
                k++;
                continue;
            } else {
                y = b[r];
            }
        }
        if (x == -1 || y == -1) {
            if (max(x, y) > k) {
                cout << -1 << endl;
                RE;
            }
            if (x == -1) ans.eb(b[r++]);
            if (y == -1) ans.eb(a[l++]);
            continue;
        }
        if (x > y) {
            if (y > k) {
                cout << -1 << endl;
                RE;
            }
            ans.eb(y);
            r++;
        } else {
            if (x > k) {
                cout << -1 << endl;
                RE;
            }
            ans.eb(x);
            l++;
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << endl;
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
