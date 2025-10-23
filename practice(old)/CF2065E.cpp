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
    int n, m, k;
    cin >> n >> m >> k;

    if (abs(n - m) > k || max(n, m) < k) {
        cout << -1 << endl;
    } else {
        if (n <= m) {
            FOR(i, 1, k) cout << "1";
            if (n) {
                cout << 0;
                n--;
            }
            m -= k;
            while (n > 0 && m > 0) {
                cout << "10";
                n--, m--;
            }

            while (n > 0) {
                cout << "0";
                n--;
            }
            while (m > 0) {
                cout << "1";
                m--;
            }
        } else {
            FOR(i, 1, k) cout << "0";
            if (m) {
                cout << "1";
                m--;
            }
            n -= k;
            while (n > 0 && m > 0) {
                cout << "01";
                n--, m--;
            }
            while (m > 0) {
                m--;
                cout << "1";
            }

            while (n > 0) {
                n--;
                cout << "0";
            }
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
