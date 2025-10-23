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
    static constexpr int N = 1e5 + 10;

    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += tr[i];
        return ans;
    }
};

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    s = ' ' + s;
    int q;
    cin >> q;
    V<FenwikTree> f(30);
    FOR(i, 1, n) {
        f[s[i] - 'a'].add(i, 1);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            f[s[pos] - 'a'].add(pos, -1);
            f[c - 'a'].add(pos, 1);
            s[pos] = c;
        } else {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            FOR(i, 'a', 'z') {
                ans += ((f[i - 'a'].query(r) - f[i - 'a'].query(l - 1)) > 0);
            }
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