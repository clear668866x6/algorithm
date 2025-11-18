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

struct BiTTree {
    static constexpr int N = 1e6 + 10;
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
    int n, q;
    cin >> n >> q;
    V<int> fac(25, 1);
    FOR(i, 1, 20) fac[i] = fac[i - 1] * i;

    while (q--) {
        char op;
        cin >> op;
        if (op == 'P') {
            int x;
            cin >> x;
            x--;

            V<int> p(n, 0);
            iota(ALL(p), 1ll);
            FOR(i, 1, n) {
                int t = x / (fac[n - i]);
                x %= fac[n - i];
                cout << p[t] << ' ';
                p.erase(p.begin() + t);
            }
            cout << endl;
        } else {
            int ans = 0;
            FOR(i, 1, n) A.add(i, 1);
            FOR(i, 1, n) {
                int x;
                cin >> x;
                ans += (fac[n - i] * (A.query(x) - 1));
                A.add(x, -1);
            }
            cout << ans + 1 << endl;
        }
    }
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