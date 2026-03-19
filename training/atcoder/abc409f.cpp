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
    int n, q;
    cin >> n >> q;

    V<int> x(n + 1, 0), y(n + 1, 0);
    FOR(i, 1, n) cin >> x[i] >> y[i];

    V<int> p(n * 3 + 1, 0);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    priority_queue<array<int, 3>, V<array<int, 3>>, greater<array<int, 3>>> pq;

    auto dist = [&](int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); };

    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            int d = dist(x[i], y[i], x[j], y[j]);
            pq.push({d, i, j});
        }
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            FOR(i, 1, n) {
                int d = dist(x[i], y[i], a, b);
                pq.push({d, i, n + 1});
            }
            x.eb(a), y.eb(b);
            n++;

        } else if (op == 2) {
            int t = -1;
            while (!pq.empty()) {
                auto [di, s, d] = pq.top();
                if (t != -1 && t != di) {
                    break;
                }
                pq.pop();
                int a = find(s), b = find(d);
                if (a == b) continue;
                p[a] = b;
                t = di;
            }
            cout << t << endl;
        } else {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b)) {
                Yes;
            } else {
                No;
            }
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