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

struct E {
    static constexpr int N = 2e5 + 10;

    V<int> div[N];

    void init() {
        int x = 2e5;
        FOR(i, 1, x) {
            FOR2(j, i, x, i) {
                div[j].eb(i);
            }
        }
    }
} A;

void solve() {
    int n;
    cin >> n;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int cur = 0;
    map<int, int> cnt;

    int ans = 0;

    FOR(i, 1, n) {
        for (auto x : A.div[w[i]]) {
            cnt[x]++;
            if (cnt[x] != i) {
                ans = max(ans, cnt[x]);
            }
        }
        if (cur != gcd(cur, w[i])) {
            ans = max(ans, cnt[cur]);
        }
        cur = gcd(cur, w[i]);
        cout << ans << " \n"[i == n];
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    A.init();
    while (Task--) {
        solve();
    }

    return 0;
}
