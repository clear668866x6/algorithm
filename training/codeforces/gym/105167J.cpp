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
// https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2025/10/1002/solution/cf105167j.md

struct BIT {
    static constexpr int N = 4e5 + 10;
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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    V<int> t1(n + 1, 0), t2(n + 1, 0);
    int ans1 = n * n / 2 - 1, ans2 = 1e18;
    int l = 3, r = 2;
    FOR(i, 1, n) {
        if (w[i] == n / 2)
            t1[i] = 1;
        else if (w[i] == n / 2 + 1)
            t1[i] = n;
        else if (w[i] < n / 2)
            t1[i] = l, l += 2;
        else
            t1[i] = r, r += 2;
    }

    int p = 0;
    FOR(i, 1, n) {
        p += (i - 1 - A.query(t1[i]));
        A.add(t1[i], 1);
    }

    FOR(i, 1, n) {
        A.add(t1[i], -1);
    }

    ans2 = min(ans2, p);

    l = 2, r = 3;
    FOR(i, 1, n) {
        if (w[i] == n / 2)
            t2[i] = n;
        else if (w[i] == n / 2 + 1) {
            t2[i] = 1;
        } else if (w[i] < n / 2) {
            t2[i] = l, l += 2;
        } else {
            t2[i] = r, r += 2;
        }
    }

    p = 0;

    FOR(i, 1, n) {
        p += (i - 1 - A.query(t2[i]));
        A.add(t2[i], 1);
    }

    FOR(i, 1, n) A.add(t2[i], -1);

    ans2 = min(ans2, p);

    cout << ans1 << ' ' << ans2 << endl;
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
