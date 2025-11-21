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

void solve() {
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    V<int> pre(n + 1, 0);
    map<int, V<int>> mp, mp2, mp3;
    FOR(i, 1, n) pre[i] = pre[i - 1] ^ w[i], mp[pre[i]].eb(i);

    for (auto [x, y] : mp) {
        mp2[x].resize(sz(y) + 2, 0);
        mp3[x].resize(sz(y) + 2, 0);
        FORD(i, 1, sz(y)) {
            if (y[i - 1] & 1) {
                mp2[x][i] = mp2[x][i + 1] + 1;
                mp3[x][i] = mp3[x][i + 1];

            } else {
                mp2[x][i] = mp2[x][i + 1];
                mp3[x][i] = mp3[x][i + 1] + 1;
            }
        }
    }

    int ans = 0;

    FOR(i, 1, n) {
        int t = pre[i - 1];
        auto it = upper_bound(ALL(mp[t]), i - 1);
        int idx = it - mp[t].begin() + 1;
        if (it != mp[t].end()) {
            if (i & 1) {
                ans += mp3[t][idx];

            } else {
                ans += mp2[t][idx];
            }
        }
    }
    cout << ans;
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