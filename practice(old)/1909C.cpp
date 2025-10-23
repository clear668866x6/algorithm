#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define se                                                                     \
    second:
#define sz size()

void solve() {
    int n;
    cin >> n;

    multiset<int> s1, s2;
    FOR(i, 0, n - 1) {
        int x;
        cin >> x;
        s1.insert(x);
    }

    V<int> b(n), c(n);
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    sort(RALL(c));
    sort(ALL(b));
    int ans = 0;
    V<int> del;
    FOR(i, 0, n - 1) {
        int l = (*prev(s1.upper_bound(b[i])));
        s1.erase(s1.find(l));
        del.eb(b[i] - l);
    }

    sort(ALL(del));

    FOR(i, 0, n - 1) { ans += c[i] * del[i]; }

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
