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
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    map<int, set<int>> mp, mp2;
    set<PII> p;

    FOR(i, 1, n) {
        int a, b;
        cin >> a >> b;
        mp[a].insert(b);
        mp2[b].insert(a);
    }

    function<PII(char)> get = [&](char x) {
        if (x == 'U')
            return PII{0, 1};
        if (x == 'D')
            return PII{0, -1};
        if (x == 'L')
            return PII{-1, 0};
        return PII{1, 0};
    };

    FOR(i, 1, m) {
        char c;
        int x;
        cin >> c >> x;
        auto [da, db] = get(c);
        int a = sx + da * x, b = sy + db * x;

        if (sx == a) {
            if (!mp[a].sz) {
                sx = a, sy = b;
                continue;
            }
            auto l = mp[a].lower_bound(min(b, sy));
            auto r = mp[a].upper_bound(max(b, sy));
            V<int> tmp;
            for (auto it = l; it != r; it++)
                tmp.pb(*it);
            for (auto t : tmp) {
                p.insert({a, t});
                mp[a].erase(t);
                mp2[t].erase(a);
            }

        } else {
            if (!mp2[b].sz) {
                sx = a, sy = b;
                continue;
            }
            auto l = mp2[b].lower_bound(min(a, sx));
            auto r = mp2[b].upper_bound(max(a, sx));
            V<int> tmp;
            for (auto it = l; it != r; it++)
                tmp.pb(*it);
            for (auto t : tmp) {
                p.insert({t, b});
                mp2[b].erase(t);
                mp[t].erase(b);
            }
        }
        sx = a, sy = b;
    }

    cout << sx << ' ' << sy << ' ' << p.sz;
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