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

    V<int> w{1, 3, 6, 10, 15};

    int ans = 1e18;

    FOR(a, 0, 10) {
        FOR(b, 0, 10) {
            FOR(c, 0, 10) {
                FOR(d, 0, 10) {
                    int p = n / 15;
                    int tot = a + 3 * b + 6 * c + 10 * d;
                    if (tot == n % 15) {
                        ans = min(ans, p + a + b + c + d);
                    }

                    p = n / 15 - 1;
                    if (p < 0) continue;

                    tot = a + 3 * b + 6 * c + 10 * d;
                    if (tot == n % 15 + 15) {
                        ans = min(ans, p + a + b + c + d);
                    }
                }
            }
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
