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
    string s;
    cin >> n >> s;
    s = ' ' + s;
    map<char, int> mp;
    for (auto x : s) mp[x]++;

    if (!mp['1']) {
        YES;
        FORD(i, 1, n) cout << i << " \n"[i == 1];
    } else {

        V<int> p;
        if (s[1] != '1') {
            p.eb(0);
        }

        FOR(i, 1, n) {
            if (s[i] == '1') {
                p.eb(i);
            }
        }

        if (s[n] != '1') {
            p.eb(n + 1);
        }

        FOR(i, 1, sz(p) - 1) {
            if (p[i] - p[i - 1] - 1 == 1) {
                NO;
                RE;
            }
        }

        YES;

        V<int> ans(n + 1, 0);
        iota(ALL(ans), 0ll);

        FOR(i, 1, sz(p) - 1) {
            int l = p[i - 1], r = p[i];
            if (!l) l++;
            if (r == n + 1) r--;
            if (s[l] == '1') l++;
            if (s[r] == '1') r--;
            reverse(ans.begin() + l, ans.begin() + r + 1);
        }
        FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
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
