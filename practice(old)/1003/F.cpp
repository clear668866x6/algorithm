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
    int n;
    cin >> n;
    V<int> w(n * 2 + 1, 0);
    FOR(i, 1, n * 2) cin >> w[i];

    FOR(i, 1, n * 2) {
        if (w[i] == 2) {
            w[i] = -1;
        }
    }

    V<int> pre(n + 1, 0), suf(2 * n + 2, 0);
    map<int, int> mp;

    FOR(i, 1, n) pre[i] = pre[i - 1] + w[i];
    FORD(i, n + 1, n * 2) suf[i] = suf[i + 1] + w[i], mp[suf[i]] = i;

    struct E {
        int x, id;
        bool operator<(const E &t) const {
            if (x == t.x) return id < t.id;
            return x < t.x;
        }
    };

    set<E> s;

    FOR(i, n + 1, n * 2) s.insert({suf[i], i});
    int ans = 2 * n;
    int t = 0;

    FOR(i, 1, n) {
        t += w[i];
        if (!t) {
            ans = min(ans, 2 * n - i);
        }
    }

    t = 0;

    FORD(i, n + 1, n * 2) {
        t += w[i];
        if (!t) {
            ans = min(ans, i - 1);
        }
    }

    FORD(i, 1, n) {
        auto it = s.lower_bound({-pre[i], -1});
        if (it != s.end()) {
            auto [x, y] = *it;
            if (x == -pre[i]) {
                ans = min(ans, mp[x] - i - 1);
            }
        }
    }

    cout << ans << endl;
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
