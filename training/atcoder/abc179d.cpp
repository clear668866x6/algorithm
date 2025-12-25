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

constexpr int mod = 998244353;

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
    int n, k;
    cin >> n >> k;
    V<array<int, 2>> w(k + 1);
    FOR(i, 1, k) cin >> w[i][0] >> w[i][1];

    V<int> f(n + 1, 0);

    f[1] = 1;
    A.add(1, 1);

    FOR(i, 1, n) {
        int tot = 0;
        FOR(j, 1, k) {
            if (i - w[j][0] <= 0) continue;
            int L = max<int>(1, i - w[j][1]), R = max<int>(1, i - w[j][0]);
            if (L > R) continue;
            tot += (A.query(R) - A.query(L - 1));
            if (tot < 0) tot += mod;
            tot %= mod;
        }
        f[i] += tot;
        A.add(i, tot);
    }

    cout << f[n];
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