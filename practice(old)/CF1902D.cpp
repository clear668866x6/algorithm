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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;

    V<array<int, 2>> sum(n + 1);
    map<array<int, 2>, V<int>> mp;
    mp[{0, 0}].eb(0);

    FOR(i, 1, n) {
        sum[i] = sum[i - 1];
        if (s[i] == 'L')
            sum[i][0]--;
        else if (s[i] == 'R')
            sum[i][0]++;
        else if (s[i] == 'D')
            sum[i][1]--;
        else
            sum[i][1]++;
        mp[sum[i]].eb(i);
    }

    auto check = [&](int x, int y, int l, int r) {
        if (!mp.contains({x, y})) {
            return 0;
        }

        array<int, 2> dx = {x, y};

        auto it = lower_bound(ALL(mp[dx]), l);
        if (it == mp[dx].end()) {
            return 0;
        }

        if (*it <= r) {
            return 1;
        }
        return 0;
    };

    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;

        int x1 = sum[l - 1][0] + sum[r][0] - x;
        int y1 = sum[l - 1][1] + sum[r][1] - y;

        if (check(x, y, 0, l - 1) || check(x1, y1, l, r - 1) || check(x, y, r, n)) {
            YES;
        } else {
            NO;
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