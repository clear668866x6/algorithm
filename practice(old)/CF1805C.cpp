#include <algorithm>
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
#define se second
#define sz size()

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> s;
    FOR(i, 1, n) {
        int x;
        cin >> x;
        s.insert(x);
    }
    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c <= 0) {
            NO;
            continue;
        }

        function<int(int, int, int)> check = [&](int a, int b, int c) {
            return b * b < 4 * a * c;
        };

        auto t = s.lower_bound(b);

        if (t != s.end() && check(a, b - *t, c)) {
            YES;
            cout << *t << endl;
        } else if (t != s.begin() && check(a, b - *prev(t), c)) {
            YES;
            cout << (*prev(t)) << endl;
        } else {
            No;
        }
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
