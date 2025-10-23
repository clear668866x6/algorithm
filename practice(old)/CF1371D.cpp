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
    int n, k;
    cin >> n >> k;
    V<V<int>> w(n + 1, V<int>(n + 1, 0));
    int ans = 0;

    int x = 1, y = 1, len1 = 1, len2 = n;
    bool f = false;

    while (k--) {
        if (x > n || y > n) {
            if (!f) {
                len1++;
                f = 1;
                x = len1, y = 1;
            } else {
                x = 1, y = len2;
                len2--;
                f = 0;
            }
        }
        w[x][y] = 1;
        x++, y++;
    }

    int t1 = 0, t2 = n;

    FOR(i, 1, n) {
        int c = 0;
        FOR(j, 1, n) {
            c += w[i][j];
        }
        t1 = max(t1, c);
        t2 = min(t2, c);
    }

    ans += (t2 - t1) * (t2 - t1);
    t1 = 0, t2 = n;
    FOR(j, 1, n) {
        int c = 0;
        FOR(i, 1, n) {
            c += w[i][j];
        }
        t1 = max(t1, c);
        t2 = min(t2, c);
    }

    ans += (t2 - t1) * (t2 - t1);

    cout << ans << endl;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cout << w[i][j];
        }
        cout << endl;
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
