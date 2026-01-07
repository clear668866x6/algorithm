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
    int n, m;
    cin >> n >> m;
    set<array<int, 2>> s;
    V<V<int>> g(n + 1);

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        s.insert({a, b});
        s.insert({b, a});
        g[a].eb(b);
        g[b].eb(a);
    }

    int t1 = 0, t2 = 0;

    FOR(i, 1, n) {
        for (auto j : g[i]) {
            for (auto k : g[i]) {
                if (j == k) continue;
                t2++;
                if (s.count({j, k})) t1++;
            }
        }
    }

    int t = gcd(t1, t2);
    t1 /= t, t2 /= t;

    cout << t1 << "/" << t2 << endl;
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
