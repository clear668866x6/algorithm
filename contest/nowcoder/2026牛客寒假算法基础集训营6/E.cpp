#include <algorithm>
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

struct DSU {
    static const int N = 5e5 + 10;
    int ans;
    int p[N], siz[N];
    int d;
    void init(int _d) {
        FOR(i, 1, N - 10) p[i] = i;
        d = _d;
        ans = 0;
    }

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    void add(int x) {
        siz[x] = 1;
        if (siz[x] >= d) ans++;
    }

    void uni(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) RE;
        if (siz[a] >= d) ans--;
        if (siz[b] >= d) ans--;
        p[b] = a;
        siz[a] += siz[b];
        if (siz[a] >= d) ans++;
    }

    int get() {
        return ans;
    }

} A;

void solve() {
    int n, m, x, d;
    cin >> n >> m >> x >> d;

    A.init(d);

    V<int> h(n + 1, 0);
    V<V<int>> g(n + 1);

    map<int, V<int>> mp;
    FOR(i, 1, n) cin >> h[i], mp[h[i]].eb(i);
    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    sort(ALL(h));
    h.erase(unique(ALL(h)), h.end());
    int mx = *max_element(ALL(h));
    multiset<int> s;
    map<int, int> ans;
    ans[mx] = 0;
    s.insert(mx);
    set<int> dot;

    FORD(id, 1, sz(h) - 1) {
        set<int> p;
        for (auto x : mp[h[id]]) {
            dot.insert(x);
            p.insert(x);
            A.add(x);
        }
        for (auto x : p) {
            for (auto v : g[x]) {
                if (dot.count(v)) {
                    int a = x, b = v;
                    A.uni(a, b);
                }
            }
        }
        int cnt = A.get();
        s.insert(h[id - 1]);
        ans[h[id - 1]] = cnt;
    }

    while (x--) {
        int val;
        cin >> val;
        auto it = prev(s.upper_bound(val));
        cout << ans[*it] << endl;
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