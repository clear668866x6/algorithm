#include <bits/stdc++.h>
#include <cerrno>
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
    int H, W, n;
    cin >> H >> W >> n;

    struct E {
        int h, w, idx;
        bool operator<(const E &t) const {
            if (h == t.h) return w > t.w;
            return h > t.h;
        }
    };
    V<E> dot(n);

    FOR(i, 1, n) {
        int x, y;
        cin >> x >> y;
        dot[i - 1] = {x, y, i};
    }

    sort(ALL(dot));

    set<array<int, 2>> s;
    map<int, int> mp1, mp2;
    mp1[1]++, mp2[1]++;
    s.insert({1, 1});
    V<array<int, 2>> ans(n + 1);

    FOR(i, 0, n - 1) {
        auto [h, w, idx] = dot[i];
        for (auto [x, y] : s) {
            int nx = (x + h) - 1, ny = (y + w) - 1;
            if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
            ans[idx] = {x, y};
            s.erase(s.find({x, y}));
            mp1[x]--, mp2[y]--;
            if (nx + 1 <= H && !mp1[nx + 1]) {
                mp1[nx + 1]++;
                s.insert({nx + 1, y});
            }

            if (ny + 1 <= W && !mp2[ny + 1]) {
                mp2[ny + 1]++;
                s.insert({x, ny + 1});
            }
            break;
        }
    }

    FOR(i, 1, n) cout << ans[i][0] << ' ' << ans[i][1] << endl;
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