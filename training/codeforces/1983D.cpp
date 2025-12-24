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
    V<int> a(n + 1, 0), b(n + 1, 0);
    map<int, int> mp1, mp2;
    V<int> c1, c2;
    FOR(i, 1, n) cin >> a[i], mp1[a[i]]++, c1.eb(a[i]);
    FOR(i, 1, n) cin >> b[i], mp2[b[i]]++, c2.eb(b[i]);

    if (mp1 != mp2) {
        NO;
        RE;
    }

    sort(ALL(c1)), sort(ALL(c2));

    auto get1 = [&](int x) { return lower_bound(ALL(c1), x) - c1.begin() + 1; };
    auto get2 = [&](int x) { return lower_bound(ALL(c2), x) - c2.begin() + 1; };

    int ans1 = 0, ans2 = 0;

    FOR(i, 1, n) {
        ans1 += (i - 1 - A.query(get1(a[i])));
        A.add(get1(a[i]), 1);
    }

    FOR(i, 1, n) A.add(get1(a[i]), -1);

    FOR(i, 1, n) {
        ans2 += (i - 1 - A.query(get2(b[i])));
        A.add(get2(b[i]), 1);
    }
    FOR(i, 1, n) A.add(get2(b[i]), -1);

    if (!((ans1 + ans2) & 1)) {
        YES;
    } else {
        NO;
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
