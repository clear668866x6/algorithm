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
    V<int> c(n * 2 + 1, 0);
    FOR(i, 1, n) cin >> w[i], c[i] = w[i], c[i + n] = w[i];

    int id1 = 0, id2 = 0;
    FOR(i, 1, n) {
        if (w[i] == 1) {
            id1 = i;
        }
        if (w[i] == n) {
            id2 = i;
        }
    }

    int c1 = 1, c2 = 1;

    FOR(i, id1 + 1, 2 * n) {
        if (c[i] - c[i - 1] == 1) {
            c1++;
        } else
            break;
    }

    FOR(i, id2 + 1, n * 2) {
        if (c[i] - c[i - 1] == -1) {
            c2++;
        } else
            break;
    }

    if (c1 == n || c2 == n) {
        YES;
    } else {
        NO;
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
