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
    FOR(i, 1, n) cin >> w[i];

    V<array<int, 2>> d(n + 1);
    FOR(i, 1, n) {
        d[i] = {abs(w[i]), i};
    }

    sort(d.begin() + 1, d.end());

    map<int, int> mp;
    FOR(i, 1, n) mp[d[i][0]]++;

    if (mp[0] == n) {
        Yes;
    } else {
        if (mp[d[1][0]] == n) {
            int p1 = 0, p2 = 0;
            FOR(i, 1, n) {
                if (w[i] > 0)
                    p1++;
                else
                    p2++;
            }

            if (!p1 || !p2) {
                Yes;
                RE;
            }

            if (n & 1 && abs(p1 - p2) == 1 || (!(n & 1) && abs(p1 - p2) == 0)) {
                Yes;
            } else {
                No;
            }
            RE;
        }

        FOR(i, 2, n - 1) {
            int a = w[d[i - 1][1]], b = w[d[i][1]], c = w[d[i + 1][1]];

            if ((i128)a * c != (i128)b * b) {
                No;
                RE;
            }
        }
        Yes;
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
