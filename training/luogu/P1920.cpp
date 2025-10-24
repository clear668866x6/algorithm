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

struct BIT {
    static constexpr int N = 2e6 + 10;
    int tr[N];

    BIT() {
        memset(tr, 0, sizeof tr);
    }

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] = max(tr[i], c);
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans = max(ans, tr[i]);
        return ans;
    }

} A, B;

void solve() {
    int x;
    V<int> a, b, c;
    while (cin >> x) {
        a.eb(x);
        b.eb(-x);
        c.eb(x);
    }

    int n = sz(a);

    sort(ALL(b));
    sort(ALL(c));
    b.erase(unique(ALL(b)), b.end());
    c.erase(unique(ALL(c)), c.end());
    auto get1 = [&](int x) { return lower_bound(ALL(b), x) - b.begin() + 1; };
    auto get2 = [&](int x) { return lower_bound(ALL(c), x) - c.begin() + 1; };

    int ans1 = 0, ans2 = 0;
    FOR(i, 0, n - 1) a[i] = -a[i];

    FOR(i, 0, n - 1) {
        int t = A.query(get1(a[i])) + 1;
        A.add(get1(a[i]), t);
        ans1 = max(ans1, t);
    }
    FOR(i, 0, n - 1) a[i] = -a[i];

    FOR(i, 0, n - 1) {
        int t = B.query(get2(a[i]) - 1) + 1;
        B.add(get2(a[i]), t);
        ans2 = max(ans2, t);
    }
    cout << ans1 << endl << ans2;
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