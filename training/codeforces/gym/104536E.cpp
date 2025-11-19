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

struct FenwikTree {
    static constexpr int N = 4e5 + 10;
    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] = max(tr[i], c);
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans = max(ans, tr[i]);
        return ans;
    }
} f0, f1;

void solve() {
    int n;
    cin >> n;
    V<int> a(n + 1, 0), b(n + 1, 0);
    V<int> c;
    FOR(i, 1, n) cin >> a[i], c.eb(a[i]);
    FOR(i, 1, n) cin >> b[i], c.eb(b[i]);

    V<V<int>> f(n + 1, V<int>(2, 0));

    int ans = 0;

    sort(ALL(c));
    c.erase(unique(ALL(c)), c.end());

    auto get = [&](int x) { return lower_bound(ALL(c), x) - c.begin() + 1; };

    FOR(i, 1, n) {
        a[i] = get(a[i]), b[i] = get(b[i]);
        f[i][0] = f0.query(a[i] - 1) + 1;
        f[i][0] = max(f[i][0], f1.query(a[i] - 1) + 1);
        f[i][1] = f0.query(b[i] - 1) + 1;
        f[i][1] = max(f[i][1], f1.query(b[i] - 1) + 1);
        ans = max({ans, f[i][0], f[i][1]});
        f0.add(a[i], f[i][0]);
        f1.add(b[i], f[i][1]);
    }
    cout << ans;
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