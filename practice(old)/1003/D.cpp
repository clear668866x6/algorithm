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
    int n, a, b;
    cin >> n >> a >> b;

    if (n % gcd(a, b)) {
        cout << -1 << endl;
        RE;
    }

    int t1 = 0, t2 = 0;
    FOR(i, 0, n) {
        if ((n - i * a) % b == 0 && (n - i * a) >= 0) {
            t1 = i;
            t2 = (n - i * a) / b;
            break;
        }
    }

    if (!t1 && !t2) {
        cout << -1 << endl;
        RE;
    }

    V<int> ans(n + 1, 0);

    int num = 1, x = 1;

    while (t1--) {
        int p = num + 1;
        FOR(i, x, x + a - 2) {
            ans[i] = p++;
        }
        ans[x + a - 1] = num;
        num += a;
        x += a;
    }

    while (t2--) {
        int p = num + 1;
        FOR(i, x, x + b - 2) {
            ans[i] = p++;
        }
        ans[x + b - 1] = num;
        num += b;
        x += b;
    }

    FOR(i, 1, n) cout << ans[i] << ' ';
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