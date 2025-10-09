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

struct FenWikTree {
    static constexpr int N = 2e5 + 10;

    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += tr[i];
        return ans;
    }

} A;

void solve() {
    int n;
    cin >> n;
    struct E {
        int l, r, id;
        bool operator<(const E &t) const {
            if (l == t.l) return r < t.r;
            return l < t.l;
        }
    };

    V<E> w(n);
    V<int> c;
    FOR(i, 0, n - 1) {
        cin >> w[i].l >> w[i].r;
        w[i].id = i + 1;
        c.eb(w[i].r);
    }

    sort(ALL(w));
    sort(ALL(c));
    c.erase(unique(ALL(c)), c.end());

    auto get = [&](int x) { return lower_bound(ALL(c), x) - c.begin() + 1; };

    FOR(i, 0, n - 1) {
        A.add(get(w[i].r), 1);
    }

    V<int> ans(n + 1, 0);

    FOR(i, 0, n - 1) {
        auto [l, r, id] = w[i];
        A.add(get(r), -1);
        ans[id] = A.query(get(r));
    }

    FOR(i, 1, n) cout << ans[i] << endl;
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