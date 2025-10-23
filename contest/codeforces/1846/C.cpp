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

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    V<V<int>> w(n);

    struct E {
        int a, b, c;
        bool operator<(const E& t) const {
            if (a == t.a) {
                if (b == t.b)
                    return c < t.c;
                return b < t.b;
            }
            return a > t.a;
        }
    };
    V<E> ans;

    FOR(i, 0, n - 1) {
        w[i].resize(m);
        FOR(j, 0, m - 1) { cin >> w[i][j]; }
        sort(ALL(w[i]));
        int pre = 0, cnt = 0, p = 0;
        FOR(j, 0, m - 1) {
            if (pre + w[i][j] <= h) {
                pre += w[i][j];
                p += pre;
                cnt++;
            } else {
                break;
            }
        }
        ans.push_back({cnt, p, i + 1});
    }

    sort(ALL(ans));

    FOR(i, 0, n - 1) {
        if (ans[i].c == 1) {
            cout << i + 1 << endl;
            RE;
        }
    }
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
