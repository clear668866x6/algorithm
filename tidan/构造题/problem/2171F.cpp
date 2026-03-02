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
    V<int> pos(n + 1, 0);
    FOR(i, 1, n) cin >> w[i], pos[w[i]] = i;

    int l = 1, r = n;
    FOR(i, 1, n) {
        if (w[i] == 1) {
            l = i;
            break;
        }
    }

    if (l == n) {
    }

    V<array<int, 2>> s;
    set<int> s2;
    FOR(i, 1, n) s2.insert(i);

    int mx = w[l], mxidx = l;
    while (l >= 1) {
        FOR(i, l + 1, r) {
            s.pb({w[l], w[i]});
            if (w[i] > mx) {
                mx = w[i];
                mxidx = i;
            }
        }

        FOR(i, l, r) s2.erase(w[i]);
        if (s2.empty() && l == 1) {
            break;
        }
        if (*s2.begin() > mx) {
            No;
            RE;
        }
        s.pb({*s2.begin(), mx});
        r = l - 1;
        l = pos[(*s2.begin())];
    }
    Yes;
    for (auto [x, y] : s) cout << x << ' ' << y << endl;
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
