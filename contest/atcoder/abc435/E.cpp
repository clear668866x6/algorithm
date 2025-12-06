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
    int L, q;
    cin >> L >> q;
    int ans = L;

    set<array<int, 2>> s;

    while (q--) {
        int l, r;
        cin >> l >> r;

        auto it = s.lower_bound({l, 0});

        if (it != s.begin()) {
            if ((*prev(it))[1] >= l - 1) {
                it--;
            }
        }

        int nl = l, nr = r;
        int t = 0;
        while (it != s.end() && (*it)[0] <= r + 1) {
            t += (*it)[1] - (*it)[0] + 1;
            nl = min(nl, (*it)[0]);
            nr = max(nr, (*it)[1]);
            it = s.erase(it);
        }

        s.insert({nl, nr});
        ans -= (nr - nl + 1);
        ans += t;
        cout << ans << endl;
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