#include <bits/stdc++.h>
#include <functional>
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

void solve() {
    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;

    V<int> c1(n + 1, 0), c2(m + 1, 0);

    FOR(i, 1, d) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            c2[min(y1, y2)]++;
        } else {
            c1[min(x1, x2)]++;
        }
    }

    V<array<int, 2>> c3(n + 1, {0, 0}), c4(m + 1, {0, 0});

    FOR(i, 1, n) c3[i] = {c1[i], i};
    FOR(i, 1, m) c4[i] = {c2[i], i};

    sort(c3.begin() + 1, c3.end(), greater());
    sort(c4.begin() + 1, c4.end(), greater());

    V<int> ans1, ans2;

    FOR(i, 1, k) ans1.eb(c3[i][1]);
    FOR(i, 1, l) ans2.eb(c4[i][1]);

    sort(ALL(ans1)), sort(ALL(ans2));

    FOR(i, 1, k) cout << ans1[i - 1] << " \n"[i == k];
    FOR(i, 1, l) cout << ans2[i - 1] << " \n"[i == l];
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