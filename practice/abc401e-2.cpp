#include <bits/stdc++.h>
#include <functional>
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
    int n, m;
    cin >> n >> m;

    V<V<int>> g(n + 1);

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    V<int> p(n + 1, 0);

    FOR(i, 1, n) p[i] = i;

    function<int(int)> find = [&](int x) {
        if (x != p[x])
            return p[x] = find(p[x]);
        return p[x];
    };

    function<void(int, int)> uni = [&](int a, int b) {
        if (a > b)
            swap(a, b);
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
        }
    };

    int lst = 1;

    set<int> s;

    for (auto j : g[1]) {
        s.insert(j);
    }

    cout << s.sz << endl;

    FOR(k, 2, n) {
        for (auto j : g[k]) {
            if (j < k) {
                uni(j, k);
                continue;
            }
            s.insert(j);
        }
        if (s.count(k - 1)) {
            s.erase(k - 1);
        }
        if (s.count(k)) {
            s.erase(k);
        }
        int cnt = 0;
        bool f = false;
        FOR(j, lst + 1, k) {
            // cout << j << ' ' << lst << endl;
            if (find(j) != find(lst)) {
                // cout << find(lst) << endl;
                // cout << lst << ' ' << j << endl;
                f = 1;
                cout << -1 << endl;
                break;
            } else {
                cnt++;
            }
        }
        if (!f) {
            cout << s.sz << endl;
        }
        // cout << lst << '-' << cnt << endl;
        lst += cnt;
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