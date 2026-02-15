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
    int H, W, n;
    cin >> H >> W >> n;

    map<int, V<int>> mp1, mp2;
    V<array<int, 3>> d(n + 1);
    FOR(i, 1, n) {
        int x, y;
        cin >> x >> y;
        d[i] = {x, y, i};
        mp1[x].eb(i);
        mp2[y].eb(i);
    }

    int curx = 1, cury = 1;
    int dh = H, dw = W;

    V<array<int, 2>> ans(n + 1);
    V<int> vis(n + 1, 0);

    FOR(setp, 1, n) {
        int idx = -1;
        bool f = 0;

        while (!mp1[dh].empty()) {
            int idx1 = mp1[dh].back();
            if (vis[idx1]) {
                mp1[dh].pop_back();
                continue;
            }
            mp1[dh].pop_back();
            idx = idx1;
            f = 1;
            break;
        }

        if (idx == -1) {
            while (!mp2[dw].empty()) {
                int idx1 = mp2[dw].back();
                if (vis[idx1]) {
                    mp2[dw].pop_back();
                    continue;
                }
                mp2[dw].pop_back();
                idx = idx1;
                f = 0;
                break;
            }
        }

        vis[idx] = 1;
        ans[idx] = {curx, cury};

        auto [h, w, idx2] = d[idx];

        if (f) {
            dw -= w;
            cury += w;
        } else {
            dh -= h;
            curx += h;
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