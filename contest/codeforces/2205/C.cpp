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
    V<V<int>> w(n + 1), g(n + 1);

    map<int, V<int>> mp;
    V<array<int, 3>> fs(n);

    FOR(i, 1, n) {
        int l;
        cin >> l;
        w[i].resize(l, 0);
        FOR(j, 0, l - 1) {
            cin >> w[i][j];
        }
        reverse(ALL(w[i]));
        mp[w[i][0]].eb(i);
        fs[i - 1] = {w[i][0], i, 0};
    }
    g = w;

    V<int> ans;
    V<int> vis(n + 1, 0);
    set<int> s3;

    FOR(r, 1, n) {
        sort(ALL(fs));
        int t = fs[0][0];
        V<int> pt(n + 1, 0);

        FOR(i, 0, n - 1) {
            pt[fs[i][1]] = i;
        }
        set<pair<V<int>, int>> s;
        for (auto v : mp[t]) {
            if (!vis[v]) {
                s.insert({w[v], v});
            }
        }

        if (s.empty()) {
            break;
        }

        V<int> p = (*s.begin()).fi;
        int id = (*s.begin()).se;
        FOR(i, 0, sz(p) - 1) {
            ans.eb(p[i]);
            s3.insert(p[i]);
        }
        vis[id] = 1;
        fs[pt[id]] = {(int)1e6 + 1, id};

        FOR(i, 1, n) {
            if (!vis[i] && !w[i].empty()) {
                int idx = -1;
                FOR(j, 0, sz(w[i]) - 1) {
                    if (!s3.count(w[i][j])) {
                        fs[pt[i]] = {w[i][j], i};
                        idx = j;
                        mp[w[i][j]].eb(i);
                        break;
                    }
                }
                if (idx != -1) {
                    reverse(ALL(w[i]));
                    while (idx--) {
                        w[i].pop_back();
                    }
                    reverse(ALL(w[i]));
                }
            }
        }
    }

    set<int> s2;

    V<int> res;
    FOR(i, 0, sz(ans) - 1) {
        if (!s2.count(ans[i])) {
            res.eb(ans[i]);
            s2.insert(ans[i]);
        }
    }

    for (auto x : res) cout << x << ' ';
    cout << endl;
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
