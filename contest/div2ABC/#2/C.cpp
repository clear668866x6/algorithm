#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve() {
    int n;
    cin >> n;

    V<int> w(n);
    for (auto& x : w)
        cin >> x;

    V<PII> seg(n);
    for (auto& [a, b] : seg)
        cin >> a >> b;

    int l = 0, r = 0;
    V<int> L(n), R(n);

    FOR(i, 0, n - 1) {
        if (w[i] == 1)
            l++, r++;
        else if (w[i] == -1)
            r++;
        l = max(l, seg[i].fi), r = min(r, seg[i].se);
        if (l > r) {
            cout << -1 << endl;
            RE;
        }
        L[i] = l, R[i] = r;
    }

    int t = l;

    FORD(i, 0, n - 1) {
        if (i) {
            if (w[i] == -1) {
                if (t >= L[i - 1] && t <= R[i - 1])
                    w[i] = 0;
                else
                    w[i] = 1, t--;
            } else if (w[i] == 1) {
                t--;
            }
        } else {
            if (w[i] == -1) {
                if (t > 0)
                    w[i] = 1, t--;
                else
                    w[i] = 0;
            }
        }
    }

    FOR(i, 0, n - 1) cout << w[i] << " \n"[i == n - 1];
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