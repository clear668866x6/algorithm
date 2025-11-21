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

// 因为i<j si<=sj 为同一色，所以可以转化为最长下降子序列的长度。

struct FenWiKTree {
    static constexpr int N = 2e5 + 10;
    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] = max(tr[i], c);
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans = max(ans, tr[i]);
        return ans;
    }

} A;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    V<int> num(n + 1, 0);
    V<int> c;
    FOR(i, 1, n) num[i] = -(s[i] - 'a' - 1), c.eb(num[i]);

    sort(ALL(c));
    c.erase(unique(ALL(c)), c.end());

    auto get = [&](int x) { return lower_bound(ALL(c), x) - c.begin() + 1; };

    V<int> f(n + 1, 0);
    int ans = 0;
    FOR(i, 1, n) {
        int t = A.query(get(num[i]) - 1) + 1;
        f[i] = t;
        ans = max(ans, f[i]);
        A.add(get(num[i]), f[i]);
    }
    cout << ans << endl;
    FOR(i, 1, n) cout << f[i] << " ";
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