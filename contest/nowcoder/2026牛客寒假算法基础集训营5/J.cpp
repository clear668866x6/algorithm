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
    int n = 3;
    V<V<int>> w(n + 1, V<int>(n + 1, 0));
    set<int> s;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> w[i][j];
            s.insert(w[i][j]);
        }
    }

    if (sz(s) != 9) {
        No;
    } else {
        set<int> s2;
        s2.insert(w[1][1] + w[2][1] + w[3][1]);
        s2.insert(w[1][2] + w[2][2] + w[3][2]);
        s2.insert(w[1][3] + w[2][3] + w[3][3]);
        s2.insert(w[1][1] + w[1][2] + w[1][3]);
        s2.insert(w[2][1] + w[2][2] + w[2][3]);
        s2.insert(w[3][1] + w[3][2] + w[3][3]);
        s2.insert(w[1][1] + w[2][2] + w[3][3]);
        s2.insert(w[3][1] + w[2][2] + w[1][3]);
        if (sz(s2) == 1) {
            Yes;
        } else {
            No;
        }
    }
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