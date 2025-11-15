#include <bits/stdc++.h>
#include <latch>
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

struct BITTree {
    static constexpr int N = 5e5 + 10;
    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += tr[i];
        return ans;
    }
} A, B;

void solve() {
    int n, q;
    cin >> n >> q;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i], w[i] += 2;

    FOR(i, 1, n) {
        A.add(w[i], 1);
        B.add(w[i], w[i]);
    }

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        l += 2, r += 2;
        if (op == 1) {
            A.add(w[l - 2], -1);
            B.add(w[l - 2], -w[l - 2]);
            w[l - 2] = r;
            A.add(r, 1);
            B.add(r, r);
        } else {
            bool f = false;
            if (l > r) swap(l, r), f = 1;
            int p2 = n - A.query(r);
            int mid = A.query(r) - A.query(l - 1);
            int p1 = n - p2 - mid;
            int ans = B.query(r) - B.query(l - 1);
            if (!f) {
                ans += p2 * r + p1 * l;

            } else {
                ans = n * r;
            }
            ans -= 2 * n;
            cout << ans << endl;
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