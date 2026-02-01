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
    int n, q;
    cin >> n >> q;

    V<int> d(n + 2, 0), dd(n + 2, 0);

    FOR(i, 1, n) {
        int a, b;
        cin >> a >> b;

        if (a - 1 > 1) {
            d[1] += (a - 2);
            dd[2]--, dd[a]++;
        }

        dd[b + 2]++;

        if (a < b - 2) {
            int la = (a + b) / 2, ra = la + 1;

            dd[a + 2]++, dd[la + 1]--;
            d[la + 1] -= (la - a - 1);

            d[ra] += (b - ra - 1);
            dd[ra + 1]--, dd[b]++;
        }
    }

    int cur = 0;

    FOR(i, 1, n) {
        cur += dd[i];
        d[i] += cur;
    }

    FOR(i, 1, n) d[i] += d[i - 1];

    FOR(i, 1, q) {
        int x;
        cin >> x;
        cout << d[x] << ' ';
    }
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
