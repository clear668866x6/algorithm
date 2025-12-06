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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];
    V<int> p(n + 1, 0), siz(n + 1, 1);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    auto uni = [&](int a, int b) {
        a = find(a), b = find(b);
        if (siz[a] < siz[b]) swap(a, b);
        if (a != b) {
            p[b] = a;
            siz[a] += siz[b];
        }
    };

    set<int> s;
    V<PII> ans;

    FORD(i, 1, n) {
        V<int> c;
        bool f = false;
        for (auto x : s) {
            if (x > w[i]) {
                uni(w[i], x);
                ans.pb({w[i], x});
                c.eb(x);
                f = 1;
            } else
                break;
        }

        if (!c.empty()) {
            for (auto j = c.begin(); (*j) != c.back(); j++) s.erase(*j);
        }
        if (!f) {
            s.insert(w[i]);
        }
    }

    int cnt = 0;

    FOR(i, 1, n) {
        if (i == p[i]) {
            cnt++;
        }
    }

    if (cnt == 1) {
        Yes;
        for (auto [x, y] : ans) cout << x << ' ' << y << endl;
    } else {
        No;
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
