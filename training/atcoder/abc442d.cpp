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

// 当时不知道怎么回事，为什么没有想到前缀和直接搞，我一直在想着那个A[i]为什么是10^4次方，然后想了很奇怪的方法。
// 做不出来，后面看了一眼解题才知道，原来前缀和在一定范围内是没有变化的。

void solve() {
    int n, q;
    cin >> n >> q;
    V<int> w(n + 1, 0), s(n + 1, 0);
    FOR(i, 1, n) cin >> w[i], s[i] = s[i - 1] + w[i];

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            swap(w[x], w[x + 1]);
            s[x] = s[x - 1] + w[x];
        } else {
            int l, r;
            cin >> l >> r;
            cout << s[r] - s[l - 1] << endl;
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