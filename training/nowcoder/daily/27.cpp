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

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    V<array<int, 3>> w(m + 1, {0, 0, 0});
    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        w[i] = {c, a, b};
    }

    sort(ALL(w));

    int l = -1, r = 1e9;

    auto check = [&](int val) {
        V<int> p(n + 1, 0);
        function<int(int)> find = [&](int x) {
            if (x != p[x]) p[x] = find(p[x]);
            return p[x];
        };
        iota(ALL(p), 0ll);
        V<int> tmp;

        FOR(i, 1, m) {
            auto [c, x, y] = w[i];
            x = find(x), y = find(y);
            if (x != y) {
                p[x] = y;
                if (c > val) {
                    tmp.eb(c);
                }
            }
        }

        sort(RALL(tmp));

        int tot = 0;
        FOR(i, 0, sz(tmp) - 1) {
            tot += (i + 1) * tmp[i];
        }

        return tot <= c;
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r;
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