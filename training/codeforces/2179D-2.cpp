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
    V<int> w(n, 0ll);
    iota(ALL(w), 0ll);

    int mx = 0;

    do {
        int cnt = 0;
        FOR(i, 0, n - 1) {
            int t = w[i];
            FOR(j, 0, i - 1) {
                t &= w[j];
            }
            cnt += __builtin_popcount(t);
        }

        mx = max(mx, cnt);

    } while (next_permutation(ALL(w)));

    iota(ALL(w), 0ll);

    do {
        int cnt = 0;
        FOR(i, 0, n - 1) {
            int t = w[i];
            FOR(j, 0, i - 1) {
                t &= w[j];
            }
            cnt += __builtin_popcount(t);
        }
        if (cnt == mx) {
            cout << cnt << endl;
            FOR(i, 0, n - 1) cout << w[i] << ' ';
            cout << endl;
            RE;
        }
    } while (next_permutation(ALL(w)));
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